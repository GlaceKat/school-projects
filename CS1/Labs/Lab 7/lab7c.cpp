#include <iostream>
#include <cmath>

using namespace std;

double degreesToRadians(double d){ //converts degrees to radians
    d = fmod(d, 360);
    return d*M_PI/180;
}

struct Pair{ //holds an (x,y) pair
    double x,y;
};

double slope(Pair p1, Pair p2){ //calculates slope with two pairs
    return (p2.y - p1.y)/(p2.x - p1.x);
}

double yIntercept(Pair p1, Pair p2){ //finds the y intercept of two pairs
    return p1.y - slope(p1, p2)*p1.x;
}

void rect(Pair p1, Pair p2){ //calculates the width, height and area of a rectangle formed between the two points
    double width = abs(p2.x - p1.x);
    double height = abs(p2.y - p1.y);
    double area = width*height;
    
    cout << "The width is " << width << endl;
    cout << "The height is " << height << endl;
    cout << "The area is " << area << endl;
}

int main(){
    //Twelfth Function Testing
    float angled = 720;
    float angler = degreesToRadians(angled);
    cout << angled << " degrees is " << angler << " radians." << endl;
    angled = 750;
    angler = degreesToRadians(angled);
    cout << angled << " degrees is " << angler << " radians." << endl;
    angled = 30;
    angler = degreesToRadians(angled);
    cout << angled << " degrees is " << angler << " radians." << endl;
    angled = 1000;
    angler = degreesToRadians(angled);
    cout << angled << " degrees is " << angler << " radians." << endl;
    angled = 280;
    angler = degreesToRadians(angled);
    cout << angled << " degrees is " << angler << " radians." << endl;
    angled = -280;
    angler = degreesToRadians(angled);
    cout << angled << " degrees is " << angler << " radians." << endl;
    
    //Thirteenth Function Testing
    Pair p1;
    p1.x = 1;
    p1.y = 3;
    Pair p2;
    p2.x = 2;
    p2.y = 5;
    cout << "The slope is " << slope(p1, p2) << endl;
    cout << "The y-intercept is " << yIntercept(p1, p2) << endl;
    
    //Fourteenth Function Testing
    rect(p1, p2);
    
    return 0;
}