#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//Creating a class for an EQUILATERAL Triangular Pyramid
//Because equilateral triangular pyramids are cool.
class TriPyramid {
    
    public:
    TriPyramid(); //Constructor
    TriPyramid(double base, double heightTriangle, double heightPyramid); //Overloaded Constructor
    void SetTriPyramid(double base, double heightTriangle, double heightPyramid); //sets all important values given
                                                                                  //height of the triangle and pyramid 
                                                                                  //along with the length of the base 
                                                                                  //of the triangle
    
    double GetBase(); //all of these retrieve the private variables for me.
    double GetHeightT();
    double GetHeightP();
	double SurfaceArea();
	double Volume();
	
    void PrintTriPyramid(); //Prints the important values:  hgiehgt of triangle and pyramid
                            //base of the triangle, surface area and volume
    
    private:
    double heightTriangle; //sets all private variables
    double heightPyramid;
    double base;
    double volume;
    double surfaceArea;
    
};

TriPyramid::TriPyramid(){
    
    SetTriPyramid(1,1,1);
    
}

TriPyramid::TriPyramid(double base, double heightTriangle, double heightPyramid){
 
    SetTriPyramid(base,heightTriangle, heightPyramid);   
    
}

void TriPyramid::SetTriPyramid(double base, double heightTriangle, double heightPyramid) {
    
    this->base = base;
    this->heightTriangle = heightTriangle;
    this->heightPyramid = heightPyramid;
    volume = ((0.5 * base * heightTriangle) * heightPyramid) / 3;
    surfaceArea = (base * heightTriangle * 0.5) * 4;
    
}

double TriPyramid::GetBase() {
    
    return base;
    
}

double TriPyramid::GetHeightT() {
    
    return heightTriangle;
    
}

double TriPyramid::GetHeightP() {
    
    return heightPyramid;
    
}

void TriPyramid::PrintTriPyramid(){
    
    cout << "The height of the pyramid is: " << heightPyramid << endl;
    cout << "The height of the triangle is: " << heightTriangle << endl;
    cout << "The base of the triangle is: " << base << endl;
    cout << "The volume of the equilateral triangular pyramid is: " << volume << endl;
    cout << "The surface area of the equilateral triangular pyramid is: " << surfaceArea << endl << endl;
    
}

int main(){
    
    TriPyramid First(1,2,3), Second(3,2,1), Third;
    
    First.PrintTriPyramid(); //testing the class and its functions.
    Second.PrintTriPyramid();
    Third.PrintTriPyramid();
    Third.SetTriPyramid(6,6,6);
    Third.PrintTriPyramid();
    
    return 0;
}