#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//Creating a class for a CONE
//This time I took inspiration from ice cream and being hungry 24/7.

class Cone {
    
    public:
    Cone(); //Constructor
    Cone(double radius, double height); //Overloaded Constructor
    void SetCone(double radius, double height); //sets all important values given
                                                                                  //height of the cone and the radius
                                                                                  //of its base. 
                                                                                  
    const double PI = 3.14159265358979323846; //used the PI used in the example sphere class instead of the cmath PI
    
    double GetRadius(); //These all acquire the private variables.
    double GetHeight();
	double SurfaceArea();
	double Volume();
	
    void PrintCone(); //Prints out the dimensions of cone: volume, radius, SA and height
    
    private:
    double height;
    double radius;
    double volume;
    double surfaceArea;
    
};

Cone::Cone(){
    
    SetCone(1,1);
    
}

Cone::Cone(double radius, double height){
 
    SetCone(radius, height);   
    
}

void Cone::SetCone(double radius, double height) {
    
    this->radius = radius;
    this->height = height;
    volume = (PI * pow(radius, 2) * height) / 3;
    surfaceArea = PI * radius * (radius + sqrt(pow(radius,2) + pow(height,2)));
    
}

double Cone::GetRadius() {
    
    return radius;
    
}

double Cone::GetHeight() {
    
    return height;
    
}

void Cone::PrintCone(){
    
    cout << "The height of the cone is: " << height << endl;
    cout << "The radius of the base is: " << radius << endl;
    cout << "The volume of the cone is: " << volume << endl;
    cout << "The surface area of the cone is: " << surfaceArea << endl << endl;
    
}

int main(){
    
    Cone First(1,2), Second(3,2), Third; //creating the three test values to  be carried out
    
    First.PrintCone(); //Testing the class and its functions.
    Second.PrintCone();
    Third.PrintCone();
    Third.SetCone(20,20);
    Third.PrintCone();
    
    return 0;
}