#include <string>
#include <vector>

void array_double(float[], int); //This can be like what we used earlier this year
void array_double(std::string[], int); //We likely will need this for all data types but at the very least these two

struct player;

struct team {
	std::string name;
	std::vector<player> roster; //We don't have to use a vector but we ought to store the players in a random access structure

	team(std::string); //Define the constructor
};

struct player {
	/*		Feel free to create more variables as needed but these should be the baseline		*/
	std::string name;
	short int pos;
	float ppg;
	float rpg;
	float apg;
	float spg;
	float bpg;

	std::vector<player**> rankings;
	player(std::string, short int, float, float, float, float, float); //Define the constructor
	player();
};


//Might have logic errors
class maxheap {
	public:
		maxheap(int, char);
		~maxheap();
		void push(player);
		player* pop();
		player* peek();
		bool full();
		bool empty();
	private:
		int parent(int);
		int left(int);
		int right(int);
		void repair_up(int);
		void repair_down(int);

		player* heap;
		char type;
		int currSize;
		int maxSize;
};

class percentile_scoring {
	private:
		player **ppg; //This needs to be dynamically allocated so we can do array doubling as we push players to it.
		player **rpg;
		player **apg;
		player **spg;
		player **bpg;
		player **cumulative;

		float weights[5];

		int players;
		int size; //Doesn't matter
		std::vector<team> teams;
	public:
		percentile_scoring(); //Seems to work
		void rank_top(); //Cumulative stats
		/*So for top rank this will need to account for the ranks in all the other matrices and then weight them with float weights.
		This shouldn't be a priority yet since it is more important to get the other stuff working first. We may need to define another
		heap class to get this done. Do whatever though*/
		void update_ranks(float, float, float, float, float); //Still needs to be defined. Just updated the weights.
		void loadPlayer(); //Done. Untested.
		team *teamexists(std::string); //Done. Untested. Sees whether a team appears in the teams vector.
		void readinfile(std::string);
		void check_arrays(); //Calls array doubling until everythings chilling. Should work. Untested.
		void sort_basic_arrays(); //Calls the heaps. Basically the midterm question. Untested (or at least not working)
		void print_top_n_points(int); //Prints stuff. Defined.


		void print_top_n_assists(int); //Undefined	oughta be suuuuuper easy
		void print_top_n_rebounds(int); //Undefined	oughta be suuuuuper easy
		void print_top_n_steals(int); //Undefined	oughta be suuuuuper easy
		void print_top_n_blocks(int); //Undefined	oughta be suuuuuper easy
};

//http://www.espn.com/mens-college-basketball/team/stats/_/id/2006
