#include "Player.hpp"
#include <climits>
#include <iostream>

void array_double(player arr[], int &cap) {
	int new_cap = 2*cap; //Define what the new size of the array should be
	player *new_arr = new player[new_cap]; //The new array
	for (int i = 0; i < cap; i++) new_arr[i] = arr[i]; //Copy all elements of the arrays
	delete [] arr;
	arr = new_arr; //Move the array
	cap = new_cap; //Adjust the size of the array
}

bool is_num(std::string s) {
	for (int i = 0; i < s.length(); i++) if (i != '1' && i != '2' i != '3' && i != '4' && i != '5' i != '6' && i != '7' && i != '8' i != '9' && i != '0' && i != '.') return 0;
		return 1;
}

/*This is the exact same as before just using type std::string for the array*/
// void array_double(std::string arr[], int cap) {
// 	int new_cap = 2*cap; //Define what the new size of the array should be
// 	std::string *new_arr = new std::string[new_cap]; //The new array
// 	for (int i = 0; i < cap; i++) new_arr[i] = arr[i]; //Copy all elements of the arrays
// 	delete [] arr;
// 	arr = new_arr; //Move the array
// 	cap = new_cap; //Adjust the size of the array
// }

void swap (player *x1, player *x2) { //Simple swap funciton for floats
	player temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}

player::player(std::string name, short int pos, float ppg, float rpg, float apg, float spg, float bpg) : name(name), pos(pos), ppg(ppg), rpg(rpg), apg(apg), spg(spg), bpg(bpg) {

}

player::player() {}

team::team (std::string name) : name(name) {}

maxheap::maxheap(int heapSize, char type) {
	heap = new player[heapSize];
	currSize = 0;
	this->maxSize = heapSize;
	if (type == 'a' || type == 'b' || type == 'p' || type == 's' || type == 'r') this->type = type;
}

maxheap::~maxheap() {
	delete [] heap;
}

void maxheap::push(player value) {
	if (!full()) {
		heap[currSize] = value;
		repair_up(currSize++);
	} else {
		array_double(heap, maxSize);
		push(value);
	}
}

player *maxheap::pop() {
	player *temp = &heap[0];
	if (!empty()) {
		heap[0] = heap[--currSize];
		repair_down(0);
	} else std::cout << "There's literally nothing to remove" << std::endl;
	return temp;
}

player *maxheap::peek() {
	return &heap[0];
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
	switch(type) {
		case 'a':
			if (heap[nodeIndex].apg > heap[p].apg) {
				swap(&heap[nodeIndex], &heap[p]);
				repair_up(p);
			}
			break;
		case 'b':
			if (heap[nodeIndex].bpg > heap[p].bpg) {
				swap(&heap[nodeIndex], &heap[p]);
				repair_up(p);
			}
			break;
		case 'p':
			if (heap[nodeIndex].ppg > heap[p].ppg) {
				swap(&heap[nodeIndex], &heap[p]);
				repair_up(p);
			}
			break;
		case 'r':
			if (heap[nodeIndex].rpg > heap[p].rpg) {
				swap(&heap[nodeIndex], &heap[p]);
				repair_up(p);
			}
			break;
		case 's':
			if (heap[nodeIndex].spg > heap[p].spg) {
				swap(&heap[nodeIndex], &heap[p]);
				repair_up(p);
			}
			break;
		default:
			std::cout << "Sum Ting Wong" << std::endl;
			break;
	}
}

