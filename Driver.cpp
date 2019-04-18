#include "Player.hpp"
#include <iostream>

int main() {
	//Eventually this should become a menu like we've seen in other assignments. For now we need to get stuff working.
	percentile_scoring ps;
	ps.readinfile("CU.txt");
	ps.print_all_players();
	ps.rank_top();
	std::cout << std::endl;
	ps.print_top_n_rebounds(4);
}
