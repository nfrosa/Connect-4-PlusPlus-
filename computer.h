#ifndef computer_h
#define computer_h
#include <iostream>
#include <vector>
using namespace std;

class Computer: public Player{
	private:
		string name;
		char ch;
		//either x or o
		int difficulty;
		//0 = easy, 1 = normal, 2 = hard
	public:
		 Computer(string n, char s, int d) {
			name = n;
			shape = s;
			difficulty = d;
		 }
 		void play(vector<vector <char> >& v, int playerdrop);
 		int getDifficulty();
 		char getShape();
 		string getName();
};

#endif