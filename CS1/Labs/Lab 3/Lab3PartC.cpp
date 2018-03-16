#include <iostream>
using namespace std;

int main(){
    
    int startNum = 0;
    int endNum = 0;
    int steps = 0;
    int sumOdd = 0;
    int sumEven = 0;
    int sumAll = 0;
    int i = 0;
    float averageSum = 0;
    int count = 0;
    
    cout << "Start Number: " << endl;
    cin >> startNum;
    cout << "Ending Number: " << endl;
    cin >> endNum;
    cout << "Steps: " << endl;
    cin >> steps;
    
    
    while (startNum > endNum || steps < 1){
    if (startNum > endNum) {
        cout << "Put in a new starting number: ";
        cin >> startNum;
        cout << "Put in a new ending number: ";
        cin >> endNum;
    }
    if (steps < 1) {
        cout << "Steps must be greater than or equal to one; reinput the steps: ";
        cin >> steps;
    }
    }
    
    for(i = startNum; i <= endNum; i = i + steps) {
        
        sumAll = sumAll + i;
        count = count + 1;
        
        if(i % 2 == 0) {
            sumEven = sumEven + i;
        }
        else
        {
            sumOdd = sumOdd + i;
        }
    }
    
    averageSum = sumAll / count;

    
    cout << "ODD Number Sum: " << sumOdd << endl;
    cout << "EVEN Number Sum: " << sumEven << endl;
    cout << "Sum of ALL numbers: " << sumAll << endl;
    cout << "Average: " << averageSum << endl;
    
    
    
    
    return 0;
}