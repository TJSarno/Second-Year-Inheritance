#pragma once
#include "Shape.h"
#include "Point.h"
#include "Movable.h"
class Circle : public Shape, public Movable
{
	double radius;

	public:
	Circle(int a, int b, double c);

	//Setters
	void setRadius(double r);
	
	//Getters
	double getRadius();

	//Functions
	void calculateArea();

	void calculatePerimeter();

	void calculatePoints();

	string toString();

	//Movable Functions
	void move(int a, int b);

	void scale(double d);

};


