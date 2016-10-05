//Names of student: Daniel Minor
//Date: 10/28/2015
//Homework # 7c
//Problem # Create pseudo-random numbers in interval [min, max] 

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

//fuction declaration
int random(int min, int max);

int main()
{ 
	int number_of_simulations = 10000000; 
	int histogram[240000] = {0};
	int min, max; 
	cout << "Enter the min and max for the interval [min, max].  The program will output pseudo-random numbers in this interval." << endl; 
	cout << "For the purposes of this program, both min and max must be in the interval [0,230000]" << endl; 
	cin >> min >> max;
	int random_num = 0; 
	
	for (int i = 0; i< number_of_simulations; i++ ) 
	{ 
		random_num = random(min, max);
		histogram[random_num]++;
	} 
	
	for (int i = min; i < min + 10; i++) 
	{ 
		cout << "histogram[" << i << "] =" << histogram[i] << endl;
	} 
	
	cout << endl;
	
	for (int i = max - 10; i <= max ; i++) 
	{ 
		cout << "histogram[" << i << "] =" << histogram[i] << endl; 
	} 
  
	char dummy; 
	cin >> dummy; 
	return 0 ;

}

//Function definition
random(int min, int max)
{
	//There are extra ints declared here so that I can come back and optimize the program later
	int range_adjustment, rand_step_one, rand_step_two, optimum_finder;
	int produced_rand = 0;
	
	range_adjustment = (max - min);
	
	if(range_adjustment <= RAND_MAX)
	{
		int remainder = RAND_MAX%(range_adjustment + 1);
		do{
			produced_rand=rand();
		}while((produced_rand < remainder));
		return min+(produced_rand%(range_adjustment+1));
	}
	else
	{
		do{
			produced_rand = (rand())*((range_adjustment/RAND_MAX)+1)+random(0,(range_adjustment/RAND_MAX));
		}while(produced_rand > range_adjustment);
	}
	return (produced_rand + min);
}

