//Student name: Daniel Minor
//Date: 9/21/2015
//Homework #: 1c
//Problem # Putting rational number in lowest terms
//The source code in this program is my own work and not the work of anyone else. 
//Your signature: Daniel Minor

#include <iostream>
using namespace std;

int main()
{
	int p, q, divisor=2;
	
	cout << "We are going to put a rational number in lowest terms." << endl;
	cout << "Enter the numerator and then press enter." << endl;
	cin >> p;
	cout << "Enter the denominator and then press enter." << endl;
	cin >> q;
	cout << "The rational number you entered is..." << endl;
	cout << p << "/" << q << "." << endl;
  
	while(divisor <= p && divisor <= q)
	{
		if(p%divisor==0 && q%divisor==0)
		{
			p/=divisor;
			q/=divisor;
		}
		else
		{
			divisor++;
		}
	}
	cout << "The rational number you entered in lowest terms is..." << endl;
	cout << p << "/" << q << endl;
  
  char dummy;
  cout << "Press any key to exit" << endl;
  cin >> dummy;
  return 0;
}

