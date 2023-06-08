#include "Shape.h"
#include <iostream>
using namespace std;

//Constructor
Shape::Shape() {

}
//Setters

void Shape::setleftTop(Point r) {
	leftTop = r;
}

void Shape::setrightTop(Point t) {
	rightTop = t;
}
void Shape::setrightBottom(Point u) {
	rightBottom = u;
}
void Shape::setleftBottom(Point i) {
	leftBottom = i;
}


void Shape::setArea(double z) {
	area = z;
}

void Shape::setPerimeter(double y) {
	perimeter = y;
}

void Shape::setisCircular(bool a) {
	a = true;
}


//Getters

double Shape::getArea() {
	return area;
}

double Shape::getPerimeter() {
	return perimeter;
}

Point Shape::getleftTop() {
	return leftTop;
}

Point Shape::getrightTop() {
	return rightTop;
}

Point Shape::getrightBottom() {
	return rightBottom;
}
Point Shape::getleftBottom() {
	return leftBottom;
}



//Virtual Functions

void Shape::calculateArea() {

}

void Shape::calculatePerimeter(){

}


void Shape::calculatePoints() {

}

string Shape::toString() {
	return "";
}


