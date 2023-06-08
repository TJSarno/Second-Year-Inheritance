#include "Square.h"
#include <iomanip>

Square::Square(int a, int b, double c) {

	Point squareLeftTop;
	squareLeftTop.setX(a);
	squareLeftTop.setY(b);
	Shape::setleftTop(squareLeftTop);

	edge = c;
	
}

Square::~Square() {

}
//Setters
void Square::setEdge(double e) {
	edge = e;
}

//Getters
double Square::getEdge() {
	return edge;
}

//Functions
void Square::calculateArea() {
	double squareArea = (edge * edge);
	Shape::setArea(squareArea);
}

void Square::calculatePerimeter() {
	double squarePerimeter = (4 * edge);
	Shape::setPerimeter(squarePerimeter);
}

void Square::calculatePoints() {
	
	//Temporary points for calculating points
	Point temp = getleftTop();
	int tempX = temp.getX();
	int tempY = temp.getY();
	//Calculating points
	Point squarerightTop(tempX + edge, tempY);
	Point squarerightBottom(tempX + edge, tempY + edge);
	Point squareleftBottom(tempX, tempY + edge);

	Shape::setrightTop(squarerightTop);
	Shape::setrightBottom(squarerightBottom);
	Shape::setleftBottom(squareleftBottom);

}
//Old output (produced desired outcome but doesn't produce a string)

//void Square::toString() {
//	calculateArea();
//	calculatePerimeter();
//	calculatePoints();
//
//	cout << "[e = " << edge << "]" << "\n";
//	cout << "Points [" << "(" << getleftTop() << ")" << "(" << getrightTop() << ")" << "(" << getrightBottom() << ")" << "(" << getleftBottom() << ")" << "]" << "\n";
//	cout << "Area = " << getArea() <<  " Perimeter = " << getPerimeter() << "\n";
//}

string Square::toString() {
	calculateArea();
	calculatePerimeter();
	calculatePoints();

	//Returning as a string
	return "Square: [e = " + to_string(edge) + "]" + "\n"
		+ "Points [(" + leftTop.printPoint() + ")" + "(" + rightTop.printPoint() + ")" + "(" + rightBottom.printPoint() + ")" + "(" + leftBottom.printPoint() + ")" + "]" + "\n"
		+ "Area = " + to_string(area) + " Perimeter = " + to_string(perimeter) + "\n";
}

//Move function

void Square::move(int a, int b) {
	Point newsquareLeftTop(a, b);
	setleftTop(newsquareLeftTop);

}

void Square::scale(double d) {
	Point tempsquareleftTop = getleftTop();
	double newtempX = tempsquareleftTop.getX();
	double newtempY = tempsquareleftTop.getY();

	newtempX* d;
	newtempY* d;
	//Calculations
	double newEdge = edge * d;

	Point newsquarerightTop(newtempX + newEdge, newtempY);
	Point newsquarerightBottom(newtempX + newEdge, newtempY + newEdge);
	Point newsquareleftBottom(newtempX, newtempY + newEdge);

	//Setting all new values
	Square::setEdge(newEdge);

	Shape::setrightTop(newsquarerightTop);
	Shape::setrightBottom(newsquarerightBottom);
	Shape::setleftBottom(newsquareleftBottom);


}
