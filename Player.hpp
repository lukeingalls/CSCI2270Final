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

	player(std::string, short int, float, float, float, float, float); //Define the constructor
};

class maxheap {
	public:
		maxheap(int);
		~maxheap();
		void push(float);
		float pop();
		float peek();
		bool full();
		bool empty();
	private:
		int parent(int);
		int left(int);
		int right(int);
		void repair_up(int);
		void repair_down(int);

		float* heap;
		int currSize;
		int maxSize;
};

class percentile_scoring {
	private:
		float stat_array[]; //This needs to be dynamically allocated so we can do array doubling as we push players to it.

	public:
		float return_percentile(std::string); /*Look for a player and then return their rank
		There's a couple issues we will end up needing to resolve here. Players with the same
		name can be dealt with later. The other is that we can compute the percentile as (position in array)/(array length)
		in general but when players have equal values we need to comput (first position of equal value)/(array length)*/
		percentile_scoring(int); /*Not sure exactly what to do here but the int can refer which stat we want to organize
		we will then have the program load all players into the heap and then pop them into the stat_array we probably need to 
		make some way of keep track of all players to make this process easier.*/
};

//http://www.espn.com/mens-college-basketball/team/stats/_/id/2006
