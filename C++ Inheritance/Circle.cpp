#include "Circle.h"
#include <iomanip>

Circle::Circle(int a, int b, double c) {
	Point circleLeftTop;
	circleLeftTop.setX(a);
	circleLeftTop.setY(b);
	Shape::setleftTop(circleLeftTop);

	radius = c;

	//Setting isCircular to true
	Shape::setisCircular(true);
}

//Setters
void Circle::setRadius(double r) {
	r = radius;
}

//Getters

double Circle::getRadius() {
	return radius;
}

void Circle::calculateArea() {
	double circleArea = (radius * radius * 3.14);
	Shape::setArea(circleArea);
}

void Circle::calculatePerimeter() {
	double circlePerimeter = (6.28 * radius);
	Shape::setPerimeter(circlePerimeter);
}

void Circle::calculatePoints() {
	Point temp = getleftTop();
	int tempX = temp.getX();
	int tempY = temp.getY();
	//Calculating point
	Point circlerightBottom(tempX + 2*radius, tempY + 2*radius);

	Shape::setrightBottom(circlerightBottom);
}

//void Circle::toString() {
//	calculateArea();
//	calculatePerimeter();
//	calculatePoints();
//
//	cout << "[r = " << radius << "]" << "\n";
//	cout << "Points [" << "(" << getleftTop() << ")" << "(" << getrightBottom() << ")" << "]" << "\n";
//	cout << "Area = " << setprecision(10) << getArea() << " Perimeter = " << getPerimeter() << "\n";
//
//	std::cout << std::setprecision(8) << std::fixed << getArea() << ":" << getPerimeter() << std::endl;
//}

string Circle::toString() {
	calculateArea();
	calculatePerimeter();
	calculatePoints();

	//Returning as a string
	return "Circle: [r = " + to_string(radius) + "]" + "\n"
		+ "Points [(" + leftTop.printPoint() + ")" + "(" + rightBottom.printPoint() + ")" + "]" + "\n"
		+ "Area = " + to_string(area) + " Perimeter = " + to_string(perimeter) + "\n";


}

void Circle::move(int a, int b) {
	Point newcircleLeftTop(a, b);
	setleftTop(newcircleLeftTop);

}

void Circle::scale(double d) {
	Point tempcircleleftTop = getleftTop();
	double newtempX = tempcircleleftTop.getX();
	double newtempY = tempcircleleftTop.getY();

	newtempX* d;
	newtempY* d;
	//Calculations
	double newRadius = radius * d;

	Point newcirclerightBottom(newtempX + newRadius, newtempY + newRadius);

	//Setting all new values
	Circle::setRadius(newRadius);

	Shape::setrightBottom(newcirclerightBottom);


}
