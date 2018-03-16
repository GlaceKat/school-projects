#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Product.h"

using namespace std;

// Display products and sale amounts
void Product::showOrder()
{
	cout << "Product Number\tSales\n";
	cout << "----------------------------------\n";
	for (int index = 0; index < realNum; index++)
	{
		cout << id[index] << "\t\t$";
		cout << setw(8) << sales[index] << endl;
	}
	cout << endl;
}

// Sort the products
void Product::dualSort()
{
	int startScan, maxIndex, tempid;
	double maxValue;

	for (startScan = 0; startScan < (realNum - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = sales[startScan];
		tempid = id[startScan];
		for (int index = startScan + 1; index < realNum; index++)
		{
			if (sales[index] > maxValue)
			{
				maxValue = sales[index];
				tempid = id[index];
				maxIndex = index;
			}
		}
		sales[maxIndex] = sales[startScan];
		id[maxIndex] = id[startScan];
		sales[startScan] = maxValue;
		id[startScan] = tempid;
	}
}

// Show sales totals
void Product::showTotals()
{
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < realNum; index++)
	{
		totalUnits += units[index];
		totalSales += sales[index];
	}
	cout << "Total units Sold:  " << totalUnits << endl;
	cout << "Total sales:      $" << totalSales << endl;
}

// Calculate sales information
void Product::calcSales() {
	for (int index = 0; index < realNum; index++)
		sales[index] = units[index] * prices[index];
};

// Read data
void Product::readFile() {
	int index = 0;
	string temp; // Temp variable to bypass line labels

	string fileName;
	cout << "What is the name of the file you would like to input?" << endl;
	cin >> fileName;

	fstream prodData;

	prodData.open(fileName, ios::in);
	prodData.get();

	if (prodData.good()) {
		while (!prodData.eof() && index < NUM_PRODS) { //got help with syntax from someone outside of class
			prodData >> temp >> id[index];
			prodData >> temp >> units[index];
			prodData >> temp >> prices[index];
			index++;
		}
	}
	else if(prodData.eof())
	{
		cout << "Empty data file." << endl;
	}
	else
	{
		cout << "Invalid data file." << endl;
	}

	realNum = index; // Set realNum to number of products read from file

	prodData.close();
};