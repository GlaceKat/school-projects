#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int countChars(string input, char which_char){ //number of characters in a string
    
    int count = 0;
    
    for(int i = 0; i < input.size(); i++){
        
        if (which_char == input.at(i))
            count++;
        
    }
    return count;
}

int upperCaseChars(string input){ //number of uppercase characters in a string
    
    int countUpper = 0;
    
    for(int i = 0; i < input.size(); i++){
        
        if (isupper(input.at(i)))
            countUpper++;
    }
    return countUpper;
}

int lowerCaseChars(string input){ //number of lowercase characters in a string
    
    int countLower = 0;
    
    for(int i = 0; i < input.size(); i++){
        
        if (islower(input.at(i)))
            countLower++;
    }
    return countLower;
}

int numPunct(string input){ //number of punctuation marks in a string
    
    int punctCount = 0;
    
    for(int i = 0; i < input.size(); i++){
        
        if (ispunct(input.at(i)))
            punctCount++;
    }
    return punctCount;
}

string stringToUpper(string input){ //converts alpha characters to uppercase
    int i = 0;
    string newInput = "";
    while(i < input.size()){
        
        newInput += toupper(input.at(i));
        i++;
    }
    return newInput;
}

string stringToLower(string input){ //converts alpha characters to lowercase
    int i = 0;
    string newInput = "";
    while(i < input.size()){
        
        newInput += tolower(input.at(i));
        i++;
    }
    return newInput;
}

vector <int> characterCounts(string input){ //creates a vector that counts how many instances of each alpha character appears in a string
    int length = 26;
    vector <int> countChars(length, 0);
    
    for(int j = 0; j < input.size(); j++){
        
            if(isalpha(input.at(j)))
                countChars.at(tolower(input.at(j))-97)++;
            
        }
    
    return countChars;
}

int numLines(string input){ //counts the numbers of lines in a string
    int lines = 0;
    for(int i = 0; i < input.size(); i++){
        if(input.at(i)=='\n')
            lines++;
    }
    if(lines == 0)
        lines++;
    return lines;
}

int numWords(string input){ //counts the number of words in a string
    int words = 0;
    char curr;
    char prev;
    for(int i = 1; i < input.size(); i++){
        curr = input.at(i);
        prev = input.at(i-1);
        if(isalpha(prev) && !isalpha(curr))
            words++;
    }
    if(isalpha(input.at(input.size()-1)))
        words++;
    return words;
}

string rightRotateString(string input, int offset){ //"rotates" the word by taking the stuff at the end and putting it at the beginning by a specified numbers of characters
    if(input.size() == 0 || offset == 0 || offset >= input.size())
        return input;
    string newInput = "";
    int counter = offset;
    while(counter > 0){
        newInput += input.at(input.size()-counter);
        counter--;
    }
    newInput += input.substr(0, input.size()-offset);
    
    return newInput;
}

int main(){
    
    //First Function Testing
    string randomChar = "abcxyz123zyz";
    char specificChar = 'z';
    int numChar = 0;
    
    numChar = countChars(randomChar, specificChar);
    
    cout << "The number of " << specificChar << "'s is " << numChar << endl;
    
    //Second Function Testing
    string aString = "";
    int capsLetters = 0;
    cout << "Input a string: ";
    getline(cin,aString);
    capsLetters = upperCaseChars(aString);
    cout << "There are " << capsLetters << " uppercase letters in this string." << endl;
    
    //Third Funtion Testing
    int lowerLetters = 0;
    lowerLetters = lowerCaseChars(aString);
    cout << "There are " << lowerLetters << " lowercase letters in this string." << endl;
    
    //Fourth Function Testing
    int punctCount = 0;
    punctCount = numPunct(aString);
    cout << "There are " << punctCount << " punctuation marks in this string." << endl;
    
    //Fifth Function Testing
    aString = stringToUpper(aString);
    cout << "The new string is " << '"' << aString << '"' << endl;
    
    //Sixth Function Testing
    aString = stringToLower(aString);
    cout << "The new string is " << '"' << aString << '"' << endl;
    
    //Seventh Function Testing
    vector <int> charTracker;
    charTracker = characterCounts(aString);
    
    for(int w = 0; w < charTracker.size(); w++){
        
        cout << "The number of " << char(w+97) << "'s is " << charTracker.at(w) << endl;
        
    }
    
    //Eigth Function Testing
    int lines = 0;
    lines = numLines(aString);
    cout << "The number of lines is " << lines << endl;
    lines = numLines(aString + "\n\n");
    cout << "The number of lines is " << lines << endl;
    
    //Ninth Function Testing
    int words = 0;
    words = numWords(aString);
    cout << "The number of words is " << words << endl;
    words = numWords(aString + "a");
    cout << "The number of words is " << words << endl;
    
    //Tenth Function Testing
    string out = rightRotateString(aString, 4);
    cout << "The rotated string is: " << out << endl;
    
    return 0;
    
}