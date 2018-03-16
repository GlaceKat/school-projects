#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


const unsigned int VECTOR_SIZE = 51;
const unsigned int NUM_RAND_GENERATED = 100000;

void displayBoi (vector <int> x){
    
    cout << "The values for 0-50 are: " << endl; 
    
    for(int i = 0; i < VECTOR_SIZE; i++)
    {
            cout << i << "\t" <<  x.at(i) << endl;
    }
    
}

void maxValue(vector <int> x){
    
    int max = x.at(0);
    for(int i = 0; i < VECTOR_SIZE; i++){
        
        if(x.at(i) > max)
            max = x.at(i);
    }
    
    cout << "The maximum value is: " << max << endl;

}

void minValue(vector <int> x){
    
    int min = x.at(0);
    for(int i = 0; i < VECTOR_SIZE; i++){
        
        if(x.at(i) < min)
            min = x.at(i);
    }
        
    cout << "The minimum value is: " << min << endl;
} 

void sumBoi(vector <int> x){
    
    int theSum = 0;
    for(int i = 0; i < VECTOR_SIZE; i++){
        
        theSum = theSum + x.at(i);
        
    }
    
    cout << "The sum of the occurences is:  " << theSum;
    
}

int randomFifty(){
    int x = 0;
    x = rand() % VECTOR_SIZE;
    return x;
    
}

int main(){
    
    
    int x = 0;
    
    vector <int> fiftyBoiz(VECTOR_SIZE,0);
    
    srand(time(NULL));
    
    for(int i = 0; i < NUM_RAND_GENERATED; i++)
    {
        x = randomFifty();
            
        fiftyBoiz.at(x) = fiftyBoiz.at(x) + 1;
        
    }
    
    displayBoi(fiftyBoiz);
    maxValue(fiftyBoiz);
    minValue(fiftyBoiz);
    sumBoi(fiftyBoiz);
    
    
    return 0;
}