#ifndef PRODUCT_H
#define PRODUCT_H

class Product {

public:

	void calcSales();
	void showOrder();
	void dualSort();
	void showTotals();
	void readFile(); //getter; this function gets the data from the text file

private:
	// NUM_PRODS is the maximum number of products produced.
	static const int NUM_PRODS = 9;
	int realNum; // Actual number of products read from file
	int id[NUM_PRODS]; //id of the product
	int units[NUM_PRODS]; //number of units
	double prices[NUM_PRODS]; //price of product
	double sales[NUM_PRODS]; //total sales of product

};

#endif