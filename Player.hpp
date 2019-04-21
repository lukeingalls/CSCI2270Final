#include <string>
#include <vector>

struct player;

struct player {
	std::string name;
	std::string team;
	std::string pos;
	short int years;
	short int height;
	short int weight;
	short int games_played;
	float game_avg[8];

	bool draft_flag;

	float relative_game_avg[8];
	player(std::string, std::string, std::string, std::string, short int, short int, short int, std::vector<int>); //Define the constructor
	player();

	player* next;
};

class table {
	private:
		int table_size;
		player **htable;

		unsigned int hashFunction(std::string);
	public:
		table(int);
		~table();
		void addPlayer(player *);
		player* searchPlayer(std::string, std::string);
};

class maxheap {
	public:
		maxheap(int, int);
		~maxheap();
		void push(player*);
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

		player** heap;
		int type_index;
		int currSize;
		int maxSize;
};

class percentile_scoring {
	private:
		std::vector<std::vector<player*> > percentile_scores;

		std::vector<float> weights;

		bool run;
		int players;
		int start_year;
		std::vector<table> year;
		void sort_basic_arrays(); //Calls the heaps. Basically the midterm question. Untested (or at least not working)
		bool empty();
		void percentile_score_players();
		int find_ith_equivalent(player **, int, char);
	public:
		percentile_scoring(); //Seems to work
		void rank_top(); //Cumulative stats
		/*So for top rank this will need to account for the ranks in all the other matrices and then weight them with float weights.
		This shouldn't be a priority yet since it is more important to get the other stuff working first. We may need to define another
		heap class to get this done. Do whatever though*/
		void update_ranks(float, float, float, float, float); //Still needs to be defined. Just updated the weights.
		void loadPlayer(); //Done. Untested.
		void readinfile(std::string);
		void print_top_n_points(int); //Prints stuff. Defined.
		void print_all_players();
		void print_top_n_assists(int);
		void print_top_n_rebounds(int);
		void print_top_n_steals(int);
		void print_top_n_blocks(int);
};

