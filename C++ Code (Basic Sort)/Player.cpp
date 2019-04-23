#include "Player.hpp"
#include <climits>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

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
std::string remove_quotes(std::string s) {
	std::string temp;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 34) {
			temp += s[i];
		}
	}
	return temp;
}
void cleaner(std::string &s) {
	std::string temp;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 13 && s[i] != 10) {
			temp +=s[i];
		}
	}
	s = temp;
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
void table::addPlayer(player p) {
	unsigned int tindex = hashFunction(p.name);
	htable[tindex].push_back(p);
}
table::table() {
	table_size = 750;
}
player *table::searchPlayer(std::string name, std::string team) {
	unsigned int index = hashFunction(name);
		for(int i = 0; i < htable[index].size(); i++) {
			if (htable[index][i].name == name && htable[index][i].team == team) {
				return &htable[index][i];
		}
	}
return 0;
}
player *table::searchPlayer(std::string name) {
	unsigned int index = hashFunction(name);
			for(int i = 0; i < htable[index].size(); i++) {
				if (htable[index][i].name == name) {
					return &htable[index][i];
			}
		}
	return 0;
}
void table::printTable() {
	for(int i = 0; i < 750; i++)
		{
			for(int j = 0; j < htable[i].size(); j++)
			{
				cout<< htable[i][j].name << " ";
			}
		cout<<endl;
	}
}

/*
Player class function definitions.
*/

player::player(std::string name, std::string team, std::string position, std::string height, short int years, short int weight, float stats[]) {
	this->name = name;
	this->team = team;
	this->pos = position;
	string s = remove_quotes(height);
	string f = splitter(s, 39);
	this->height = 12*(stoi(f)) + stoi(s);
	this->years = years;
	this->weight = weight;
	this->draft_flag = 0;
	for (int i = 0; i < 9; i++) {
		game_avg[i] = stats[i];
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

percentile_scoring::percentile_scoring() {
	run = 0;
	for (int i = 0; i < sizeof(weights)/sizeof(weights[0]); i++) {
		weights[i] = 1;
	}
	start_year = 2007;
	players = 0;
}

void percentile_scoring::readinfile(std::string file)
{
	std::ifstream roster;
	roster.open(file);
	string line;
	if(roster.is_open()){
		while(!roster.eof()){
			getline(roster, line);
			cleaner(line);
			if(line.empty()) continue;
			string name = splitter(line);
			string position = splitter(line);
			string height = splitter(line);
			short int weight = stoi(splitter(line));
			string team = splitter(line);
			team = splitter(line);
			float games = stof(splitter(line));
			float minutes = stof(splitter(line))/games;
			float points = stof(splitter(line))/games;
			float rebounds = stof(splitter(line))/games;
			float assists = stof(splitter(line))/games;
			float steals = stof(splitter(line))/games;
			float blocks = stof(splitter(line))/games;
			float turnovers = stof(splitter(line))/games;
			float fouls = stof(splitter(line))/games;
			short int years = stoi(splitter(line));
			//0: games per year, 1: minutes, 2: points, 3: rebounds,
			//4: assists, 5: steals, 6: blocks, 7: turnovers
			//8: fouls, 9: years played
			float array[9] = {games, minutes, points, rebounds, assists, steals, blocks, turnovers, fouls};
			//player::player(std::string name, std::string team, std::string position, std::string height, short int years, short int weight, float stats[])
			if(!year.searchPlayer(name, team)) {
				player person(name, team, position, height, years, weight, array);
				players++;
				year.addPlayer(person);
			}
		}
	}
	std::cout << "There are now " << players << " players in the table" << std::endl;
	roster.close();
}

table percentile_scoring::rtable() {
	return year;
}

void percentile_scoring::sort_basic_arrays() {
	run = 1;
	maxheap games(players, 0);
	maxheap minutes(players, 1);
	maxheap points(players, 2);
	maxheap rebounds(players, 3);
	maxheap assists(players, 4);
	maxheap steals(players, 5);
	maxheap blocks(players, 6);
	maxheap turnovers(players, 7);
	maxheap fouls(players, 8);
	for (int j = 0; j < 750; j++) {
		for (int i = 0; i < year.htable[j].size(); i++) {
			games.push(&year.htable[j][i]);
			minutes.push(&year.htable[j][i]);
			points.push(&year.htable[j][i]);
			rebounds.push(&year.htable[j][i]);
			assists.push(&year.htable[j][i]);
			steals.push(&year.htable[j][i]);
			blocks.push(&year.htable[j][i]);
			turnovers.push(&year.htable[j][i]);
			fouls.push(&year.htable[j][i]);
		}
	}

	for (int i = 0; i < players; i++) {
		percent_scores[0].push_back(games.pop());
		percent_scores[1].push_back(minutes.pop());
		percent_scores[2].push_back(points.pop());
		percent_scores[3].push_back(rebounds.pop());
		percent_scores[4].push_back(assists.pop());
		percent_scores[5].push_back(steals.pop());
		percent_scores[6].push_back(blocks.pop());
		percent_scores[7].push_back(turnovers.pop());
		percent_scores[8].push_back(fouls.pop());
	}
}

void percentile_scoring::percentile_score_players() {
	if (!run) sort_basic_arrays();
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < players/* - 1*/; i++) {
			// if (percent_scores[j][i]->game_avg[j] > percent_scores[j][i+1]->game_avg[j]) {
				percent_scores[j][i]->relative_game_avg[j] = (float)(players - (i + 1))/(float)players;
			// } else {
				// int j = find_ith_equivalent(percent_scores[j], i, players - 1, j);
				// for (int k  = 0; k < j; k++) percent_scores[j][i]->relative_game_avg[j] = (float)(players - (i + j + 1))/(float)players;
				// i+=j;
			// }
		}
	}
}

