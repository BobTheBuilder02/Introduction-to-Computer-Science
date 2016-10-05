//Student name: Daniel Minor
//Date: 9/17/2015
//Homework #: 1
//Problem # 1-8 (Savitch, Problem Solving with C++)
//The source code in this program is my own work and not the work of anyone else. 
//Your signature: Daniel Minor

	#include <iostream>
	using namespace std;
	
	int main()
	{
		int num_of_quarters, num_of_dimes, num_of_nickels, num_of_pennies, val_of_quarters, val_of_dimes, val_of_nickels, val_of_pennies, val_total;
		num_of_quarters = num_of_dimes = num_of_nickels = num_of_pennies = 0;
		cout << "Let's count your change. \n";
		cout << "How many quarters do you have? \n";
		cin >> num_of_quarters;
		val_of_quarters = num_of_quarters * 25;
		cout << "How many dimes do you have? \n";
		cin >> num_of_dimes;
		val_of_dimes = num_of_dimes * 10;
		cout << "How many nickels do you have? \n";
		cin >> num_of_nickels;
		val_of_nickels = num_of_nickels * 5;
		cout << "How many pennies do you have? \n";
		cin >> num_of_pennies;
		val_of_pennies = num_of_pennies * 1;
		val_total = val_of_quarters + val_of_dimes + val_of_nickels + val_of_pennies;
		cout << "You have ";
		cout << num_of_quarters;
		cout << " quarters, ";
		cout << num_of_dimes;
		cout << " dimes, ";
		cout << num_of_nickels;
		cout << " nickels, and ";
		cout << num_of_pennies;
		cout << " pennies. \n";
		cout << "So you have ";
		cout << val_total;
		cout << " cents. \n";
	
		char dummy; //Create Dummy variable to be entered to make program pause before exiting
    cout << "Enter any key to quit." << endl;
    cin >> dummy;
    
		return 0;
	}

