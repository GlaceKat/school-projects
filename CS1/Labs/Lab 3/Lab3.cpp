#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int i = 0;
    //double q = 0; 
//Write a for loop that displays sum of  values between 2 up to and including 35 with loop interval of 3
    int numVal = 2;
    int sumVal = 2;
    for (i = 0; numVal <= 32; i=i+3)
    {
        numVal = numVal + 3;
        sumVal = sumVal + numVal;
    }
    cout << "Sum: " << sumVal << endl;
    
//Write a for loop sums the values from from 2 to 40 in steps of 2 (even numbers) and then produces the integer average of these numbers.
    int k = 0;
    int evenNum = 2;
    int sumEven = 2;
    for(k=2; evenNum <= 40;++k){
        evenNum = evenNum + 2;
        sumEven = sumEven + evenNum;
    }
    cout << "Average: " << sumEven/k << endl;
    
//Write a for loop that goes from 25 to 0 in loop steps of .5 
    double q = 0;
    double countDown = 25.5;
    for(q = 25; countDown > 0 ;q = q - 0.5){
        countDown = countDown - 0.5;
        if (countDown > 0)
            cout << countDown << ", ";
        else
            cout << countDown;
    }
    
    return 0;

}