#include "Player.hpp"
#include<iostream>
#include<string>
using namespace std;
void menu();

void jokic();

int main() {
	percentile_scoring all_data;
	percentile_scoring data_2019;
	percentile_scoring data_2018;
	all_data.readinfile("train_data.csv");
	all_data.readinfile("test_data.csv");
	all_data.readinfile("prediction.csv");
	all_data.read_draft_file("drafts.csv");
	data_2018.readinfile("test_data.csv");
	data_2019.readinfile("prediction.csv)");
	all_data.sort_basic_arrays();
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
				all_data.print_top_n_games(stoi(n));
				tf = true;
				break;
			}
			case 'B':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				all_data.print_top_n_minutes(stoi(n));
				tf = true;
				break;
			}
			case 'C':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				all_data.print_top_n_points(stoi(n));
				tf = true;
				break;
			}
			case 'D':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				all_data.print_top_n_rebounds(stoi(n));
				tf = true;
				break;
			}
			case 'E':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				all_data.print_top_n_assists(stoi(n));
				tf = true;
				break;
			}
			case 'F':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				all_data.print_top_n_blocks(stoi(n));
				tf = true;
				break;
			}
			case 'G':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				all_data.print_top_n_steals(stoi(n));
				tf = true;
				break;
			}
			case 'H':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				all_data.print_top_n_turnovers(stoi(n));
				tf = true;
				break;
			}
			case 'I':
			{
				cout << "How many players would you like to display?" << endl;
				getline(cin, n);
				all_data.print_top_n_fouls(stoi(n));
				tf = true;
				break;
			}
			case 'J':
			{
				all_data.rtable().printTable();
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
				data_2018.update_ranks(stof(w1),stof(w2),stof(w3),stof(w4),stof(w5),stof(w6),stof(w7),stof(w8),stof(w9));
				cout << "Enter how many top players would you like to display with the new weights "<< endl;
				getline(cin, n);
				data_2018.print_top_n_aggregate(stoi(n));
				tf = true;
				break;
			}
			case 'L':
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
				data_2019.update_ranks(stof(w1),stof(w2),stof(w3),stof(w4),stof(w5),stof(w6),stof(w7),stof(w8),stof(w9));
				cout << "Enter how many top players would you like to display with the new weights "<< endl;
				getline(cin, n);
				std::cout << "Here is YOUR 2019 draft class:" << std::endl;
				data_2019.print_top_n_aggregate(stoi(n));
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
			// case'Z':
				// jokic();
				// break;
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
	cout <<"K. Customize each statistics weighted value and test it" << endl;
	cout <<"L. Customize each statistics weighted value and make a prediction" << endl;

	cout <<"Q. Quit " << endl;
	// cout <<"Z. Display Jokic" << endl;
}

