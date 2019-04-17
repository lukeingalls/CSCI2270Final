#include "Player.hpp"
#include <iostream>

int main() {
	//Eventually this should become a menu like we've seen in other assignments. For now we need to get stuff working.
	percentile_scoring ps;
	ps.readinfile("CU.txt");
	ps.print_all_players();
	ps.sort_basic_arrays();
	std::cout << std::endl;
	ps.print_top_n_rebounds(4);
	/*So this doesn't work. Output should be:
	1. Tyler Bey		13.6
	2. Mckinley Wright	13.0
	3. Shane Gatling	9.7
	*/
}
