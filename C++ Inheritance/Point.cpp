#include "Point.h"
//Constructors
Point::Point() {

}
Point::Point(int a, int b) {
	x = a;
	y = b;
}

//cout overloader
ostream& operator<<(ostream& os, const Point& dt)
{
	os << dt.x << ',' << dt.y;
	return os;
}
//to_string overloader
//std::string to_string(std::string& stringO, const Point& dt) {
//	return "(" + s
//
//}

//+ overloader
Point operator+ (const Point& point, const Point& point2)
{
	Point temp;
	temp.x = point.x + point2.x;
	temp.y = point.y + point2.y;

	return temp;
}


//Setters
void Point::setX(int a) {
	x = a;
}

void Point::setY(int b) {
	y = b;

}

//Getters
int Point::getX() {
	return x;
}
int Point::getY() {
	return y;
}

string Point::printPoint(){
	return to_string(getX()) + "," + to_string(getY());

}