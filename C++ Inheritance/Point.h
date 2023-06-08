#pragma once
#include <string>
#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;

	//cout overloader to allow cout to display Point values.
	//Wasn't used in the final build as toString() would not allow for couts, but proved useful in testing addition of points.

	friend ostream& operator<<(ostream& os, const Point& dt);


	//+ overloader to allow + to add Point values.
	friend Point operator+ (const Point& point, const Point& point2);

	

public:
	Point();
	Point(int a, int b);

	//Setters
	void setX(int a);
	void setY(int b);

	//Getters
	int getX();
	int getY();


	//Functions
	//Displaying a point as a string (for later use in toString())
	string printPoint();
};

