//#include "Lab2Task2.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	const int NUM_DIVS = 3;           // Number of divisions
	const int NUM_QTRS = 4;           // Number of quarters
	double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
	double totalSales = 0;            // To hold the total sales.
	int div, qtr;                     // Loop counters.
	string x;
	char key = 'y';

	cout << "Where do you want to write the data to?";
	cin >> x;

	ifstream data;
	data.open(x.c_str());
	if (data.fail())
	{
		cout << "File not Found. Do you want to create a file?";
		cin >> key;
		cin.clear();
		cin.ignore(100, '\n');
		if (key == 'y')
		{
			ofstream outputFile(x.c_str(), ios::app);
			cout << "This program will calculate the total sales of\n";
			cout << "all the company's divisions.\n";
			cout << "Enter the following sales information:\n\n";
			// Nested loops to fill the array with quarterly
			// sales figures for each division.
			int sum = 0;
			for (div = 0; div < NUM_DIVS; div++) {
				for (qtr = 0; qtr < NUM_QTRS; qtr++) {
					cout << "Division " << (div + 1);
					cout << ", Quarter " << (qtr + 1) << ": $";
					cin >> sales[div][qtr];
					sum = sum + sales[div][qtr];

				}
				cout << endl; // Print blank line.
			}

			outputFile << fixed << showpoint << setprecision(2);
			outputFile << "The sales for the company is: $" << endl;
			outputFile << "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;


			// Nested loops to display the quarterly sales figures for each division.
			for (div = 0; div < NUM_DIVS; div++) {
				outputFile << div + 1 << "\t";
				for (qtr = 0; qtr < NUM_QTRS; qtr++) {
					outputFile << "$" << sales[div][qtr] << "\t";
				}
				outputFile << endl; // Print blank line.
			}
			totalSales = sum;
			outputFile << endl;
			outputFile << "The total sales for the company are: $";
			outputFile << totalSales << endl;

			outputFile.close();
		}
	}
	else
	{
		ofstream data;
		data.open(x.c_str(), ios::app);
		cout << "File found!" << endl;
		cout << "This program will calculate the total sales of\n";
		cout << "all the company's divisions.\n";
		cout << "Enter the following sales information:\n\n";
		// Nested loops to fill the array with quarterly
		// sales figures for each division.
		int sum = 0;
		for (div = 0; div < NUM_DIVS; div++) {
			for (qtr = 0; qtr < NUM_QTRS; qtr++) {
				cout << "Division " << (div + 1);
				cout << ", Quarter " << (qtr + 1) << ": $";
				cin >> sales[div][qtr];
				sum = sum + sales[div][qtr];
			}
			cout << endl; // Print blank line.
		}

		data << fixed << showpoint << setprecision(2);
		data << "The sales for the company is: $" << endl;
		data << "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;

		// Nested loops to display the quarterly sales figures for each division.
		for (div = 0; div < NUM_DIVS; div++) {
			data << div + 1 << "\t";
			for (qtr = 0; qtr < NUM_QTRS; qtr++) {
				data << "$" << sales[div][qtr] << "\t";
			}
			data << endl; // Print blank line.
		}
		totalSales = sum;
		data << endl;
		data << "The total sales for the company are: $";
		data << totalSales << endl;
		data.close();
	}
}
