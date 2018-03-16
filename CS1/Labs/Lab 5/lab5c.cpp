#include <iostream>
#include <math.h> //Preference.  Don't like mathc.
using namespace std;

int primeNumCheck (int primeNum){ //checks to see if a number is prime
    
    bool isItPrime = 1; //whether or not this number is prime T/F
    
    if (primeNum <= 1){
        
        isItPrime = 0;
        return isItPrime;
        
    }
    
    for (int i = 2; i <= sqrt(primeNum); i++){
        
        if (primeNum % i == 0){
            isItPrime = 0;
            return isItPrime;
        }
        
    }
    
    return isItPrime;
}


int main(){
    
    int numOfPrimes = 0; //how many primes to find
    int counter = 0; //counts prime numbers
    
    cout << "How many prime numbers should be output?" << endl;
    cin >> numOfPrimes;
    
    cout << endl;
    cout << "List of Prime Numbers:" << endl;
    
    for (int i = 0; counter < numOfPrimes; i++){ //counts the prime numbers until the number wanted outputs
        
        if(primeNumCheck(i)){
            
            cout << i << endl;
            
            counter++;
        
        }
        
    }
    
    return 0;
}