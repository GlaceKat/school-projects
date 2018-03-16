//#include "Lab2.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {

	string x;
	string quote;
	char key = 'y';

	// Ask user for file and create if it doesn't exist
	cout << "Which file do you want to open?";
	cin >> x;

	ifstream Quote;
	Quote.open(x.c_str());

	if (Quote.fail())
	{
		cout << "No file. Do you want to create a file?";
		cin >> key;
		if (key == 'y')
		{
			ofstream outputFile(x.c_str(), ios::app);
			outputFile << "New file is created";
		}
	}
	else
	{
		cout << "Good to go!" << endl;
		int counter = 0;
		while (Quote.good() && counter < 10) // Get lines and print them out one by one
		{
			getline(Quote, quote);
			cout << quote << endl;
			counter++;
		}

		Quote.close();
	}

	return 0;
}