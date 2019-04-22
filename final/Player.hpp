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
	float game_avg[10];
	//0: games per year, 1: minutes, 2: points, 3: rebounds,
	//4: assists, 5: steals, 6: blocks, 7: turnovers
	//8: fouls, 9: years played
	bool draft_flag;

	float relative_game_avg[10];
	player(std::string, std::string, std::string, std::string, short int, short int, float []); //Define the constructor
	player();

	player* next;
};

struct table {
		int table_size;
		std::vector<player> htable[750];

		unsigned int hashFunction(std::string);
		table();
		void addPlayer(player);
		player* searchPlayer(std::string, std::string);
		player* searchPlayer(std::string);
		void printTable();
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
		std::vector<player*> percent_scores[10];
		//same as the order of the stats[] in class player
		float weights[9];

		bool run;
		int players;
		int start_year;
		table year;
		bool empty();
		int find_ith_equivalent(std::vector<player*>, int, int, int);
	public:
		void sort_basic_arrays(); //Calls the heaps. Basically the midterm question. Untested (or at least not working)
		void percentile_score_players();
		percentile_scoring(); //Seems to work
		void rank_top(); //Cumulative stats
		table rtable();
		/*So for top rank this will need to account for the ranks in all the other matrices and then weight them with float weights.
		This shouldn't be a priority yet since it is more important to get the other stuff working first. We may need to define another
		heap class to get this done. Do whatever though*/
		void update_ranks(float, float, float, float, float, float, float, float, float); //Still needs to be defined. Just updated the weights.
		void readinfile(std::string);
		void print_all_players();
		void print_top_n_games(int);
		void print_top_n_minutes(int);
		void print_top_n_points(int); //Prints stuff. Defined.
		void print_top_n_assists(int);
		void print_top_n_rebounds(int);
		void print_top_n_steals(int);
		void print_top_n_blocks(int);
		void print_top_n_fouls(int);
		void print_top_n_turnovers(int);
		void print_top_n_aggregate(int);
		bool read_draft_file(std::string);
		void write_to_final_csv();
};
