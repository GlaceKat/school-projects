#include <iostream>
#include <iomanip> //looked this up for table even though used before
using namespace std;

double numFactorial (int x){ //Finds factorial of a given number
    
    double numToReturn = x;
    
    if (x == 0){ //makes sure factorial 0 is 1
        
        numToReturn = 1;
        
        return numToReturn;
        
    }
    
    for(int i = x; i > 1; i--){
        
        numToReturn = numToReturn * (i - 1);
        
    }
    
    return numToReturn;
}

int main() {
    
    double someNumber = 0; //Number that's factorial needs found
    double niceFactorial = 0; //Stores the factorial of someNumber
    
    cout << "Input a number: ";
    cin >> someNumber;
    cout << endl;
    
    cout << left << setw(20) << "Number" << "Factorial" << endl;
    
    for (int i = 0; i <= someNumber; i++){ //loops to create table of 25 for this lab
        
        niceFactorial = numFactorial(i);
        
        cout << left << setw(20) << i << niceFactorial << endl;
        
    }
    
    return 0;
}