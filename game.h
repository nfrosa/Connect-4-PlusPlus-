#ifndef game_h
#define game_h
#include <iostream>
#include <vector>
using namespace std;

class Game
	{
	private:
	    int rows;
	    int columns;
	    int numPlayers;
	    vector<vector<string> > board;
	public:
		Game(int r, int c);
		void getGameMode();
		void displayBoard(std::vector<std::vector<string> > game);
		void check(Player one, Player two);
		bool checkRows(std::vector<std::vector<string> > game, string shape);
		bool checkColumns(std::vector<std::vector<string> > game, string shape);
		bool checkDiagonals(std::vector<std::vector<string> > game, string shape);
		void displayResult(Player temp);
		bool checkFill (vector<vector<string> > game);
		void checkStatus (vector<vector<string> > game, Player one, Player two);
		int PlayersMenu();
		void createPlayers(int x);
	}
#endif