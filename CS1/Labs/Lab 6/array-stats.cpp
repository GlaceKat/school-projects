/*
Name: Katerina Betts
Date: October 10, 2017
Assignment: Functions With Arrays AND Strings
Description: Filling in functions to work as directed on Lab 6 document.
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm> //added on for find()

using namespace std;

//All code taken from skeleton provided and filled.

void init(int array[], int length, int value){
  
  for(int i = 0; i < length; i++){
      
      array[i] = value;
      
  }
  
}

void init(string array[], int length, string value){
  
  for(int i = 0; i < length; i++){
      
      array[i] = value;
      
  }
  
}

int count(int array[], int length, int value){
  
  int count = 0;
  
  if (length <= 0)
    return 0;
  
  for(int i = 0; i < length; i++){
      
      if(array[i] == value)
        count++;
      
  }
  
  return count;
  
}

int count(string array[], int length, string value){
  
  int count = 0;
  
  if (length <= 0)
    return 0;
  
  for(int i = 0; i < length; i++){
      
      if(array[i] == value)
        count++;
      
  }
  
  return count;
  
}

bool isSorted(int array[], int length){
  
  if(length <= 1)
    return 1;
  
  for(int i = 1; i < length; i++){
      
      if(array[i] < array[i - 1])
        return 0;
      
  }
  
  return 1;
  
}

void reverse(int array[], int length){
  
    int j = length - 1;
    int k = array[0];
  
    for(int i = 0; i < j; i++){
        
        k = array[i];
        array[i] = array[j];
        array[j] = k;
        j--;
      
  }
  
}

float mean(float array[], int length){
  
  float sumVal = 0;
  
  if(array == 0)
    return 0;
  
  for(int i = 0; i < length; i++){
      
      sumVal = sumVal + array[i];
      
  }
  
  return sumVal / length;
  
}

float stdev(float array[], int length){
  float stdSum = 0;
  for(int i = 0; i < length; i++)
  {
      stdSum = stdSum + pow(array[i] - mean(array, length), 2);
  }
  
  return sqrt(stdSum/length);
}

void shuffle(float array[], int length){
  
  int k = 0;
  float j = 0;
  
  for(int i = 0; i < length; i++){
      
      k = rand() % length;
      j = array[i];
      array[i] = array[k];
      array[k] = j;
      
  }
  
}

vector<int> removeDups(vector<int> array){

    vector <int> newArray;

    for(int i = 0; i < array.size(); i++){
      
      if(find(newArray.begin(),newArray.end(), array.at(i)) == newArray.end()) //Where algorithm was needed
        newArray.push_back(array.at(i));
        
    }
  
  return newArray;
}

// See below for this function
template<typename T>
string print(T array[], int length);


int main(){
  srand(time(0));   
 
  cout << "reverse" << endl;
  int a1[] = {1,2,3,4,5};
  reverse(a1, 5);
  cout << "[5,4,3,2,1] = " << print(a1, 5) << endl;
  reverse(a1, 5);
  cout << "[1,2,3,4,5] = " << print(a1, 5) << endl;
  int a2[] = {5};
  cout << "[5] = " << print(a2,1) << endl;
  int a3[] = {1,2,4,5};
  reverse(a3, 4);
  cout << "[5,4,2,1] = " << print(a3, 4) << endl;
  int a4[100] = {1,2};
  reverse(a4, 100);
  cout << "0 = " << a4[0] << endl;
  cout << "2 = " << a4[98] << endl;
  
  float f1[] = {5.6, 2.1, 9.9, 125.4};
  float f2[] = {5.6, 5.6, 5.6, 5.6, 5.6, 5.6};
  cout << endl << "mean:" << endl;
  cout << "35.75 = " << mean(f1, 4) << endl;
  cout << "5.6 = " << mean(f2, 6) << endl;
  
  cout << endl << "stdev:" << endl;
  cout << "51.8331 = " << stdev(f1, 4) << endl;
  cout << "0 = " << stdev(f2, 6) << endl;
  
  cout << endl << "shuffle:" << endl;
  shuffle(f1, 4);
  // These should not match, but there is a chance they will.
  cout << "[5.6,2.1,9.9,125.4] != " << print(f1, 4) << endl;
  cout << "51.8331 = " << stdev(f1, 4) << endl;
  
  cout << endl << "removedups:" << endl;
  //vector<int> v1 = {1,2,3,3,4,5,1};  // Not supported in C++98
  vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(3);
  v1.push_back(4);
  v1.push_back(5);
  v1.push_back(1);
  vector<int> v12 = removeDups(v1);
  cout << "[1,2,3,4,5] = " << print(v12.data(), v12.size()) << endl;
  cout << "5 = " << v12.size() << endl;
  vector<int> v2;
  for(int i = 0; i < 100; i++){
    v2.push_back(i%17 + i %7);
  }
  vector<int> v22 = removeDups(v2);
  cout << "22 = " << v22.size() << endl;

  cout << "Init w/ ints" << endl;
  init(a1, 5, 99);
  cout << "99 = " << a1[1] << endl;
  cout << "99 = " << a1[3] << endl;

  cout << endl << "Init w/ strings" << endl;
  string sa2[] = {"", "Bla", "What?", "You don't say!"};
  init(sa2, 4, "Empty");
  cout << "Empty = " << sa2[0] << endl;
  cout << "Empty = " << sa2[3] << endl;

  cout << endl << "Count w/ ints" << endl;
  int ca3[] = {1,2,3,4,5,6,7,1,2};
  cout << "1 = " << count(ca3, 9, 5) << endl;
  cout << "2 = " << count(ca3, 9, 1) << endl;
  int ca4[100];
  for(int i = 0; i < 100; i++){
	  ca4[i] = (i + i %7 ) % 11;
  }
  cout << "8 = " << count(ca4, 100, 5) << endl;
  cout << "9 = " << count(ca4, 100, 1) << endl;

  cout << endl << "Count w/ strings" << endl;
  string a5[] = {"blab", "ha", "ha"};
  cout << "1 = " << count(a5, 3, "blab") << endl;
  cout << "2 = " << count(a5, 3, "ha") << endl;

  cout << endl << "Is Sorted" << endl;
  int a7[] = {1,2,2,3,5,10,100};
  int a8[] = {1,2,3,4,4,5,4};
  cout << "0 = " << isSorted(ca3, 9) << endl;
  cout << "1 = " << isSorted(a1, 5) << endl;
  cout << "1 = " << isSorted(a7, 7) << endl;
  cout << "0 = " << isSorted(a8, 7) << endl;

  return 0;
}

// A sneaky way to allow 1 function to print any typed array, as long as
// the passed array element can be sent to <<.
// The stringstream allows us to 'print' information to a fake output
// stream, and then get the result as a string.  It's a simple way of
// getting a non-string/character into a string.
// Contense of this function will not be tested in this course!
template<typename T>
string print(T array[], int length){
  stringstream out;
  out << '[';
  for(int i = 0; i < length; i++){
    out << array[i];
    if(i != length-1)out << ',';
  }
  out << ']';
  return out.str();
}