void jokic() {
	std::cout	<< "+++++++++++++///++:.`````-/++++++/-.`````+o.:`-.`::````````.```....```````...............`....................-/ooshsdhydyos:/::-................................................```-`/y+/-.`:.-..o:``-+ooo:-.-.`````````/oo+ooooooo++++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```......```````............``..............-/osdhmmmmmmmmmmmmmmdmdddyso//-...........................................``:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```......`````````````````````.........-/osddmmmmmmNNNNNNNNNNNNmmmmmmmmmmmdy+/........................................``:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```......`````````````````````......:oydmmmmNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmmmmh+-.....................................``:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```......`````````````````````...-+smmmmNNmNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmmmmmmdy+-..................................``:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```............................-odmmmNNNmNNNmmmmNNNNNNmNNmNmNNNNNNNNmmNNmmNmmmmmmmdho:................................``:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```.........................`:odmmmNmNmmmmmmmmmmmmmmmmmmmmmmmmmmNmNNmmNmmmmmNNmmmmmddh+-..............................``:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```.........................+dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmNNNmmmmmmmmmmmmmmmddhyo-............................``:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```......................`/hmmmmmmmmmmmddddmmmddmmddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmmddy/-..........................``:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```....................../dmmmmmmmmmmmdddddddmddddhhddhhhhhhhdhddmmmmmmmmmmmmmmmmmmmmmmmmddy/........................```:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.```````````````````````:sdmmmmmmmmmdddddhhhdhddddhhyhhdhhhhhhhhddddmmmmmmddddddmmmmmmmmmmmddho.......................```:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````.````..............````:hmdmmmmmmddddhhhhhhhyhhhddhyyyyyysyyhyyyhhhdddmmddddddmmdddmmmmmmmmmdhh/......................```:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````..``````.....```````.`:hdddmmmmddddddhdhdddhyhyyhhhhyyyysysyyhyhhhhdddmmddddddddddddmmmmmmmmddho...``````````````````````:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````....................``sdhdddddhhhhdhhhhdddhhhyyyyyhyyyysssyyyyhddddhhddddddhhdhdhhddddddmmmmdddy-..``````````````````````:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::`````````````````````````````.shhddhhhyyyyyhhhhdddhhyssyyhysssssssyyyhyhhhhhhhhdddhhhhhhhhyyhhdddmmmdddds.......................`:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````````````````````````.+hhhddhyysssssssyyyyhhhhyyyyyyssyysssyyyyhhhhhhhhhyhhyyyyyhyyyyyyyhddddddddh+......................`:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````````````````````````-yhhhhhyyssooo++o+oossyyyyyyyysssssosossyyyyyhyhsyyysssssssssssssssyhhdddddddy+.....................`:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::```````.....................:yyyyyyysso+++//////++++++oooooo+++++/++osssoss++++++++ooo+o+oooooosyyhhdhddhhs.....................`:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::```````-/:////////::::::::::ohyyyyyssso+/////////:::::::::::-:::::::/+///////:::://///++++++oooosyyhhhhhhh+`....................`:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::```````...............::::::ohhhhhyyss++////////::::::-----------:--:::::::::::::::////////+++ooosyhhhhyyys.....................`:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``````````````````````./////shhdhhyyyso+///////:::::::---------------::::::::::::::////////+++ooosyyyyysoyy-.....................:`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::```````````````````````./////hhhhyyyso++///////::::::::-----------------:::::::::://////////+++ossyyssoooyhy/++++++++++++++++++++/`/yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::````````````````````````.////shhhyyssso+//////:::::::::::::::::--------:::::::::////////////+++oosyss+//+ss+/////////////////////-./yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``..````````````````````.::::+hhhhyssso++/////::::::/:/::::::::::::::::::::::://////////////+++oosyyo//:+oo/::--------------------./yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``./`.`````````````````:+++++ohhhhyssso+////::////::::::::::::::::::::::::::::::::::////////++++ossss/://oo//-...................../yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+`--.``````````````-oooooo+hhhhyyso++////:::/:::::::--------::::::::::::::::::::::///////++++oooss+///+/::....................../yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+`---..````````````/++++++/yhhyys++++////::::::::::-------------------------:-::::::://///+++++++++:/+//:-......................+yo/-.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+`----:++++++++++++++++++++shhyyo+////////:::::::::---------------------------::::::://////++/:/::+//////:----/////////////////+syo/-.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+`-----::::::::::::::::+o++ohhhyo////////:::::::::-----------------:-::-::::://++oooo++oo+/++/:::-:::///++:oo/yyyyyyyyyyyyyyyyyyyyo/-.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+`---------------------/+o+oyhhyo/////////++/+/+++++++/////:::::---:::///+oosssyyyyyssssssoooo/:::-::+/+ssoo+++/////////////////////-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+`--------------------:++++osyyy+///+++oooooossssyyyyyyyssso+/:----::/+oossyhhhhhyysooooo+++ooo+++:-:yyyso+++o+////////////////////+-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+````````````````````-++///+syhy+///+ooo+++oossyyyyyyyhhhyyso+::---::/ooossyyysysdyyyssooo++++oo++/-:osoo++ooos/::::::::::::::::::::-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+````````````````````:+/////+shs////++//++osssshysmoyosyysooo+//::://+oooosso//sohsoo+syso+++/++++/:-:o+++++oos+-.....................`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+--------------------:+//////oyo////////++osso/+osso++oso++/++//::///osoosoo+/://++//++ooo++/////++/--++ooo++os+::::::::::::::::::::-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+--------------------:+///://oo+///::::///+++++/+++++++++///++//::///+ooo+++///////++++++++//////++/:-/oo++++os+--------------------..`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+::::::::::::::::::::////////++////:::::///////////////////++///::///+ooooo+/////:://///////////++++/::oso++/+s/......................`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+/--------------------://::/o+///////////////:::::://///////////:://+++++o++///:::::://///:::///+++//::+ooo+++o:....................-.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+s````````````````````://::///////////::::::::::::://:://///////:://+oo++++++///:::::::::::::://++////:+++oso+o:--------------------:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y....................-//:///////////::::::::::::::/::://////////://+o++++++//////:::::::::::://++///+/+/oyyo+o:---------------------.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y-...................-//://:/+//////::::::::::::::::::://+//+//////+oooo++/////:::::::::::::://+///++++syyo+++---------------------:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y.```````````````````.//://::++/////:::::::::::::::::::/+++////::://+osooo/:::::::::::::::::://++/++++yyso+++/:::::::::::::::::::--:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:.```````````````````:/::///+++////:::::::::::::::::::/++////:--::/+ooo++o/::::::::::::::::://++/+++++++oo+:--------------------.-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:o--------------------://:::/o+////::::::::::::::::::://////:----::/+++++++/::::::::::::::://+++/+++++/+++:```````````````````-:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:sy--------------------:/:::/++/////:::::::-:--::::::://+///::::::/++++o++oo+:::::::::::::///+++/+++oo+++:-------------------+y:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shy/-------------------:/:///++///::::::::----:-:-:::/++oo+//::///++ooooooo+/::::::::::::///++//++++++/--------------------/hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhho-:::::::::::::::::::::::/+////:::::::-------:::::/+++////+++++oooooo++/:::::---:::::///++////--..------------------.`-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy`.-:::::::::::::::::.`..-/+///:::::::--------:::::/+++//////++ooooo++///::::::::::::///+++//--.`.----------------:.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```o::::::::::::::::.``.--+////::::::-------::////++//////://///+++++++///:::::::::///++++/:`````...............ss.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd---------------..---.://///:::::------::////////:::::::::///////+++++/::::::::///++++/....................-do.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..```````````````````.//////:::::::--:://+////++++++++++oooooooossso+/:-:::///////++/:````````````````````+ho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd.....................-:///////:::::--::/+ooooo++/////++///////++o+///::::::///////++/:...................`sho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd.-::::::::::::::::::::/:///////:::::--://////////://////////////////:::::////////++/:/````````````````````yho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd.-//////////////////////:///////:/::-:::::/://:////+oooooo+////:///:::::::///////+/:+/````````````````````yho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..////////////////////////////////:/::::::://:::://+++ooo+///::::::::::::///////+///+/````````````````````hho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..///////////////////////++/////////::::::::::::::///::////////:::::://///////+++/+++:````````````````````hho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..//////////////////////:/++////////:::/::::::::::::::-:::://////////////////+++/++++:````````````````````hho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..///////////////////////://++////////:::://:/::::::--:-::::///////////////++++++++++:````````````````````dho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..+//////////////////////:::/++++///////:://///::::::::::::::////++/+++/+++oo++++++++:``````````````````-:dho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..///////////////////////:::://+++++/////////////::::://:::////+++++oo++oooo+++++++o+:````````````````-+shdho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::.-.-/+////////////////::::://++o+oo++++++/+///////::///+/++ooooooossoo+++++++++++:```````````````+hssddho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::`-..-h+//////////////:::::::://++ossoo+ooooooo+++++++ooosssooossysso+++++++++++++:`````````.```-.hdssddho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::`-..-do:::::::::::///::::::::::///+oossssoosssssssssssssssooossso++++++++++++++++:````````:.```-.hdssddho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::`-..-do:-`````````:///:::::::::::///++ossssssooosssooooosoosss++++++++//////+++++:`````-/`/.```-.hdssddho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::`-..-do:-.:`````.`:///::::::::::::::///++++oooooooo+++++++++++++++++////////+++++:````+d+`/.```-.hdssddho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::`-..-do:-./````.//////::::::::::::::::::/:://///////////////////+////////////++++/--:-dd+`/.```-.hdssddho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::`-..-do:-./``.-/+++///:::::::::::::::::::::::::::::::::::::://///////////////++++//++:ddyo+-.``-.hdssddho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::`-..:ds/-./.:/+++++///::::::----:::::::::::----------:::::::://///////:://////+++//ooooymNmo/:.-.hdssddho.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..::.-:/ddmho:+++///+++///::::-----:--::::::::::::-------:::::::::/:::::::::://///+++++sssssydms//:/-sdhyhdhs.``-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy```yd..:::::/ddso+++/////++////:::::--------:::::::::::::::::::::::::::::::::::::::////++++ssooooshm/::::::mmmhmmds:`-+hy:`-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhy``:hd+::::---/ds+/////////+/////:::::--------::::-:-----:::::::::::::::::::::::::::////+++oooooooyms--:::::mmmmmmmmmyoshh+.-:.`:.--.o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``.+y:shhhh/odmmd:-------+h+///////////////::::::-----------------------::::::::::::::::::::::////+++oooo+osdy-------ommmmmmmmmmmmmmmds/--:----o:``-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:`-.`::``-shyhddmmmmmmmmd--......+y/:::::////////:::::::--------------------------------:-:---:::::::////+++o+++oohh-----.--mmmmmmmmmmmmmmmmmm/::::::os:.`-+ooo:-.-.`````````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````+o.:.---::+hmmmmmmmmmmmmddmmh-.......+s/::::::://///::::::::-------------------------------------:::::::///++++++++syh--.-....ymmmmmmmmmmmmmmmmmd-::::::yyyso+oooo++//:-.```````/oo+oooosoo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.`````:++/:::::-:dmmmmmmmmdddddddmmh-......./s/::::::://///::::::::-----------------------------------::::::::////+++++ooyy-.......ommmmmmmmmmmmmmmmmmh-:::::/yhsoooooooooooosoo+//:-./oo+ooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++/-.``.-:/+ss/:-:---ommmmmmmmmdddddddddd:.......:s+:::::::///::::::::::--------------------------------::::::::://///+++oooho-.......ommmmmmmmmmmmmmmmmmmy-::::::yyo++++++++++++oooooosssssooooooooo+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````-/+o++++//:/+ooooosss------:mmmmmmmmmmmddddddmdd/........oo::::::://:::::::::::----------:---------------------:::::::::////++ssyh:........smmmmmmmmmmmmmmmmmmmmy--::--:yy++++///++++++++++oooooossssssssso+o++//-.``````" << std::endl
                << "++++++++++++++++++:.`````:/+++++oooo+++++ooosy:------hmmmmmmmmmmmddddddddds......../s/:::::://::::::::::::--------:::----:-:---------::::::::::::///+syhh+........-hmmmmmmmmmmmmmmmmmmmmmh-------sy+////////++++++++++ooooooooosssssooo+//-.``````" << std::endl
                << "++++++++++++++++++:..-:/+oooo+++++++++++++++oy/------smmmmdddmmmmmdddddddddh:``.....-+o/::::::::::::::::::-:-:-:-::::::::::------:::--:::::::::://+oyyy+........./dmmmmmmmmmmmmmmmmmmmmmmh.-----.+y+/////////++++++++++++++ooooooooossoo+/-.``````" << std::endl
                << "++++++++++++++++++++oooo+++++++/////////////+y+.---.-/mmdddddmmmmmdddddddddddo........-+so/:::::::::::::::--::-:::::::::::::::::::::---::::////+ooyyo:.........-ymmmmmmmmmmmmmmmmmmmmmmmmm-..----:ys////////++++++++++++++++++++++oooosso+:-``````" << std::endl
                << "+++++++++++++++ooo+++++++++//////////////////so......:mmmmdddmmmmdddddddddddddh/.`.......:oss+/::::::::::::::::::::::::::::::::::::---::://++osyyo/..........-sdmmmmmmmmmmdmmmmmmmmmmmmmmm/.......sy/////////+//++/++++/++/+++++++++oooooso/-.````" << std::endl
                << "++++++++++++oooo+++++////////////////////////so......:mdddddddddddddddddddddddddy:`..`......:+syo+/::::::::---::::::::::::::::::::---::/++osss+:...........:sdmmmmmmmmmmmmmmmmmmmmmmmmddmmo.......+y+////////////////////////////++++++ooosso:...." << std::endl
                << "++++++++++oo+++++++//////////////////////:///so......-mdddddddddddddddddddddddddddy:...........-:+oso+/::::---:::::::::::::::::::::::/+oso/:............./ydmmmmmmmmmmmmmmmmmmmmmmmmmdddmmd.......-so///////////////////////////////++++ooooos+:.." << std::endl
                << "++++++++o+++++++/////////////////////////:///s+......-ddddddddddddddddddddddddddddddy/.`............-/+oo+/:---:::::::::::::::::::/+oo/:............../shdmmmmmmmmmmmmmddmmmmmmmmmmmdddmmmm/.......os////////:::::://////////////////++++oooooso/:" << std::endl
                << "++++++++++++//////////////////////////////://s/......-ddddddddddddddddddddddddddddddddhs/-...............:+o+/:::::::::::::----:+s+:..............-/shddmmmmmmmmmmmmddddddmmmmmmmmmddddmmmmh.......:s+//:/:::::::::::::::/:///////////+++++ooooss+" << std::endl
                << "+++++++++///////////:://////////////:/::::://y-......-dddddddddddddddddddddddddddddddddddhs+:.`...........`.:+o+//::::::-----:+o/-............-/ohddmddmmmmmmdddddddddddddmmmmmmmmddddmmmmmm:.......ss:::::::::::::::::::::::::////////+++++ooooss" << std::endl
                << ":/+++++/////////::::::::::::/::::::::::::::/+y.......-ddddmdddddddddddddddddddddddddddddddddhhs+:.`.........`.-+o++//:::::::/o+............:+yhdddmdddddddddddddddddhhhhhhdhhhhhdddddmmmmmmdy.......:s+::::::::::::::::::::::::::://////+++++oooos" << std::endl
                << "/++++///////:::::::::::::::::::::::::::::::/os.......:ddddddddddddddddddddddddddddddddddddddddddhhs/-........```-+so+//::::+o:..`.......:shddddddmdddds+++ody/////dh:::/++ms::::sddddmmmmmmdd:.......os:::::::::::::::::::::::::::///////+++++oooo" << std::endl
                << "+++++/////:::::::::::::::::::::::::::::::::/s+`......+ddddddddddddddddddddddddddddddddddddddddddddddhy/-``.....``.:oso+//+o+.```......:ydddddddmmdddddh::::ho::::-sy-::+::dh-:::+ddmmmmmmmdddy.......-s+::::::::::::::::::::::::::://////+++++oooo" << std::endl
                << "+++/////:::::::::::::::::::::::::::::::::::/y:......`yddddddddddddddddddddddddddddddddddddddmmdddddddddh+.``....```./ssoso:..........sdddddddmmmdddddddy-::+/:-+:::o-:-+--hd:::::ddmmmmmmmdddm/.......+y/::::::::::::::::::::::::::///////+++++ooo" << std::endl
                << "++//////::::::::::::::::::::::---::::::::::oy.......-dddddddddddddhddddddddddddddddddddddddddddmdddddddddy-`.......``./o+.`........-yddddddmmmmddddddddd+:::::-y+::::::+--oy::::/mdmmmmmmdddddd-.......ss::::::::::::::::::::::::::://////++++++oo" << std::endl
                << "+//////:::::::-------------------:--::::::/s+`.....`+dddddddddddy++dddddddddddddddddhhhhyysssshmmmddddddddh/``......```.```........hdddddmmmmdddddddddddd/::::-hh:::::++::::://ohmdmmmmmmddddddy.......:y+::::::::::::::::::::::::::///////++++++o" << std::endl
                << "+/////::::::::----------------:-------::::/y-.......hdddddddddh+:-hdddddddhhhyso+////++osyyhddddmmmmdddddddd:`.........`.........`sddddmmmmmdddddddddddddysssssdhyyysyhyyyysshssyydmmmmmdddddmdd/.......+y:::::::::::::::::::::::::::///////++++++" << std::endl
                << "+/////:::::::::-----------------------::::os`....../dddddddddd::::/ossso++/::://osyhhddddddddddddmmmmmddddddh..........`.........:dddmmmmmddddddddmmdddyo+ooy/od++sd+sd/oyso+hososddmmmddddddmddh........so:::::::::::::::::::::::::::://////+++++" << std::endl
                << "/////::::::::::-----------------------:::/y:`......ydddddddddd/::::::::://+syhdddddddddddddddddddddmmmmmddddd+`.................`oddmmmdddddddddmmmdddddsdyhdyhdshsdsshssshoyoy+s/ddmmmdddddddddds.......:y/:::::::::::::::::::::::::::///////++++" << std::endl
                << "////:::::::::::------------------------::+s``....`/ddddddddddddysooosyyhddddddddddddddddddddddddddmmmmmmmddddy`.................`sdmmddddddddmmmmmmddmdddddddddd/h/h+s+ohohsysdyhymdmmdddddddddddd+.......os:::::::::::::::::::::::::::////////+++" << std::endl
                << "////:::::::::::------------------------:/s:``.....hdddddddddddddddddddddddddddddddddddddddddddmmmmmmdmmmmmmmdd.................-:ymdddddddmmmmmmmddddddddddddddddhddddddddddddmdmdddmdddddddddddddd-......-y+:::::::::::::::::::::::::://///////++" << std::endl
                << "//::::::::::::::-----------------------:+s``....`+dddddddddddddddddddddddddddddddddddddddddmmmmmmmmmmmmmmmmmmmo++ooooossssyyhhddmddddmmmmmmmmmddddddddddddddddddddddddddddddddmddddddddddddddddddddy......./y/::::::::::::::::::::::::://////////+" << std::endl
                << "//:::::::::::::::---------------------:/s:``.....hddddddddddddddddddddddddddddddddddmmdmddmmmmdmddddddddddddddddddmmdmdmmmmmmmmmmmmmmmmmmmmddddddddddddddddddddddddddddddddddddddddddddddddddddddddd+`......oo:::::::::::::::::::::::::://///////+" << std::endl
                << "//:::::::::::::::---------------------:+o```...`oddddddddddddddddddddddddddddddddddddmmdmmmmdddddddddddddddddmmmmmmmmmmmmmmmmmmmmmmmmmmddddddddddddddddddddddddddddddmddddddddddddddddddddddddddddddd:......-y+///::::::::::::::::::::::://///////" << std::endl
                << "/:::::::::::::::---------------------:/s-```..`:ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddmmmmdddmmmmmmmmmmmmmmmmmdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddh......`/y///::::::::::::::::::::::://///////" << std::endl
                << "/:::::::::::::--:-------------------::o+````...hdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddmmmdddmdmdddddddddddddddddddddddddddddddds`......so+//:::::::::::::::::::::://///////" << std::endl
                << "//:::::::::::::::-----------------:::+s.```..`sddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddmmmmmmmmmmmmmdmdmmmddddddddddddddddddddddddddddddddd/`.....-y+o//:::::::::::::::::////:////////" << std::endl
                << "/:::::::::::::::-----:----------:::::s:```..`:dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddmmddddddmddmmmdmdddmddddddddddddddddddddddddddddddddddd-......+s++//:::::::::::::::::::://///////" << endl;
}
