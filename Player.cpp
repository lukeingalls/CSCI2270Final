#include "Player.hpp"
#include <climits>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

/*
Nonclass functions that are still useful.
*/

bool is_num(std::string s) {
	for (std::string::iterator i = s.begin(); i != s.end(); i++) if (*i != '1' && *i != '2' && *i != '3' && *i != '4' && *i != '5' && *i != '6' && *i != '7' && *i != '8' && *i != '9' && *i != '0' && *i != '.') return 0;
		return 1;
}

std::string splitter(std::string &input, char delim = ',') {
	std::string temp = "";
	if (input.find(delim) != std::string::npos) {
		temp = input.substr(0, input.find(delim));
		input.erase(0, 1 + input.find(delim));
	} else {
		temp = input;
		input = "";
	}
	return temp;
}

/*
These are the functions for the hashtable. This will store all the players for a particular year.
Players are indexed by name and when searching will be matched player name and school (to prevent
players with the same name from being seen as identical)
*/

unsigned int table::hashFunction(std::string p) {
	unsigned int hashValue = 5381;
	int length = p.length();
	for (int i=0;i<length;i++) {
		hashValue = ((hashValue << 5) + hashValue) + p[i];
	}
	hashValue %= table_size;
	return hashValue;
}
table::table(int n) : table_size(n) {
	htable = new player*[table_size];
	for (int i = 0; i < table_size; i++) {
		htable[i] = 0;
	}
}
table::~table() {
	delete [] htable;
}
void table::addPlayer(player *p) {
	unsigned int tindex = hashFunction(p->name);
	if (!htable[tindex]) {
		htable[tindex] = p;
	} else {
		p->next = htable[tindex];
		htable[tindex] = p;
	}
}
player *table::searchPlayer(std::string name, std::string team) {
	unsigned int index = hashFunction(name);
	player *itr = htable[index];
	while (itr) {
		if (itr->name == name && itr->team == team) {
			break;
		} else {
			itr = itr->next;
		}
	}
	return itr;
}

/*
Player class function definitions.
*/

player::player(std::string name, std::string team, std::string position, std::string height, short int years, short int weight, short int games_played, std::vector<int> stats) {
	this->name = name;
	this->team = team;
	this->pos = position;
	this->height = 12 * stoi(height.substr(0, height.find("'"))) + stoi(height.substr(2, height.length() - 3));
	this->years = years;
	this->weight = weight;
	this->games_played = games_played;
	for (int i = 0; i < 8; i++) {
		game_avg[i] = (float)stats[i]/(float)games_played;
	}

}
player::player() {}

/*
Below this line is the definition of the maxheap
*/

maxheap::maxheap(int heapSize, int index) {
	heap = new player*[heapSize];
	currSize = 0;
	this->maxSize = heapSize;
	type_index = index;
}
maxheap::~maxheap() {
	delete [] heap;
}
void maxheap::push(player *value) {
	if (!full()) {
		heap[currSize] = value;
		repair_up(currSize++);
	} else {
		std::cout << "Heap full: Big Problem" << std::endl;
	}
}
player *maxheap::pop() {
	player *temp = heap[0];
	if (!empty()) {
		heap[0] = heap[--currSize];
		repair_down(0);
	} else std::cout << "There's literally nothing to remove" << std::endl;
	return temp;
}
player *maxheap::peek() {
	return heap[0];
}
bool maxheap::full() {
	if (currSize == maxSize) return 1;
	return 0;
}
bool maxheap::empty() {
	if (currSize == 0) return 1;
	return 0;
}
int maxheap::parent(int nodeIndex) {return (nodeIndex-1)/2;}
int maxheap::left(int nodeIndex){return (2*nodeIndex + 1);}
int maxheap::right(int nodeIndex){return (2*nodeIndex + 2);}
void maxheap::repair_up(int nodeIndex) { // Currently a max heap
	if (nodeIndex == 0) return;
	int p = parent(nodeIndex);
	if (heap[nodeIndex]->game_avg[type_index] > heap[p]->game_avg[type_index]) {
		std::swap(heap[nodeIndex], heap[p]);
		repair_up(p);
	}
}
void maxheap::repair_down(int nodeIndex) {
	int l = left(nodeIndex);
	int r = right(nodeIndex);
	int compar = nodeIndex;
	if (l < currSize) {
		if (heap[l]->game_avg[type_index] > heap[nodeIndex]->game_avg[type_index]) {
			compar = l;
		}
		if (r < currSize) {
			if (heap[r]->game_avg[type_index] > heap[compar]->game_avg[type_index]) {
				compar = r;
			}
		}
	} else return;
	if (compar != nodeIndex) {
		std::swap(heap[compar], heap[nodeIndex]);
		repair_down(compar);
	}
}

