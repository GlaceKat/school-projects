#ifndef CALCSVECTORS
#define CALCSVECTORS

class CalcsVectors {

public:

	CalcsVectors(); //default constructor
	CalcsVectors(float magnitude, float angle); //overload with angle and magnitude
	CalcsVectors(double x1, double y1);

	// Set attributes
	void setX(double newX1);
	void setY(double newY1);
	void setMagnitude(float mag);
	void setAngle(float ang);

	// Get attributes
	double getX();
	double getY();
	double getMagnitude();
	double getAngle();

	// Print vector
	void printAll();

	// Overloads
	void operator + (CalcsVectors anotherVector); //overloads the + operator to add two vectors together
	void operator - (CalcsVectors anotherVector); //overloads the - operator to subtract one vector from another
	void operator * (double scalar);			  //overloads the * operator to multiple the vector by a scalar
	void operator / (double scalar);			  //overloads the / operator to divide the vector by a scalar
	bool operator == (CalcsVectors equivalent);	  //overloads the == operator to tell if two VECTORS are equal

private:

	double x1;
	double y1;
	double magnitude;
	double angle;
};

#endif