int percentile_scoring::find_ith_equivalent(std::vector<player*> p, int start, int remaining, int series) {
	float start_val = p[start]->game_avg[series];
	for (int i = 0; i < p.size(); i++) std::cout << p[i]->name << std::endl;
	for (int i = start; i < remaining; i++) {
		if (p[i]->game_avg[series] < start_val) {
			return i;
		}
	}
	return remaining;
}

//games, minutes, points, rebounds, assists, steals, blocks, turnovers, fouls

void percentile_scoring::print_top_n_games(int n) {
	std::cout << "Here are the " << n << " players who played the most: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[0][i]->name << percent_scores[0][i]->game_avg[0] << std::endl;
}

void percentile_scoring::print_top_n_minutes(int n) {
	std::cout << "Here are the " << n << " players who averaged the most minutes per game: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[1][i]->name << percent_scores[1][i]->game_avg[1] << std::endl;
}

void percentile_scoring::print_top_n_points(int n) {
	std::cout << "Here are the " << n << " best scorers: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[2][i]->name << percent_scores[2][i]->game_avg[2] << std::endl;
}

void percentile_scoring::print_top_n_rebounds(int n) {
	std::cout << "Here are the " << n << " best rebounders: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[3][i]->name << percent_scores[3][i]->game_avg[3] << std::endl;
}

void percentile_scoring::print_top_n_assists(int n) {
	std::cout << "Here are the " << n << " best assisters: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[4][i]->name << percent_scores[4][i]->game_avg[4] << std::endl;
}

void percentile_scoring::print_top_n_steals(int n) {
	std::cout << "Here are the " << n << " best stealers: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[5][i]->name << percent_scores[5][i]->game_avg[5] << std::endl;
}

void percentile_scoring::print_top_n_blocks(int n) {
	std::cout << "Here are the " << n << " best shot blockers: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[6][i]->name << percent_scores[6][i]->game_avg[6] << std::endl;
}

void percentile_scoring::print_top_n_turnovers(int n) {
	std::cout << "Here are the " << n << " worst ball handlers: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[7][i]->name << percent_scores[7][i]->game_avg[7] << std::endl;
}

void percentile_scoring::print_top_n_fouls(int n) {
	std::cout << "Here are the " << n << " players who commit the most fouls: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[8][i]->name << percent_scores[8][i]->game_avg[8] << std::endl;
}