//
//
//
// Percentile code below ⬇
//
//
//

bool percentile_scoring::empty() {
	return !players;
}

percentile_scoring::percentile_scoring() : year(13, table(500)) {
	run = 0;
	for (int i = 0; i < weights.size(); i++) {
		weights[i] = 1;
	} 
	start_year = 2007;
	players = 0;
}

void percentile_scoring::readinfile(std::string file) {
	std::ifstream roster;
	roster.open(file);
	std::string bio[4];
	std::string line;
	if (roster.is_open()) {
		while (!roster.eof()) {
			std::vector<std::string> lines;
			getline(roster, line);
			for (int i = 0; !line.empty(); i++) {
				bio[i] = splitter(line);
			}
			std::cout << bio[0] << std::endl;
			while(1) {
				getline(roster, line);
				if (line.find("--") == std::string::npos) {
					if (line.empty()) break;
					lines.push_back(line);
				}
			}
			for (int i = lines.size(); i > 0; i--) {
				std::vector<std::string> temp;
				while(!lines[i-1].empty()) {
					temp.push_back(splitter(lines[i-1])); 
				}
				if (temp.size() < 11) break;
				std::vector<int> s;
				for (int j = 3; j < temp.size(); j++) {
					s.push_back(stoi(temp[j]));
				}
				std::cout << players << std::endl;
				player *p = new player(bio[0], temp[1], bio[1], bio[2], i, stoi(bio[3]), stoi(temp[2]), s);
				year[stoi(temp[0]) - start_year].addPlayer(p);
			}
			this->players++;
		}
	}
	roster.close();
	run = 0;
	std::cout << "There are now " << players << " players in the program" << std::endl;
}


















// int percentile_scoring::find_ith_equivalent(player **p, int remaining, char val) {
// 	switch(val) {
// 		case 'p': {
// 				float start_val = (*p)->ppg;
// 				for (int i = 0; i < remaining; i++) if ((*p + i)->ppg < start_val) return i;
// 			}
// 			break;
// 		case 'r': {
// 				float start_val = (*p)->rpg;
// 				for (int i = 0; i < remaining; i++) if ((*p + i)->rpg < start_val) return i;
// 			}
// 			break;
// 		case 'a': {
// 				float start_val = (*p)->apg;
// 				for (int i = 0; i < remaining; i++) if ((*p + i)->apg < start_val) return i;
// 			}
// 			break;
// 		case 'b': {
// 				float start_val = (*p)->bpg;
// 				for (int i = 0; i < remaining; i++) if ((*p + i)->bpg < start_val) return i;
// 			}
// 			break;
// 		case 's': {
// 				float start_val = (*p)->spg;
// 				for (int i = 0; i < remaining; i++) if ((*p + i)->spg < start_val) return i;
// 			}
// 			break;
// 	}
// 	return remaining;
// }

