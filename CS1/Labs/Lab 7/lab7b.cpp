#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>

using namespace std;

void histogram(vector<int> input){ //outputs a histogram of the values stored in the vector (split into three bins)
    int maxNum = 0;
    for(int i = 0; i < input.size(); i++){
        if(input.at(i) > maxNum)
            maxNum = input.at(i);
    }
    
    int bin1 = maxNum / 3;
    int bin2 = bin1 * 2;
    int bin3 = maxNum;
    
    int bin1Sum = 0;
    int bin2Sum = 0;
    int bin3Sum = 0;
    
    for(int i = 0; i < input.size(); i++)
    {
        if(input.at(i) <= bin1)
            bin1Sum++;
        else if(input.at(i) <= bin2)
            bin2Sum++;
        else
            bin3Sum++;
    }
    
    int maxSum = max(max(bin1Sum, bin2Sum), bin3Sum); //scales the histogram
    double factor = 1;
    if(maxSum > 40)
        factor = 40/double(maxSum);
        
    cout << "0 - " << bin1 << "\t\t-";
    for(int i = 0; i < bin1Sum*factor; i++)
        cout << "*";
        
    cout << endl << bin1+1 << " - " << bin2 << "\t-";
    for(int i = 0; i < bin2Sum*factor; i++)
        cout << "*";
        
    cout << endl<< bin2+1 << " - " << bin3 << "\t-";
    for(int i = 0; i < bin3Sum*factor; i++)
        cout << "*";
    cout << endl;
    
}

int main(){
    srand(time(NULL));
    int length = 100;
    int max = 600;
    vector<int> v(length, 0);
    for(int i = 0; i < length; i++){
        int num = rand() % 600;
        v.at(i) = num;
    }
    
    histogram(v); //calls the function created
    
    return 0;
}