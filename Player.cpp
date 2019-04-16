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
