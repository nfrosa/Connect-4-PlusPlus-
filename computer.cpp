#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Computer: public Player
{
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

void Computer::play(vector<vector <string> >& v, int playerdrop)
{
	/*play drops the computer's piece based on difficulty. an easy mode would drop
	the piece in a random location on the gameboard, a medium difficulty would drop
	the next piece close to where the player drops their piece and attempt to make four
	in a row when possible, a hard difficulty will actively try to keep the player
	from winning and try to win.*/

	if(difficulty == 0)
	{
			//drops next gamepiece anywhere
			int nextpos;
			bool validposition = false;
			int nextvectorindex;
			do
			{
			nextvectorindex = rand() % (v.size()+1);
			for(int i=0;i<v/*[][nextvectorindex]*/.size();i++)
			{
				if(v[i][nextvectorindex]!= ' ')
				{
				nextpos = i-1;
				validposition = true;
				}
			}
		} while (!validposition);
			v[nextpos][nextvectorindex] = shape;
	}

	if(difficulty == 1)
	{
		//drops next gamepiece near player
		int nextvectorindex;
		bool validposition = false;
		//finding the range where to drop the piece
		int upperrange;
		int lowerrange;
		int x;
		if(v[playerdrop+2][0] ==NULL)
		{
			playerdrop - v.size() = upperrange;
			lowerrange = upperrange - 2;
			if(lowerrange<0)
			{
				lowerrange  = v.size() + lowerrange;
			}
		}
		else
		{
			upperrange = playerdrop + 2;
			lowerrange = playerdrop - 2;
			if(lowerrange<0)
			{
				 lowerrange  = v.size() + lowerrange;
			}
		}
		do
		{
			nextvectorindex = rand() % upperrange + lowerrange;
				for(int i=0;i<v/*[0][nextvectorindex]*/.size();i++)
				{
					if(v[i][nextvectorindex]!= ' ')
					{
					   x = i-1;
					   validposition = true;
					   break;
	  				}
				}
		} while (!validposition);
		v[x][nextvectorindex] = shape;
	}

	if(difficulty == 2)
	{
		/* first check if player has 2 or 3 in a row at any point. 3 in a row is checked
		first,and then 2 in a row. if neither of those are true, then drop the next piece
		within a radius of 1 of the last piece dropped. also if cpu is about to make
		four in a row, it should put that as a priority, as it will win the game even if
		the player also has 3 in a row.
		therefore...
		1 - 3 in a row (cpu)
		2 - 3 in a row (player)
		3 - 2 in a row (cpu)
		4 - 2 in a row (player)
		5 - near player piece
		REMEMBER: matrix[row][column]
		*/
		//FIND THE MAX AMOUNT OF CONTINUOUS PIECES OF ONE COLOR
		//finding if there's 3 in a row horizontally
		int consecutive = 1;
		int nextx=-1;
		int nexty=-1;
		//checking if player has 3 in a row horizontally
		for (int i=0;i<v.size();i++)
		{
			consecutive = 1;
			for (int j=0;j<v[0].size();j++)
			{
				if (v[i][j]==ch)
				{
				   consecutive++;
				}
				 if (consecutive == 3)
				 	break;
			}
			if (consecutive == 3)
			{
				//checking if sides are vacant and something can be placed on them
				if ((j-3)>=0&&v[i][j-3]==' '&& v[i+1][j-3]!= ' ')
				{
					nextx=i;
					nexty=j-3;
					break;
				}
				else if ((j+1)>=v.size()&&v[i][j+1]==' '&& v[i+1][j+1]!= ' ')
				{
					nextx=i;
					nexty=j+1;
					break;
				}
			}
		}
		//checking if opponent has 3 in a row horizontally
		if(nextx==-1&&nexty==-1)
		{
			for (int i=0;i<v.size();i++)
			{
				consecutive = 0;
				for (int j=0;j<v[0].size();j++)
				{
					if (v[i][j]!=ch&&v[i][j]!=' ')
					{
					   consecutive++;
					}
				 	if (consecutive == 3)
				 	{
					 	break;
					}
				}
				if (consecutive == 3)
				{
					//checking if sides are vacant
					if ((j-3)>=0&&v[i][j-3]==' '&& v[i+1][j-3]!= ' ')
					{
						nextx=i;
						nexty=j-3;
						break;
					}
					else if ((j+1)>=v.size()&&v[i][j+1]==' '&& v[i+1][j+1]!= ' ')
					{
						nextx=i;
						nexty=j+1;
						break;
					}
				}
			}
		}
		//finding if there's 3 in a row vertically
		//self
		if(nextx==-1&&nexty==-1)
		{
			for (int i=0;i<v.size();i++)
			{
				consecutive = 0;
				for (int j=0;j<v[0].size();j++)
				{
					if (v[j][i]==ch)
					{
					   consecutive++;
					}
					if (consecutive == 3)
					{
					 	break;
					}
				}
				if (consecutive == 3)
				{
					//checking if top is vacant
					if ((j-3)>=0&&v[j-3][i]==' ')
					{
						nextx=j-3;
						nexty=i;
						break;
					}
				}
			}
		}
		//opponent
		if(nextx==-1&&nexty==-1)
		{
			for (int i=0;i<v.size();i++)
			{
				consecutive = 0;
				for (int j=0;j<v[0].size();j++)
				{
					if (v[j][i]!=ch||v[j][i]==' ')
					{
					   consecutive++;
					}
					if (consecutive == 3)
					{
					 	break;
					}
				}
				if (consecutive == 3)
				{
					//checking if sides are vacant
					if ((j-3)>=0&&v[i][j-3]==' ')
					{
						nextx=j-3;
						nexty=i;
						break;
					}
				}
			}
		}
		//finding if there's 3 in a row increasing diagonally
		//self
		if(nextx==-1&&nexty==-1)
		{
			for (int i=0;i<v.size();i++)
			{
				consecutive = 0;
				for (int j=0;j<v[0].size();j++)
				{
					if (v[j][i]==ch)
					{
						consecutive++;
						for (int k=i-1, l = i+1;k>=0, l<v[0].size();k--, l++)
						{
							if (v[k][l]==ch)
							{
							   consecutive++;
							}
							if (consecutive == 3)
							{
								if ((k-1)>=0&&(l+1)<=v[0].size()&&v[k-1][l+1]==' '&&v[k][l+1]!=' ')
								{
									nextx=k-1;
									nexty=l+1;
								}
							break;
					  		}
						}
  			   		}
					if (consecutive == 3)
					{
				 	   break;
					}
				}
				if (consecutive == 3)
				{
				    break;
				}
			  }
		}
		//finding a row decreasing diagonally.
		if(nextx==-1&&nexty==-1)
		{
			for (int i=0;i<v.size();i++)
			{
				consecutive = 0;
				for (int j=0;j<v[0].size();j++)
				{
					if (v[j][i]==ch)
					{
						consecutive++;
						for (int k=i+1, l = i+1;k>v.size(), l<v[0].size();k++, l++)
						{
							if (v[k][l]==ch)
							{
							   consecutive++;
							}
							if (consecutive == 3)
							{
								if ((k+1)<v.size()&&(l+1)<v[0].size()&&v[k+1][l+1]==' '&&v[k][l+1]!=' ')
							    {
									nextx=k+1;
									nexty=l+1;
								}
							break;
					  		}
						}
  			   		}
					if (consecutive == 3)
					{
				 	   break;
					}
				}
			}
			if (consecutive == 3)
			{
			    break;
			}
		}
		//opponent
		if(nextx==-1&&nexty==-1)
		{
			for (int i=0;i<v.size();i++)
			{
				consecutive = 0;
				for (int j=0;j<v[0].size();j++)
				{
					if (v[j][i]!=ch&&v[j][i]!= ' ')
					{
						consecutive++;
						for (int k=i-1, l = i+1;k>=0, l<v[0].size();k--, l++)
						{
							if (v[j][i]!=ch&&v[j][i]!= ' ')
							{
							   consecutive++;
							}
							if (consecutive == 3)
							{
								if ((k-1)>=0&&(l+1)<=v[0].size()&&v[k-1][l+1]==' '&&v[k][l+1]!=' ')
								{
									nextx=k-1;
									nexty=l+1;
								}
							break;
					  		}
						}
  			   		}
					if (consecutive == 3)
					{
				 	   break;
					}
				}
			}
			if (consecutive == 3)
			{
			    break;
			}
		}
		//finding a row decreasing diagonally.
		if(nextx==-1&&nexty==-1)
		{
			for (int i=0;i<v.size();i++)
			{
				consecutive = 0;
				for (int j=0;j<v[0].size();j++)
				{
					if (v[j][i]!=ch&&v[j][i]!= ' ')
					{
						consecutive++;
						for (int k=i+1, l = i+1;k>v.size(), l<v[0].size();k++, l++)
						{
							if (v[j][i]!=ch&&v[j][i]!= ' ')
							{
							   consecutive++;
							}
							if (consecutive == 3)
							{
								if ((k+1)<v.size()&&(l+1)<v[0].size()&&v[k+1][l+1]==' '&&v[k][l+1]!=' ')
								{
									nextx=k+1;
									nexty=l+1;
								}
							break;
					  		}
						}
  			   		}
					if (consecutive == 3)
					{
				 	   break;
					}
				}
			}
			if (consecutive == 3)
			{
			    break;
			}
		}
	}
}

string Computer::getShape()
{
	return shape;
}

string Computer::getName()
{
	return name;
}

int Computer::getDifficulty()
{
	return difficulty;
}
