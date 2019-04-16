#include "Player.hpp"
#include <climits>
#include <iostream>

void array_double(float arr[], int &cap) {
	int new_cap = 2*cap; //Define what the new size of the array should be
	float *new_arr = new float[new_cap]; //The new array
	for (int i = 0; i < cap; i++) new_arr[i] = arr[i]; //Copy all elements of the arrays
	delete [] arr;
	arr = new_arr; //Move the array
	cap = new_cap; //Adjust the size of the array
}

/*This is the exact same as before just using type std::string for the array*/
void array_double(std::string arr[], int cap) {
	int new_cap = 2*cap; //Define what the new size of the array should be
	std::string *new_arr = new std::string[new_cap]; //The new array
	for (int i = 0; i < cap; i++) new_arr[i] = arr[i]; //Copy all elements of the arrays
	delete [] arr;
	arr = new_arr; //Move the array
	cap = new_cap; //Adjust the size of the array
}

void swap (float *x1, float *x2) { //Simple swap funciton for floats
	float temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}

player::player(std::string name, short int pos, float ppg, float rpg, float apg, float spg, float bpg) : name(name), pos(pos), ppg(ppg), rpg(rpg), apg(apg), spg(spg), bpg(bpg) {

}

team::team (std::string name) : name(name) {}

maxheap::maxheap(int heapSize) {
	heap = new float[heapSize];
	currSize = 0;
	this->maxSize = heapSize;
}

maxheap::~maxheap() {
	delete [] heap;
}

void maxheap::push(float value) {
	if (!full()) {
		heap[currSize] = value;
		repair_up(currSize++);
	} else {
	}
}

float maxheap::pop() {
	float temp = heap[0];
	if (!empty()) {
		heap[0] = heap[--currSize];
		repair_down(0);
	} else std::cout << "There's literally nothing to remove" << std::endl;
	return temp;
}

float maxheap::peek() {
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
	if (heap[nodeIndex] > heap[p]) {
		swap(&heap[nodeIndex], &heap[p]);
		repair_up(p);
	}
}

void maxheap::repair_down(int nodeIndex) {
	int l = left(nodeIndex);
	int r = right(nodeIndex);
	int compar = nodeIndex;

	if (l < currSize) {
		if (heap[l] > heap[nodeIndex]) {
			compar = l;
		}
		if (r < currSize) {
			if (heap[r] > heap[compar]) {
				compar = r;
			}
		}
	} else return;
	if (compar != nodeIndex) {
		swap(&heap[compar], &heap[nodeIndex]);
		repair_down(compar);
	}
}
