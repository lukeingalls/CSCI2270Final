
#include "Player.hpp"

int main() {
	percentile_scoring ps;
	ps.readinfile("train_data.csv");
	ps.sort_basic_arrays();
	ps.print_top_n_points(10);
	ps.rank_top();
	ps.print_top_n_aggregate(60);
	// ps.rtable().printTable(); //This is how to print all players
}

/*
//
// This is the start of a main function that Ben has created
//
#include "Player.hpp"
#include<iostream>
using namespace std;

void menu();

int main() {
	bool tf = 1;
	string menuChoice;
	//percentile_scoring ps;
	//ps.readinfile("train_data.csv");

	cout << "-----Welcome to the NBA Draft predictor-----" << endl;
	menu();
	getline(cin,menuChoice);
	do
	{

		switch(menuChoice[0])
		{

			case '1':
			{
				break;
			}
			case'9':
			{
				cout << "Exiting" << endl;
				//call desctructor here
				tf = false;
				break;
			}
		}
		if(tf == false)
		{
			break;
		}
		menu();
		getline(cin,menuChoice);


	}while(menuChoice[0] != '9' || tf == true);

}


void menu()
{
	cout <<"-----Please input the corresponding number for your selection and press 'Enter'-----" << endl;
	cout <<"1. ..." << endl;
	cout <<"2. ..." << endl;
	cout <<"3. ..." << endl;
	cout <<"4. ..." << endl;
	cout <<"5. ..." << endl;
	cout <<"6. ..." << endl;

}
*/
