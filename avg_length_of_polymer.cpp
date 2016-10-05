//Student name: Daniel Minor
//Date: 11/4/2015
//Homework # 4
//Problem # (Monte Carlo simulation, average length of polymer)
//average length of polymer = 28 roughly
//The source code in this program is my own work and not the work of anyone else. 
//Your signature:

#include <iostream>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
int main()
{
	double x = 0.0, y = 0.0, distance = 0.0, average_distance, random_theta;
	int chains, min = 0, number_of_simulations;

	cout << "Enter the number of chains in the polymer." << endl;
	cin >> chains;
	cout << "Enter the number of time you would like to run the simulation." << endl;
	cin >> number_of_simulations;

	for (int n = 0; n < number_of_simulations; n++)
	{
		x = y = 0;
		for (int i = 0; i < chains; i++)
		{
			random_theta = ((rand() * 2 * M_PI) / (RAND_MAX + 1));
			x += cos(random_theta);
			y += sin(random_theta);
		}
		distance += sqrt((x*x) + (y*y));
	}
	average_distance = distance / number_of_simulations;
	cout << "The average distance of a " << chains << " polymer after " << number_of_simulations << " simulations is " << average_distance << "." << endl;
	
	char dummy;
  cout << "Enter any key to quit." << endl;
  cin >> dummy;
	return 0;
}

