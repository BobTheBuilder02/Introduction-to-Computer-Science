//Name: Daniel Minor
//Date: 12/3/2015
//Homework # 15
//Problem # (Savitch problem 10-3)
//The source code in this program is my own work and not the work of anyone else. 
//Your signature:

#include <iostream>
using namespace std;

//Create CDAccount object
class CDAccount
{
public:
	CDAccount(double balance, double interest_rate, int term); //constructor
	CDAccount(); //Default constructor
  
  //functions to access private variables, member functions
	double InitialBalance();
	double InterestRate();
	int Term();
	double BalanceAtMaturity();
	void output(ostream& out);
	void input(istream& in);

private:
//member variables
	double balance_at_maturity;
	double balance;
	double interest_rate;
	double rate_fraction;
	double interest;
	int term;
	void check_balance(); //Used to check if account has a valid positive balance. Not always nescessary. For our purposes it's defined, but unused.
};

int main()
{
	char dummy;

	CDAccount account = CDAccount(100.0, 10.0, 6);
	
	cout << "CD Account interest rate: " << account.InterestRate() << endl;
	cout << "CD Account initial balance: " << account.InitialBalance() << endl;
	cout << "CD Account balance at maturity is: " << account.BalanceAtMaturity() << endl;
	cout << "CD Account term is: " << account.Term() << " months" << endl;
	account.output(cout);
	cout << "Enter CD initial balance, interest rate, " << " and term:" << endl;
	account.input(cin);
	cout << "CD Account interest rate: " << account.InterestRate() << endl;
	cout << "CD Account initial balance: " << account.InitialBalance() << endl;
	cout << "CD Account balance at maturity is: " << account.BalanceAtMaturity() << endl;
	cout << "CD Account term is: " << account.Term() << " months" << endl;
	account.output(cout);
	cout << endl;

	cout << "Enter any character and press return to terminate." << endl;
	cin >> dummy;
	return 0;
}

double CDAccount::InitialBalance()
{
	return balance;
}

double CDAccount::InterestRate()
{
	return interest_rate;
}

int CDAccount::Term()
{
	return term;
}

void CDAccount::output(ostream& out)
{
	out << "CD Account interest rate: " << InterestRate() << endl;
	out << "CD Account initial balance: " << InitialBalance() << endl;
	out << "CD Account balance at maturity is: " << BalanceAtMaturity() << endl;
	out << "CD Account term is: " << Term() << " months" << endl;
}

void CDAccount::input(istream& in)
{
	in >> balance >> interest_rate >> term;
}

double CDAccount::BalanceAtMaturity()
{
	rate_fraction = interest_rate / 100.0;
	interest = balance * rate_fraction * (term / 12.0);
	balance_at_maturity = balance + interest;
	return balance_at_maturity;
}

CDAccount::CDAccount()
{
	//Default account details go here.
}

CDAccount::CDAccount(double balance, double interest_rate, int term)
{
	this->balance = balance;
	this->interest_rate = interest_rate;
	this->term = term;
}

void CDAccount::check_balance()
{
	if((balance < 0) || (interest_rate < 0) || (term < 0))
	{
		cout << "Balance, Interest, and/or Term given is invalid." << endl;
		cout << "Aborting program." << endl;
		exit(1);
	}
}

