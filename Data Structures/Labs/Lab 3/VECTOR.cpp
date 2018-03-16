#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>
#include "VECTOR.h"

using namespace std;

//below are all the constructors (default and overloads) that set the initial value of the vector.
CalcsVectors::CalcsVectors() {

	x1 = 0;
	y1 = 0;
	magnitude = 0;
	angle = 0;

}

CalcsVectors::CalcsVectors(float mag, float ang)
{
	CalcsVectors();

	magnitude = mag;
	angle = ang;

	x1 = magnitude * cos(ang);
	y1 = magnitude * sin(ang);
}
CalcsVectors::CalcsVectors(double x, double y)
{
	x1 = x;
	y1 = y;
	magnitude = sqrt(pow(x1, 2) + pow(y1, 2));
	angle = atan(x1 / y1);
}

//the set functions below allocate what goes into the private member variables
void CalcsVectors::setX(double x) {
	x1 = x;

	magnitude = sqrt(pow(x1, 2) + pow(y1, 2));
	angle = atan(x1 / y1);
}
void CalcsVectors::setY(double y) {
	y1 = y;

	magnitude = sqrt(pow(x1, 2) + pow(y1, 2));
	angle = atan(x1 / y1);
}
void CalcsVectors::setAngle(float ang) {
	angle = ang;

	x1 = magnitude * cos(ang);
	y1 = magnitude * sin(ang);
}
void CalcsVectors::setMagnitude(float mag) {
	magnitude = mag;

	x1 = magnitude * cos(angle);
	y1 = magnitude * sin(angle);
}

//the get functions below return the variable indicated
double CalcsVectors::getX() {
	return x1;
}
double CalcsVectors::getY() {
	return y1;
}
double CalcsVectors::getMagnitude() {
	return magnitude;
}
double CalcsVectors::getAngle() {
	return angle;
}
void CalcsVectors::printAll() //utilizes get functions to display the many private attributes
{
	cout << "Vector:\n";
	cout << "X: " << getX() << endl;
	cout << "Y: " << getY() << endl;
	cout << "Angle: " << getAngle() << endl;
	cout << "Magnitude " << getMagnitude() << endl;
}

//All the overloaded functions below are explained in the .h file
void CalcsVectors::operator+(CalcsVectors anotherVector) {

	x1 = x1 + anotherVector.x1;
	y1 = y1 + anotherVector.y1;

	magnitude = sqrt(pow(x1, 2) + pow(y1, 2));
	angle = atan(x1 / y1);

}

void CalcsVectors::operator-(CalcsVectors anotherVector) {

	x1 = x1 - anotherVector.x1;
	y1 = y1 - anotherVector.y1;

	magnitude = sqrt(pow(x1, 2) + pow(y1, 2));
	angle = atan(x1 / y1);

}

void CalcsVectors::operator*(double scalar) {

	x1 = x1 * scalar;
	y1 = y1 * scalar;

	magnitude = sqrt(pow(x1, 2) + pow(y1, 2));
	angle = atan(x1 / y1);

}

void CalcsVectors::operator/(double scalar) {

	x1 = x1 / scalar;
	y1 = y1 / scalar;

	magnitude = sqrt(pow(x1, 2) + pow(y1, 2));
	angle = atan(x1 / y1);

}

bool CalcsVectors::operator == (CalcsVectors equivalent) {

	if ((x1 == equivalent.x1) && (y1 == equivalent.y1)) {

		return 1;

	}
	else
		return 0;
};