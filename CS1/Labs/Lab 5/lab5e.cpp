#include <iostream>
using namespace std;

double numFactorial (int x){ //Finds factorial of a given number
    
    int numToReturn = x;
    
    if (x == 0){ //makes sure factorial 0 is 1
        
        numToReturn = 1;
        
        return numToReturn;
        
    }
    
    for(int i = x; i > 1; i--){
        
        numToReturn = numToReturn * (i - 1);
        
    }
    
    return numToReturn;
}

double myExp(int howAccurate){ //approximates the value of e using numFactorial
        
    double e = 1;    
    
    for (double i = 1; i < howAccurate; i++){
        
       e = e + (1.0 / numFactorial(i));
       
    }
    
    return e;
}

int main(){
    int howAccurate = 0; //basically how far the factorial needs to go to get an accurate version of e
    double e = 0; //the number e
    
    cout << "How many factorials should the loop go to approximate the value of e? (<35) "; //used to test the code
    cin >> howAccurate;
    cout << endl;
    
    e = myExp(howAccurate);
    
    cout << "The value of e is " << e << "." << endl; //outputs approx of e.
    
    return 0;
}