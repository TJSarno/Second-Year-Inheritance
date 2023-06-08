#include "Rectangle.h"
#include <iostream>
#include <iomanip>

using namespace std;

Rectangle::Rectangle(int a, int b, int c, int d) {
	
	Point rectLeftTop;
	rectLeftTop.setX(a);
	rectLeftTop.setY(b);
	Shape::setleftTop(rectLeftTop);
	
	height = c;
	width = d;
}

Rectangle::~Rectangle() {

}
//Setters
void Rectangle::setHeight(double h) {
	height = h;
}

void Rectangle::setWidth(double w) {
	width = w;
}

//Getters
double Rectangle::getHeight() {
	return height;
}

double Rectangle::getWidth() {
	return width;
}

//Functions

void Rectangle::calculateArea() {
	double rectArea = width * height;
	Shape::setArea(rectArea);
}

void Rectangle::calculatePerimeter() {
	double rectPerimeter = (2 * width) + (2 * height);
	Shape::setPerimeter(rectPerimeter);
	
}


void Rectangle::calculatePoints() {
	//Temporary points for calculating points
	Point temp = getleftTop();
	int tempX = temp.getX();
	int tempY = temp.getY();
	//Calculating points
	Point rectrightTop(tempX + width, tempY);
	Point rectrightBottom(tempX + width, tempY + height);
	Point rectleftBottom(tempX, tempY + height);
	
	Shape::setrightTop(rectrightTop);
	Shape::setrightBottom(rectrightBottom);
	Shape::setleftBottom(rectleftBottom);

}

//Old output (produced desired outcome but doesn't produce a string)

//void Rectangle::toString() {
//		calculateArea();
//		calculatePerimeter();
//		calculatePoints();
//		
//		cout << "[h = " << height << ", w = " << width << "]" << "\n";
//		cout << "Points [" << "(" << getleftTop() << ")" << "(" << getrightTop() << ")" << "(" << getrightBottom() << ")" << "(" << getleftBottom() << ")" << "]" << "\n";
//		cout << "Area = " << getArea() << " Perimeter = " << getPerimeter() << "\n";
//		
//}

string Rectangle::toString() {
	calculateArea();
	calculatePerimeter();
	calculatePoints();

	//Returning as a string
	return "Rectangle: [h = " + to_string(height) + ", w = " + to_string(width) + "]" + "\n"
		+ "Points [(" + leftTop.printPoint() + ")" + "(" + rightTop.printPoint() + ")" + "(" + rightBottom.printPoint() + ")" + "(" + leftBottom.printPoint() + ")" + "]" + "\n"
		+ "Area = " + to_string(area) + " Perimeter = " + to_string(perimeter) + "\n";


}

//Move functions

void Rectangle::move(int a, int b) {
	Point newrectLeftTop(a,b);
	setleftTop(newrectLeftTop);

}

void Rectangle::scale(double d, double e) {
	Point temprectleftTop = getleftTop();
	double newtempX = temprectleftTop.getX();
	double newtempY = temprectleftTop.getY();

	newtempX* d;
	newtempY* e;
	//Calculations
	double newHeight = height * d;
	double newWidth = width * e;
	
	Point newrectrightTop(newtempX + newWidth, newtempY);
	Point newrectrightBottom(newtempX + newWidth, newtempY + newHeight);
	Point newrectleftBottom(newtempX, newtempY + newHeight);

	//Setting all new values
	Rectangle::setHeight(newHeight);
	Rectangle::setWidth(newWidth);

	Shape::setrightTop(newrectrightTop);
	Shape::setrightBottom(newrectrightBottom);
	Shape::setleftBottom(newrectleftBottom);


}




