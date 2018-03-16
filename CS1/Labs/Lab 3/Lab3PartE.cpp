#include <iostream>
 
 using namespace std;
 
 int main(){
 
 int userNum = 0;
 int i = 0;
 
 for (i = userNum; userNum <= 100; userNum = userNum + 1){
     
     cout << userNum << " - ";
     
     if (userNum % 2 == 0){
         cout << "even";
     }
     else {
         cout << "odd";
     }
     if (userNum % 3 == 0) {
         cout << ", three";
     }
     if (userNum % 5 == 0) {
         cout << ", five";
     }
     cout << endl;
 }
 
 }