void maxheap::repair_down(int nodeIndex) {
	int l = left(nodeIndex);
	int r = right(nodeIndex);
	int compar = nodeIndex;
	switch(type) {
		case 'a':
			if (l < currSize) {
				if (heap[l].apg > heap[nodeIndex].apg) {
					compar = l;
				}
				if (r < currSize) {
					if (heap[r].apg > heap[compar].apg) {
						compar = r;
					}
				}
			} else return;
			break;
		case 'b':
			if (l < currSize) {
				if (heap[l].bpg > heap[nodeIndex].bpg) {
					compar = l;
				}
				if (r < currSize) {
					if (heap[r].bpg > heap[compar].bpg) {
						compar = r;
					}
				}
			} else return;
			break;
		case 'p':
			if (l < currSize) {
				if (heap[l].ppg > heap[nodeIndex].ppg) {
					compar = l;
				}
				if (r < currSize) {
					if (heap[r].ppg > heap[compar].ppg) {
						compar = r;
					}
				}
			} else return;
			break;
		case 'r':
			if (l < currSize) {
				if (heap[l].rpg > heap[nodeIndex].rpg) {
					compar = l;
				}
				if (r < currSize) {
					if (heap[r].rpg > heap[compar].rpg) {
						compar = r;
					}
				}
			} else return;
			break;
		case 's':
			if (l < currSize) {
				if (heap[l].spg > heap[nodeIndex].spg) {
					compar = l;
				}
				if (r < currSize) {
					if (heap[r].spg > heap[compar].spg) {
						compar = r;
					}
				}
			} else return;
			break;
	}
	if (compar != nodeIndex) {
		swap(&heap[compar], &heap[nodeIndex]);
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

percentile_scoring::percentile_scoring() {
	size = 10;
	ppg = new player*[size]; 
	rpg = new player*[size];
	apg = new player*[size];
	spg = new player*[size];
	bpg = new player*[size];
	cumulative = new player*[size];

	for (int i = 0; i < sizeof(weights)/sizeof(weights[0]); i++) {
		weights[i] = 1;
	} 

	players = 0;
}

percentile_scoring::loadPlayer() {
	std::string inputs[8];
	team *t;
	while (1) {
		std::cout << "The teams currently in the system are:" << std::endl;
		for (int i = 0; i < teams.size(); i++) std::cout << teams[i].name << std::endl;
		std::cout << "What team does he play for?" << std::endl;
		getline(std::cin, inputs[0]);
		for (int i = 0; i < teams.size(); i++) {
			if (teams[i].name == inputs[0]) {
				t = &teams[i];
				break;
			}
		}
		std::cout << "Would you like to add this team? YES input 1. NO input 2." << std::endl;
		getline(std::cin, inputs[1]);
		if (inputs[1][0] == '1') {
			teams.push_back(inputs[0]);
			t = &teams[teams.size() - 1];
			break;
		}
	}
	std::cout << "Player name:" << std::endl;
	getline(std::cin, inputs[1]);
	while(1) {
		std::cout << "PPG? ";
		getline(std::cin, inputs[2]);
		std::cout << std::endl;
		if (is_num(inputs[2]))
			break;
		else
			std::cout << "Input a float..." << std::endl;
	}
	while(1) {
		std::cout << "RPG? ";
		getline(std::cin, inputs[3]);
		std::cout << std::endl;
		if (is_num(inputs[3]))
			break;
		else
			std::cout << "Input a float..." << std::endl;
	}
	while(1) {
		std::cout << "APG? ";
		getline(std::cin, inputs[4]);
		std::cout << std::endl;
		if (is_num(inputs[4]))
			break;
		else
			std::cout << "Input a float..." << std::endl;
	}
	while(1) {
		std::cout << "BPG? ";
		getline(std::cin, inputs[5]);
		std::cout << std::endl;
		if (is_num(inputs[5]))
			break;
		else
			std::cout << "Input a float..." << std::endl;
	}
	while(1) {
		std::cout << "SPG? ";
		getline(std::cin, inputs[6]);
		std::cout << std::endl;
		if (is_num(inputs[6]))
			break;
		else
			std::cout << "Input a float..." << std::endl;
	}
	while (1) {
		std::cout << "POS? ";
		getline(std::cin, inputs[7]);
		std::cout << std::endl;
		if (inputs[7] == '1' || inputs[7] == '2' || inputs[7] == '3' || inputs[7] == '4' || inputs[7] == '5')
			break;
		else
			std::cout << "Input an int..." << std::endl;
	}
	player p(inputs[1], stoi(inputs[7]), stof(inputs[2]), stof(inputs[3]), stof(inputs[4]), stof(inputs[5]), stof(inputs[6]));
	t->roster.push_back(p);
}
