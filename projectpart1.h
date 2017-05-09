#ifndef projectpart1_h
#define projectpart1_h

#include <iostream>
#include <vector>
#include "projectpart2.h"

using namespace std;

	class Game
	{
	private:
	    int rows;
	    int columns;
	    int numPlayers;
	    std::vector<std::vector<string> > board;
	public:
		Game(int r, int c)
		{
		        std::vector<std::vector<string> > board (r, std::vector<string> (c,"|_|"));
		        rows = r;
		        columns = c;
		        numPlayers = PlayersMenu();
		       void getGameMode();
		       void displayBoard( board);
		}
	    void getGameMode()
		{
	        int x = 0;
	        int y = 0;
	        cout << "Choose Game Mode: \n";
	        cout << "1. Classic - Best of number of rounds you choose. The first to get four in a row wins the round.\n";
	        cout << "2. Continuous - Play until the board is filled. The player with the greater number of four in a rows wins. \n";
	        cin >> x;
	            while ((x != (int)x) || (!((x>=1) && (x<=2))))
				{
			      	cout << "Please enter an integer choice 1 or 2. \n";
			        cin.clear();
			        cin.ignore(1000,'\n');
			        cin >> x;
			    }
			if (x == 1)
			{
	            cout << "Choose the number of rounds you wish to play: \n";
	            cout << "1. One Round\n";
	            cout << "2. Three Rounds\n";
	            cout << "3. Five Rounds\n";
	            cin >> y;
					while ((y != (int)y) || (!((y>=1) && (y<=3))))
					{
			      		cout << "Please enter an integer between 1 and 3. \n";
			        		cin.clear();
			        		cin.ignore(1000,'\n');
			        		cin >> y;
			    	}
	            if (y == 1)
				{
	                cout << "You have chosen to play one round of Connect4++\n";
	            }
	            else {
	                if (y == 2)
					{
	                    cout << "You have chosen to play three rounds of Connect4++\n";
	                }
	                else
					{
	                    if (y == 3)
						{
	                        cout << "You have chosen to play five rounds of Connect4++\n";
	                    }
	                }
	            }
	        }
	        else
			{
	            if (x == 2)
				{
	                cout << "You chose the continuous game.\n";
	            }
	        }
		}
    void displayBoard(std::vector<std::vector<string> > game)
	{
        for (int i = 0; i < rows; ++i)
		{
            for (int j = 0; j < columns; ++j)
			{
                cout << game[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void check(Player one, Player two)
	{
        bool a = checkRows(board, one.shape);
        bool b = checkColumns(board, one.shape);
        bool c = checkDiagonals(board, one.shape);
        if ((a == true) && (b == true) && (c == true))
		{
            displayResult(one);
        }
        else
		{
            bool d = checkRows(board, two.shape);
            bool e = checkColumns(board, two.shape);
            bool f = checkDiagonals(board, two.shape);
            if ((d == true) && (e == true) && (f == true))
			{
                displayResult(two);
            }
        }
    }
    bool checkRows(std::vector<std::vector<string> > game, string shape)
	{
        int num = 0;
        bool rows = false;
        for (int i = 0; i < columns; ++i)
		{
            for (int j = 0; j < rows; ++j)
			{
                string temp = game[j][i];
                if (temp == shape)
				{
                    ++num;
                    if (num == 4)
					{
                        rows = true;
                    }
                }
            }
        }
        return rows;
    }
    bool checkColumns(std::vector<std::vector<string> > game, string shape)
	{
        int num = 0;
        bool columns = false;
        for (int i = 0; i < rows; ++i)
		{
            for (int j = 0; j < columns; ++j)
			{
                string temp = game[i][j];
                if (temp == shape)
				{
                    ++num;
                    if (num == 4)
					{
                        columns = true;
                    }
                }
            }
        }
        return columns;
    }
    bool checkDiagonals(std::vector<std::vector<string> > game, string shape)
	{
        int num = 0;
        bool diagonals = false;
        int c = 0;
        for (int i = 0; i < rows; ++i)
		{
            string temp = game[i][c];
            if (temp == shape)
			{
                ++num;
                if (num == 4)
				{
                    diagonals = true;
                }
            }
            ++c;
        }
        if (diagonals == false)
		{
            c = columns;
            num = 0;
            for (int i = 0; i < rows; i++)
			{
                string temp = game[i][c];
                if (temp == shape)
				{
                    ++num;
                    if (num == 4)
					{
                        diagonals = true;
                    }
                }
                --c;
            }
        }
        return diagonals;
    }
    void displayResult(Player temp)
	{
        cout << "Congratulations " << temp.name << ". You are the winner of this game.\n";
    }
    bool checkFill (vector<vector<string> > game)
	{
        bool checkFill = false;

        for (int i= 0; i<rows; i++)
		{
            for (int j=0; j<columns;j++)
			{
                if (game[i][j] == "|_|")
				{
                    checkFill = false;
                    break;
                }
            }
        }
        return checkFill;
    }


    void checkStatus (vector<vector<string> > game, Player one, Player two)
	{
        bool checkStatus = false;

        if ((checkRows(game, one.getShape()) == true) || (checkColumns(game, one.getShape()) == true) || ((checkDiagonals(game, one.getShape())) == true))
		{
            checkStatus = true;
            cout << "Congratulations! " << one.getName() << "won. " << endl;
        }
        else
		{
            if ((checkRows(game, two.getShape()) == true) || (checkColumns(game, two.getShape()) == true) || ((checkDiagonals(game, two.getShape())) == true))
			{
            	checkStatus = true;
            	cout << "Congratulations! " << two.getName() << "won. " << endl;
            }
        }
    }
    int PlayersMenu()
	{
        int a = 0; //Player choice
        int b = 0; //player mode
        cout << "Choose the PLAYERS of the game: \n";
        cout << "1. Computer vs Computer\n";
        cout << "2. Player vs Computer\n";
        cout << "3. Player 1 vs Player 2\n";
        cin >> a;
        	while ((a != (int)a) || (!((a>=1) && (a<=3))))
			{
		      	cout << "Please enter an integer between 1 and 3. \n";
		      	cin.clear();
		      	cin.ignore(1000,'\n');
		     	cin >> a;
		   	}
        if (a == 1)
		{
            cout << "You have chosen to play Player 1 vs Player 2!!!\n";
            b = 2;
        }
        else
		{
            if (a == 2)
			{
                cout << "You have chosen to play Player vs Computer\n";
                b = 1;
            }
            else
			{
                if (a == 3)
				{
                    cout << "You have chosen to play Computer vs Computer\n";
                    b = 0;
                }
            }
        }
        return b;
    }
    void createPlayers(int x)
	{
        int c = x - 1;
        Player one;
        one.setType(c);
        --c;
        Player two;
        two.setType(c);
    }
};
#endif /* projectpart1_h */