void percentile_scoring::print_top_n_aggregate(int n) {
	std::cout << "Here are YOUR top " << n << " players: " << std::endl;
	for (int i = 0; i < n && i < players; i++) std::cout << std::right << std::setw(4) << i + 1 << ": " << std::left << std::setw(30) << percent_scores[9][i]->name << percent_scores[9][i]->game_avg[9] << std::endl;
}

void percentile_scoring::rank_top() {
	percentile_score_players();
	for (int i = 0; i < 750; i++) {
		float sum = 0;
		for (int j = 0; j < year.htable[i].size(); j++) {
			for (int k = 0; k < 9; k++) {
				sum += (year.htable[i][j].relative_game_avg[k] * weights[k]);
			}
			year.htable[i][j].game_avg[9] = sum;
		}
	}
	maxheap aggregate(players, 9);
	for (int j = 0; j < 750; j++) {
		for (int i = 0; i < year.htable[j].size(); i++) {
			aggregate.push(&year.htable[j][i]);
		}
	}

	for (int i = 0; i < players; i++) {
		percent_scores[9].push_back(aggregate.pop());
	}
}

void percentile_scoring::update_ranks(float w1, float w2, float w3, float w4, float w5, float w6, float w7, float w8, float w9) {
	weights[0] = w1;
	weights[1] = w2;
	weights[2] = w3;
	weights[3] = w4;
	weights[4] = w5;
	weights[5] = w6;
	weights[6] = w7;
	weights[7] = w8;
	weights[8] = w9;
}

void percentile_scoring::print_all_players() {
	year.printTable();
}

bool percentile_scoring::read_draft_file(std::string file) {
	std::ifstream draft_data;
	draft_data.open(file);
	std::string line;
	int counter = 0;
	if (draft_data.is_open()) {
		while (getline(draft_data, line)) {
			if (line.empty()) continue;
			cleaner(line);
			player *p = year.searchPlayer(line);
			if (p) {
				// std::cout << p->name << " found!" << std::endl;
				p->draft_flag = 1;
				counter++;
			} else {
				// std::cout << line << " not found :(" << std::endl;
			}
		}
	} else {
		std::cout << "Draft data failed to open" << std::endl;
		return 0;
	}
	std::cout << "Marked " << counter << " players" << std::endl;
	draft_data.close();
	return 1;
}

void percentile_scoring::write_to_final_csv() {
	std::ofstream write_out;
	write_out.open("output.csv");
	write_out << "Name,Position,Years,Height,Weight,Games,Minutes,Points,Rebounds,Assists,Steals,Blocks,Turnovers,Fouls,Draft Status" << std::endl;
	for (int i = 0; i < 750; i++) {
		for (int j = 0; j < year.htable[i].size(); j++) {
			write_out << year.htable[i][j].name << "," << year.htable[i][j].pos << "," << year.htable[i][j].years << "," << year.htable[i][j].height << ","
			<< year.htable[i][j].weight << "," << year.htable[i][j].game_avg[0] << "," << year.htable[i][j].game_avg[1] << "," << year.htable[i][j].game_avg[2] << ","
			<< year.htable[i][j].game_avg[3] << "," << year.htable[i][j].game_avg[4] << "," << year.htable[i][j].game_avg[5] << "," << year.htable[i][j].game_avg[6] << ","
			<< year.htable[i][j].game_avg[7] << "," << year.htable[i][j].game_avg[8] << "," << year.htable[i][j].draft_flag << std::endl;
		}
	}

	write_out.close();
}

void percentile_scoring::compare_to_ML() {
	int counter = players;
	for (int i = 0; i < players; i++) {
		if (i < 28) {
			if (!percent_scores[9][i]->draft_flag) counter--;
		} else {
			if (percent_scores[9][i]->draft_flag) counter--;
		}
	}
	float accuracy = 100*((float)counter/(float)players);
	std::cout << "You missclassified " << players - counter << " players for an accuracy of " << std::fixed << setprecision(2) << accuracy << std::endl;
	(accuracy < 83.88) ? std::cout << "You did NOT beat the computer. You did " << 83.88 - accuracy << " percent worse" <<std::endl : std::cout << "You beat the computer by " << accuracy - 83.88 << " percent" <<std::endl;
}



