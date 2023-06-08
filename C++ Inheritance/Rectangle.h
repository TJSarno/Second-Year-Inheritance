#pragma once
#include "Shape.h"
#include "Point.h"
#include "Movable.h"
class Rectangle : public Shape, public Movable
{
	double width;
	double height;
	
public:
	Rectangle(int a, int b, int c, int d);
	~Rectangle();
	
	//Getters
	void setHeight(double h);
	void setWidth(double w);

	//Setters
	double getHeight();
	double getWidth();

	//Functions
	void calculateArea();

	void calculatePerimeter();

	void calculatePoints();

	string toString();

	//Movable functions
	void move(int a, int b);

	void scale(double d, double e);
};

