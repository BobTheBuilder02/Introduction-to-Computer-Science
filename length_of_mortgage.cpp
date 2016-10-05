//Student name: Daniel Minor
//Date: 10/12/2015
//Homework #: 3
//Problem:  length of mortgage
//numb. of months= 244 , last payment = $1108.06
//The source code in this program is my own work and not the work of anyone else. 
//Your signature:

#include <iostream>
#include <cmath>

#define initial_mortgage 240000
#define initial_down_payment 40000
#define first_rate (.06/12+1)
#define second_rate (.07/12+1)
#define principle 1500

int main()
{
	int time_month = 1;
	double value = initial_mortgage - initial_down_payment;
	
		for(time_month; value > 1500 * second_rate; time_month++)
		{
			if(time_month <= 36)
			{
				value = value * first_rate - principle;
			}
			else
			{
				value = value * second_rate - principle;
			}
		}
	value = value * second_rate;
	std::cout << "The final payment is $"<< value << std::endl;	
	std::cout << "The number of months it takes to pay off the mortgage is "<< time_month << "." << std::endl;
	
	char dummy;
    std::cout << "Enter any key to quit." << std::endl;
    std::cin >> dummy;
    
	return 0;
}

