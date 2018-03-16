#include <iostream>
#include <iomanip>
#include <fstream>
#include "Product.h"
#include <string>

using namespace std;

int main() {

	Product prodList;

	// Read the data into the products
	prodList.readFile();

	// Calculate sales information
	prodList.calcSales();

	// Sort the products
	prodList.dualSort();

	// Set the numeric output formatting.
	cout << setprecision(2) << fixed << showpoint;

	// Display the products and sales amounts.
	prodList.showOrder();

	// Display total units sold and total sales.
	prodList.showTotals();

	return 0;

}