// void percentile_scoring::percentile_score_players() {
// 	if (!run) sort_basic_arrays();
// 	for (int i = 0; i < players - 1; i++) {
// 		if (ppg[i]->ppg > ppg[i + 1]->ppg) {
// 			ppg[i]->ppg_percentile = (float)(players - (i + 1))/(float)players;
// 		} else {
// 			int j = find_ith_equivalent(ppg + i, (players - 1) - i, 'p');
// 			for (int k  = 0; k < j; k++) ppg[i + k]->ppg_percentile = (float)(players - (i + j + 1))/(float)players;
// 			i+=j;
// 		}
// 	}
// 	for (int i = 0; i < players - 1; i++) {
// 		if (rpg[i]->rpg > rpg[i + 1]->rpg) {
// 			rpg[i]->rpg_percentile = (float)(players - (i + 1))/(float)players;
// 		} else {
// 			int j = find_ith_equivalent(rpg + i, (players - 1) - i, 'r');
// 			for (int k  = 0; k < j; k++) rpg[i + k]->rpg_percentile = (float)(players - (i + j + 1))/(float)players;
// 			i+=j;
// 		}
// 	}
// 	for (int i = 0; i < players - 1; i++) {
// 		if (apg[i]->apg > apg[i + 1]->apg) {
// 			apg[i]->apg_percentile = (float)(players - (i + 1))/(float)players;
// 		} else {
// 			int j = find_ith_equivalent(apg + i, (players - 1) - i, 'a');
// 			for (int k  = 0; k < j; k++) apg[i + k]->apg_percentile = (float)(players - (i + j + 1))/(float)players;
// 			i+=j;
// 		}
// 	}
// 	for (int i = 0; i < players - 1; i++) {
// 		if (spg[i]->spg > spg[i + 1]->spg) {
// 			spg[i]->spg_percentile = (float)(players - (i + 1))/(float)players;
// 		} else {
// 			int j = find_ith_equivalent(spg + i, (players - 1) - i, 's');
// 			for (int k  = 0; k < j; k++) spg[i + k]->spg_percentile = (float)(players - (i + j + 1))/(float)players;
// 			i+=j;
// 		}
// 	}
// 	for (int i = 0; i < players - 1; i++) {
// 		if (bpg[i]->bpg > bpg[i + 1]->bpg) {
// 			bpg[i]->bpg_percentile = (float)(players - (i + 1))/(float)players;
// 		} else {
// 			int j = find_ith_equivalent(bpg + i, (players - 1) - i, 'b');
// 			for (int k  = 0; k < j; k++) bpg[i + k]->bpg_percentile = (float)(players - (i + j + 1))/(float)players;
// 			i+=j;
// 		}
// 	}
// }

// void percentile_scoring::rank_top() {
// 	percentile_score_players();
// }


// team *percentile_scoring::teamexists(std::string t) {
// 	for (int i = 0; i < teams.size(); i++) if (teams[i].name == t) return &teams[i];
// 	return 0;
// }

// void percentile_scoring::loadPlayer() {
// 	std::string inputs[8];
// 	team *t;
// 	while (1) {
// 		std::cout << "The teams currently in the system are:" << std::endl;
// 		for (int i = 0; i < teams.size(); i++) std::cout << teams[i].name << std::endl;
// 		std::cout << "What team does he play for?" << std::endl;
// 		getline(std::cin, inputs[0]);
// 		for (int i = 0; i < teams.size(); i++) {
// 			if (teams[i].name == inputs[0]) {
// 				t = &teams[i];
// 				break;
// 			}
// 		}
// 		std::cout << "Would you like to add this team? YES input 1. NO input 2." << std::endl;
// 		getline(std::cin, inputs[1]);
// 		if (inputs[1][0] == '1') {
// 			teams.push_back(inputs[0]);
// 			t = &teams[teams.size() - 1];
// 			break;
// 		}
// 	}
// 	std::cout << "Player name:" << std::endl;
// 	getline(std::cin, inputs[1]);
// 	while(1) {
// 		std::cout << "PPG? ";
// 		getline(std::cin, inputs[2]);
// 		std::cout << std::endl;
// 		if (is_num(inputs[2]))
// 			break;
// 		else
// 			std::cout << "Input a float..." << std::endl;
// 	}
// 	while(1) {
// 		std::cout << "RPG? ";
// 		getline(std::cin, inputs[3]);
// 		std::cout << std::endl;
// 		if (is_num(inputs[3]))
// 			break;
// 		else
// 			std::cout << "Input a float..." << std::endl;
// 	}
// 	while(1) {
// 		std::cout << "APG? ";
// 		getline(std::cin, inputs[4]);
// 		std::cout << std::endl;
// 		if (is_num(inputs[4]))
// 			break;
// 		else
// 			std::cout << "Input a float..." << std::endl;
// 	}
// 	while(1) {
// 		std::cout << "BPG? ";
// 		getline(std::cin, inputs[5]);
// 		std::cout << std::endl;
// 		if (is_num(inputs[5]))
// 			break;
// 		else
// 			std::cout << "Input a float..." << std::endl;
// 	}
// 	while(1) {
// 		std::cout << "SPG? ";
// 		getline(std::cin, inputs[6]);
// 		std::cout << std::endl;
// 		if (is_num(inputs[6]))
// 			break;
// 		else
// 			std::cout << "Input a float..." << std::endl;
// 	}
// 	while (1) {
// 		std::cout << "POS? ";
// 		getline(std::cin, inputs[7]);
// 		std::cout << std::endl;
// 		if (inputs[7][0] == '1' || inputs[7][0] == '2' || inputs[7][0] == '3' || inputs[7][0] == '4' || inputs[7][0] == '5')
// 			break;
// 		else
// 			std::cout << "Input an int..." << std::endl;
// 	}
// 	player p(inputs[1], stoi(inputs[7]), stof(inputs[2]), stof(inputs[3]), stof(inputs[4]), stof(inputs[5]), stof(inputs[6]));
// 	t->roster.push_back(p);
// 	players++;
// 	run = 0;
// }


