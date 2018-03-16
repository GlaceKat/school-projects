#include <iostream>
using namespace std;

bool IsMultipleOfX(int number, int X){ //finds whether or not number is a multiple of the given number X
    
    if(number % X == 0){
        
        return 1;
    
    }
    
    return 0;
}

bool IsMultipleOfFive(int number){ //finds whether number is a multiple of five
    
    if (IsMultipleOfX(number,5)){
        
        return 1;
        
    }
    
    return 0;
}

bool IsMultipleOfThree(int number){ //finds whether the number is a multiple of three
    
    if (IsMultipleOfX(number,3)){
        
        return 1;
    
        
    }
    
    return 0;
}

bool IsAnOddNumber(int number){ //Returns true if the number is odd
    
    if (number % 2 == 0){
        
        return 0;
        
    }
    
    return 1;
    
}

bool IsAnEvenNumber(int number){ //Returns true if the number is even
    
    if (number % 2 == 0){
        
        return 1;
        
    }
    
    return 0;
    
}

int main(){
    
    int counter = 1;
    
    while (counter < 101 && counter > 0){ //Tests created functions for 1-100
        
        cout << counter << " - ";
        

        if(IsAnOddNumber(counter)){
            
            cout << "odd";
            
        }
        if(IsAnEvenNumber(counter)){
            
            cout << "even";
            
        }
                if(IsMultipleOfFive(counter)){
            
            cout << ", five";
            
        }
        if(IsMultipleOfThree(counter)){
            
            cout << ", three";
            
        }
        
        cout << endl;
        counter++;
        
    }
    
    return 0;
}