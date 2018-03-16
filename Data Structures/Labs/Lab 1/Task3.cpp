// This program produces a sales report for DLC, Inc.

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes

struct Product {
	// Production ID numbers
	int id;

	// Number of units sold
	int units;

	// Product Prices
	double prices;

	// Computed Sales Amounts
	double sales;
};


//This void function calculates the total amount of sales for DLC, Inc.
void calcSales(Product productsList[], int num) {
	for (int index = 0; index < num; index++)
		productsList[index].sales = productsList[index].units * productsList[index].prices;
};

//This void function outputs a a title and then lists the product id and its sales.
void showOrder(struct Product productsList[], int num)
{
	cout << "Product Number\tSales\n";
	cout << "----------------------------------\n";
	for (int index = 0; index < num; index++)
	{
		cout << productsList[index].id << "\t\t$";
		cout << setw(8) << productsList[index].sales << endl;
	}
	cout << endl;
}

//This sorts the products in descending order.
void dualSort(struct Product productsList[], int size)
{
	int startScan, maxIndex, tempid;
	double maxValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = productsList[startScan].sales;
		tempid = productsList[startScan].id;
		for (int index = startScan + 1; index < size; index++)
		{
			if (productsList[index].sales > maxValue)
			{
				maxValue = productsList[index].sales;
				tempid = productsList[index].id;
				maxIndex = index;
			}
		}
		productsList[maxIndex].sales = productsList[startScan].sales;
		productsList[maxIndex].id = productsList[startScan].id;
		productsList[startScan].sales = maxValue;
		productsList[startScan].id = tempid;
	}
}


//This void functions outputs the total units sold and total sales.
void showTotals(struct Product productsList[], int num)
{
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < num; index++)
	{
		totalUnits += productsList[index].units;
		totalSales += productsList[index].sales;
	}
	cout << "Total units Sold:  " << totalUnits << endl;
	cout << "Total sales:      $" << totalSales << endl;
}


// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;



int main() {

	Product productsList[NUM_PRODS] = {
		{ 914,842,12.95 },
		{ 915,416,14.95, },
		{ 916,127,18.95 },
		{ 917,514,16.95 },
		{ 918,437,21.95 },
		{ 919,269,31.95 },
		{ 920,97,14.95 },
		{ 921,492,14.95 },
		{ 922,212,16.95 }
	};

	calcSales(productsList, NUM_PRODS);

	dualSort(productsList, NUM_PRODS);

	// Set the numeric output formatting.
	cout << setprecision(2) << fixed << showpoint;

	// Display the products and sales amounts.
	showOrder(productsList, NUM_PRODS);

	// Display total units sold and total sales.
	showTotals(productsList, NUM_PRODS);

	return 0;

}