#ifndef player_h
#define player_h
#include <iostream>
#include <vector>
using namespace std;
class Player
{
	public:
    string name;
    string shape;
    string type;
    string getName();
    string getShape();
    void setName(string n);
    void setShape(char c);
    string getType()
	{
        return type;
    }
    void setType(int x)
	{
        int y = x - 1;
        if (y <= 0)
		{
            type = "Computer";
        }
        if (y >= 1)
		{
            type = "Human";
        }
    }
};
#endif