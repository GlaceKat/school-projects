#include <iostream>
using namespace std;

void line(int width, char fill_char){ //creates a line out of ASCII symbols
    
    for(int i = 0; i < width; i++){
        
        cout << fill_char;
        
    }
    cout << endl;
    
}
void solidRectangle(int width, int height, char fill_char){ //creates a rectangle out of ASCII symbols
    
    for(int i = 0; i < height; i++){
        
        line(width,fill_char);
        
    }
    
}
void framedRectangle(int width, int height, char fill_char, int frame_width){ //creates with ASCII characters the "border" of a rectangle
    
    for (int i = 0; i < frame_width; i++){
     
        line(width,fill_char);
        
    }
    
    for (int i = frame_width; i < height - frame_width; i++){
        
        for(int j = 0; j < frame_width; j++){
            
            cout << fill_char;
        }
        for(int k = frame_width; k < width - frame_width; k++){
            
            cout << " ";
        }
        for(int l = 0; l < frame_width; l++){
            
            cout << fill_char;
        }
        cout << endl;
    }
    
    for(int i = 0; i < frame_width; i++){
        
        line(width, fill_char);
    }
    
}
void square(int size, char fill_char){ //creates a square out of ASCII symbols
    
    solidRectangle(size, size, fill_char);
    
}

int main(){
    char fill_char; //character picked from ASCII table
    int width = 0; //width of picture
    int size = 0; //sides of square picture
    int frame_width = 0; //how many characters thick the framed rectangle is
    int height = 0; //how tall the picture is
    int shape = 0; //which shape is drawn[1-4]
    
    cout << "Which shape should I draw (0 to exit the menu)??" << endl;
    cin >> shape;
    
    while(shape != 0){ //goes until user exits by pressing 0
        
        if(shape == 1){
        
            cout << "Line Drawing" << endl;
            cout << "Fill Character?  ";
            cin >> fill_char;
            cout << endl;
            cout << "Width?  ";
            cin >> width;
            cout << endl;
            
            line(width, fill_char);
        
        }
        else if(shape == 2){
        
            cout << "Solid Rectangle" << endl;
            cout << "Fill Character?  ";
            cin >> fill_char;
            cout << endl;
            cout << "Height?  ";
            cin >> height;
            cout << endl;
            cout << "Width?  ";
            cin >> width;
            cout << endl;
            
            solidRectangle(width,height,fill_char);
            
        }
        else if(shape == 3){
            
            cout << "Framed Rectangle" << endl;
            cout << "Fill Character?  ";
            cin >> fill_char;
            cout << endl;
            cout << "Height?  ";
            cin >> height;
            cout << endl;
            cout << "Width?  ";
            cin >> width;
            cout << endl;
            cout << "Border Width?  ";
            cin >> frame_width;
            cout << endl;
            
            framedRectangle(width,height,fill_char,frame_width);
        
        }
        else if(shape == 4){
            
            cout << "Square" << endl;
            cout << "Size?  ";
            cin >> width;
            cout << endl;
            cout << "Fill Character? ";
            cin >> fill_char;
            cout << endl;
            
            square(width,fill_char);
            
        }
        else{ //if it isn't zero, but doesn't match anything else in the if statements
            
            cout << "This is not a valid input. Please re-enter your choice." << endl;
            
        }
        
        cout << "Which shape should I draw? " << endl;
        cin >> shape;
        
    }
    return 0;
}