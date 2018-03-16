#include <iostream>
using namespace std;

int main() {
    float testBoi = 0;
    float sumBoi = 0;
    do {
    cout << "Enter Positive Number to Add or Enter Zero or Negative Number to End: ";
    cin >> testBoi;
    sumBoi = sumBoi + testBoi;
    } while (testBoi > 0);
    cout << "Sum of Entered Numbers: " << sumBoi;
    
    return 0;
}