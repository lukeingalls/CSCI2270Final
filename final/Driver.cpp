
#include "Player.hpp"
#include<iostream>
#include<string>
using namespace std;
void menu();

int main() {
	percentile_scoring ps;
	ps.readinfile("blank");
	ps.sort_basic_arrays();
	ps.print_top_n_points(10);
	ps.rank_top();
	ps.print_top_n_aggregate(60);
	ps.read_draft_file("drafts.csv");
	ps.write_to_final_csv();
	// ps.print_all_players();
	// ps.rtable().printTable(); //This is how to print all players
	bool tf = 1;
	string menuChoice, n;

	cout << "-----Welcome to the NBA Draft predictor-----" << endl;
	menu();
	getline(cin,menuChoice);
	do
	{
		// if(menuChoice[0] != 'A' || menuChoice[0] != 'B' || menuChoice[0] != 'C' || menuChoice[0] != 'D' || menuChoice[0] != 'E' || menuChoice[0] != 'F' || menuChoice[0] != 'H' || menuChoice[0] != 'J' || menuChoice[0] != 'K' || menuChoice[0] != 'Q')
		// {
		// 	cout << "Enter valid menu choice, make sure your input is capitalized" << endl;
		// 	menu();
		// 	tf = true;
		// 	bSreak;
		// }
		switch(menuChoice[0])
		{
			case 'A':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_games(stoi(n));
				tf = true;
				break;
			}
			case 'B':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_minutes(stoi(n));
				tf = true;
				break;
			}
			case 'C':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_points(stoi(n));
				tf = true;
				break;
			}
			case 'D':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_rebounds(stoi(n));
				tf = true;
				break;
			}
			case 'E':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_assists(stoi(n));
				tf = true;
				break;
			}
			case 'F':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_blocks(stoi(n));
				tf = true;
				break;
			}
			case 'G':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_steals(stoi(n));
				tf = true;
				break;
			}
			case 'H':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_turnovers(stoi(n));
				tf = true;
				break;
			}
			case 'I':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				ps.print_top_n_fouls(stoi(n));
				tf = true;
				break;
			}
			case 'J':
			{
				ps.rtable().printTable();
				tf = true;
				break;
			}
			case 'K':
			{
				string w1,w2,w3,w4,w5,w6,w7,w8,w9;
				cout << "How much would you like to weight number of games played" << endl;
				getline(cin, w1);
				cout << "How much would you like to weight number of minutes played" << endl;
				getline(cin, w2);
				cout << "How much would you like to weight average points per game" << endl;
				getline(cin, w3);
				cout << "How much would you like to weight average rebounds per game" << endl;
				getline(cin,w4);
				cout << "How much would you like to weight average assists per game" << endl;
				getline(cin,w5);
				cout << "How much would you like to weight average steals per game" << endl;
				getline(cin,w6);
				cout << "How much would you like to weight average blocks per game" << endl;
				getline(cin,w7);
				cout << "How much would you like to weight average turnovers per game" << endl;
				getline(cin,w8);
				cout << "How much would you like to weight average fouls per game" << endl;
				getline(cin,w9);
				ps.update_ranks(stof(w1),stof(w2),stof(w3),stof(w4),stof(w5),stof(w6),stof(w7),stof(w8),stof(w9));
				cout << "Enter how many top players would you like to display with the new weights "<< endl;
				getline(cin, n);
				ps.print_top_n_aggregate(stoi(n));
				tf = true;
				break;
			}
			case'Q':
			{
				cout << "Exiting" << endl;
				// call destructor
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

	}while(menuChoice[0] != 'Q' || tf == true);

}

void menu()
{
	cout << endl;
	cout <<"A. Display top N players for number of games played " << endl;
	cout <<"B. Display top N players for minutes played " << endl;
	cout <<"C. Display top N players for points per game " << endl;
	cout <<"D. Display top N players for rebounds per game " << endl;
	cout <<"E. Display top N players for assists per game " << endl;
	cout <<"F. Display top N players for steals per game " << endl;
	cout <<"G. Display top N players for blocks per game " << endl;
	cout <<"H. Display top N players for turnovers per game " << endl;
	cout <<"I. Display top N players for fouls per game " << endl;
	cout <<"J. Display ALL players " << endl;
	cout <<"K. Customize each statistics weighted value " << endl;
	cout <<"Q. Quit " << endl;

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
