#include <iostream>
#include <fstream> //to use the file i/o stuff
#include <string>
#include <vector>

using namespace std;

bool isPrime(int num){//checks if a number is prime
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    
    ifstream infile; //created file stream
    infile.open("input.txt"); //open file stream
    
    if(!infile) //checks if error opening the file
        cout << "Error opening file" << endl;
        
    vector<int> numbers;
    int num;
    int count = -1;
    int primes = -1;
    
    while((infile >> num).good()){
        numbers.push_back(num);
        count++;
        if(isPrime(num))
            primes++;
    }
    
    cout << "Numbers read in: " << count << endl;
    cout << "Prime numbers: " << primes << endl;
    
    return 0;
}