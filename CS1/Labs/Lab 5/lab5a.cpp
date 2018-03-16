#include <iostream>
using namespace std;

int maxValue(int a, int b) {  //This function returns the maximum value of two integers.
    
    if  (a > b)
        return a;
    else
        return b;

}

int minValue(int a, int b){  //This function returns the minimum value of two integers.
    
    if (a < b)
        return a;
    else
        return b;
    
}

int main() {
    
    int firstInt = 0; //First integer
    int secondInt = 0; //Second integer
    int minimum; //Value to store minimum  of two integers
    int maximum; //Value to store maximum of two integers
    
    cout << "Input an integer: ";
    cin >> firstInt;
    cout << "Input a second integer: ";
    cin >> secondInt;
    
    minimum = minValue(firstInt,secondInt);
    maximum = maxValue(firstInt,secondInt);
    
    cout << "The minimum value is " << minimum << "!" << endl;
    cout << "The maximum value is " << maximum << "!" << endl;
    
    return 0;
}