// void percentile_scoring::check_arrays() {
// 	while(size < players) {
// 		array_double(&ppg, size);
// 		array_double(&rpg, size);
// 		array_double(&apg, size);
// 		array_double(&bpg, size);
// 		array_double(&spg, size);
// 		size = array_double(&cumulative, size);
// 	}
// }

// void percentile_scoring::sort_basic_arrays() {

// 	check_arrays();
// 	run = 1;
// 	maxheap points(players, 'p');
// 	maxheap rebounds(players, 'r');
// 	maxheap assists(players, 'a');
// 	maxheap steals(players, 's');
// 	maxheap blocks(players, 'b');
// 	for (int j = 0; j < teams.size(); j++) {
// 		for (int i = 0; i < teams[j].roster.size(); i++) {
// 			points.push(&teams[j].roster[i]);
// 			rebounds.push(&teams[j].roster[i]);
// 			assists.push(&teams[j].roster[i]);
// 			steals.push(&teams[j].roster[i]);
// 			blocks.push(&teams[j].roster[i]);
// 		}
// 	}

// 	for (int i = 0; i < players; i++) {
// 		ppg[i] = points.pop();
// 		rpg[i] = rebounds.pop();
// 		apg[i] = assists.pop();
// 		bpg[i] = blocks.pop();
// 		spg[i] = steals.pop();
// 	}
// }

// void percentile_scoring::print_top_n_points(int n) {
// 	std::cout << "Here are the " << n << " best scorers: " << std::endl;
// 	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << ppg[i]->name << ppg[i]->ppg << std::endl; 
// }

// void percentile_scoring::print_top_n_assists(int n) {
// 	std::cout << "Here are the " << n << " best assisters: " << std::endl;
// 	for(int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << apg[i]->name << apg[i]->apg << std::endl;
// }

// void percentile_scoring::print_top_n_rebounds(int n) {
// 	std::cout << "Here are the " << n << " best rebounders: " << std::endl;
// 	for(int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << rpg[i]->name << rpg[i]->rpg << std::endl;
// }

// void percentile_scoring::print_top_n_steals(int n) {
// 	std::cout << "Here are the " << n << " best sttealers: " << std::endl;
// 	for(int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << spg[i]->name << spg[i]->spg << std::endl;
// }

// void percentile_scoring::print_top_n_blocks(int n) {
// 	std::cout << "Here are the " << n << " best shot blockers: " << std::endl;
// 	for(int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << bpg[i]->name << bpg[i]->bpg << std::endl;
// }

// void percentile_scoring::print_all_players() {
// 	for (int j = 0; j < teams.size(); j++) {
// 		for (int i = 0; i < teams[j].roster.size(); i++) {
// 			std::cout << i + 1 << ": " << std::left << std::setw(30) << teams[j].roster[i].name << teams[j].roster[i].ppg << std::endl;
// 		}
// 	}
// }


