//Student name: Daniel Minor
//Date: 10/6/2015
//Homework #: 1m
//Problem # lines on grid
//[sample size = 100]Probability(line from (0,0) to (x,y) does not hit any intermediate points)= 54/100 - 75/100
//[sample size = 100000]Probability(line from (0,0) to (x,y) does not hit any intermediate points)= ~60800/100000
//Exact probability = 608383/1000000
//The source code in this program is my own work and not the work of anyone else. 
//Your signature:
//The use of functions is utilized in this program. The tutor taught me how to use them.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

//Function declaration
int probability(int declared_sample_space);

int main()
{
	cout << "Estimated probability that the line does not hit" << endl;
	cout << "any intermediate points using a sample size of 100 is..." << endl;
	cout << probability(100) << "/100" << endl; // function call
	
	cout << "Estimated probability that the line does not hit" << endl;
	cout << "any intermediate points using a sample size of 100000 is..." << endl;
	cout << probability(100000) << "/100000" << endl; //function call
	
	int x, y, common_term=2, counter=0, sample_space=0, counter_inverse;
	
	for(x = 1; x <= 1000; x++)
	{
		for(y = 1; y <= 1000; y++)
		{
			if(x == 1 || y == 1)
			{
				sample_space++;
				continue;
			}
			else
			{
				while(common_term <= x && common_term <= y)
				{
					if(x%common_term==0 && y%common_term==0)
					{
						counter++;
						break;
					}
					else
					{
						common_term++;
					}
				}
				sample_space++;
				common_term = 2;
			}
		}
	}
	counter_inverse = sample_space - counter;
	
	cout << "Exact probability that a line does not hit any intermediate points is..." << endl;
	cout << counter_inverse << "/" << sample_space << endl;
	
	char dummy;
	cout << "Enter any key to quit..." << endl;
	cin >> dummy;
	
	return 0;
}

//Function definition
int probability(int declared_sample_space)
{
	int x, y, common_term=2, counter=0, sample_space=0, counter_inverse;
	
	srand(time(0));
	while(sample_space < declared_sample_space)
	{
		do
		{
			x = rand();
		}
		while(x > 32000);
		x = x%1000 + 1;
		
		do
		{
			y = rand();
		}
		while(y > 32000);
		y = y%1000 + 1;
		
		while(common_term <= x && common_term <= y)
		{
			if(x%common_term==0 && y%common_term==0)
			{
				counter++;
				break;
			}
			else
			{
				common_term++;
			}
		}
		sample_space++;
		common_term = 2;
	}
	counter_inverse = declared_sample_space - counter;
	return counter_inverse;
}

