//Name: Daniel Minor
//Date: 11/23/2015
//Homework # 11
//Problem # (Savitch problem 7-6) 
//The source code in this program is my own work and not the work of anyone else. 
//Your signature:                             
//
//

#include <iostream>
#include <fstream>
using namespace std;

void swap(int& a, int& b); //arguments must be call by reference so the values change outside of function call.
void input(int array[], int& array_size); //Reads in input from an external file.
void output(int array[], int array_size); //Outputs sorted values to external file
void insertion_sort(int array[], int array_size); //sorts the values.

int main()
{
	int array[240000], array_size;
  
	input(array, array_size);
	insertion_sort(array, array_size);
	output(array, array_size);
	
	char dummy;
    cout << "Enter any key to quit." << endl;
    cin >> dummy;
    return 0;
}

void swap(int& a, int& b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	return;
}

void input(int array[], int& array_size)
{
	ifstream incoming_data; //declare input stream
	incoming_data.open("input.txt"); //opens file named "input.txt"
	
	if(incoming_data.fail()) //checks to see if file opening fails.
	{
		cout << "Error: Could not open file" << endl;
		char dummy;
    	cout << "Enter any key to quit." << endl;
    	cin >> dummy;
		exit(1);
	}
	
	array_size=0;
	
	while(!incoming_data.eof()) //checks to make sure that the incoming data is not the end of file
	{
		incoming_data >> array[array_size]; //puts data into the array
		array_size++; //increments array size so that the next incoming data will go into the next spot in the array.
	}
	array_size--; //decrements the array size by 1, because arrays start at 0.
	incoming_data.close(); // closes steam
	return;
}

void output(int array[], int array_size)
{
	ofstream outgoing_data; //declaring output stream
	outgoing_data.open("output.txt"); //create a new file named "output.txt"
	
	if(outgoing_data.fail()) //checks to make sure file opens
	{
		cout << "Error: Could not open file" << endl;
		char dummy;
    	cout << "Enter any key to quit." << endl;
    	cin >> dummy;
		exit(1);
	}
	for(int i=0; i < array_size; i++)
	{
		outgoing_data << array[i] << endl; //puts each element of sorted array into the external file.
	}
	outgoing_data.close(); //closes stream
	return;
}

void insertion_sort(int array[], int array_size) //Insertion Sorting algorithm with 
{
	for(int i=1; i < array_size; i++) 
	{
		int mover = i - 1; //decrements mover by 1
		while((mover >= 0) && (array[mover]>array[mover+1]))//checks if values are out of order, if true, then swaps
		{
			swap(array[mover],array[mover + 1]); 
			mover--;
		}
	}
	return;
}

