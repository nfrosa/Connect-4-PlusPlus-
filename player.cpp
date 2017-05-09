#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//Player class
//The parent class for both types of C4 Players (users and ai)

class Player
{
    //private but can be accessed by derived classes
    //protected:
	public:
    string name;
    string shape;
    string type;
    //returns Player's name

    string getName();

     //returns the character player is using
     string getShape();

    //function to set name of player
    void setName(string n);

    //function to set the character player uses
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

string Player::getName()
{
   return name;
}

string Player::getShape()
{
	return shape;
}

void Player::setName(string n)
{
	name = n;
}
void Player::setShape(char c)
{
    shape = c;
}

//User class
class Human: public Player
{
	public:
    //string name and char shape declared in player class
    //Default constructor for user
    Human()
    {
        shape = 'O';
        name = "Jonathan Liu";
    }
    //Constructor of User; Sets input name as user object's name, and associated character
    Human(string n, string c)
    {
        shape =c;
        name = n;
    }
};