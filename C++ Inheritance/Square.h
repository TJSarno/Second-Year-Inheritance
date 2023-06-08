#pragma once
#include "Shape.h"
#include "Point.h"
#include "Movable.h"
class Square : public Shape, public Movable
{
	double edge;
	
public:
	Square(int a, int b, double c);
	~Square();

	//Setters
	void setEdge(double e);

	//Getters
	double getEdge();
	//Functions
	void calculateArea();

	void calculatePerimeter();

	void calculatePoints();

	string toString();

	//Movable functions
	void move(int a, int b);

	void scale(double d);
};

