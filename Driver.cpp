#include "Player.hpp"

int main() {
	//Eventually this should become a menu like we've seen in other assignments. For now we need to get stuff working.
	percentile_scoring ps;
	ps.readinfile("CU.txt");
	ps.sort_basic_arrays();
	ps.print_top_n_points(3);
	/*So this doesn't work. Output should be:
	1. Tyler Bey		13.6
	2. Mckinley Wright	13.0
	3. Shane Gatling	9.7
	*/
}
