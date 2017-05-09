#include <iostream>
#include <vector>
#include "computer.h"
#include "game.h"
#include "player.h"

using namespace std;

int main()
{
    double x;
    double y;
	{
			cout << "Please enter the number of rows on your game board: \n";
	    cin >> x;
	    while ((x != (int)x) || (!((x>=4) && (x<=10))))
		{
	        cout << "Please enter an integer between 4 and 10. \n";
	        cin.clear();
	        cin.ignore(1000,'\n');
	        cin >> x;
	    }
	    cout << "Please enter the number of columns on your game board: \n";
	    cin >> y;
	    while ((y != (int)y) || (!((y>=4) && (y<=10))))
		{
	        cout << "Please enter an integer between 4 and 10. \n";
	        cin.clear();
	        cin.ignore(1000,'\n');
	        cin >> y;
	    }
	Game test = *new Game(x,y);
	test.displayBoard();


    return 0;
}

