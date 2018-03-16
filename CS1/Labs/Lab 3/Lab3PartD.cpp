#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    
    int angle_in_degrees = 0;
    double angle_in_radians = 0;
    
    cout << fixed << "Deg";
    cout << fixed << setw(10) << "Sine";
    cout << fixed << setw(10) << "Cosine";
    cout << fixed << setw(25) << "Tangent" << endl;
    
    while (angle_in_degrees < 360){
    angle_in_radians = angle_in_degrees * M_PI/180.0;
    
    

    cout << angle_in_degrees;
    cout << fixed << setw(10) << setprecision(4) << sin(angle_in_radians);
    cout << fixed << setw(10) << setprecision(4) << cos(angle_in_radians);
    cout << fixed << setw(25) << setprecision(4) << tan(angle_in_radians) << endl;
    
    angle_in_degrees = angle_in_degrees + 10;
    }
    
}