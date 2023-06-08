#pragma once
#include "Point.h"
#include <vector>
class Shape
{
protected:
	//Basic shape properties
	double area;
	double perimeter;
	bool isCircular = false;
	
	//Points

	Point leftTop;
	Point rightTop;
	Point rightBottom;
	Point leftBottom;
	


	
public:
	
	//Constructor
	Shape();

	//Setters
	void setleftTop(Point);
	void setrightTop(Point);
	void setrightBottom(Point);
	void setleftBottom(Point);
	void setArea(double);
	void setPerimeter(double);
	void setisCircular(bool);

	//Getters
	Point getleftTop();
	Point getrightTop();
	Point getrightBottom();
	Point getleftBottom();
	double getArea();
	double getPerimeter();
	
	//Functions

	//Virtual functions to be overidden
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual void calculatePoints();
	virtual string toString();

};

