/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file. 
During marking, we will use the exact same notation 
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't 
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK! 

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>
#include <vector>

#pragma warning (disable : 4996)

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands


		while (userCommand.compare("exit") != 0)
		{
			cout << "Enter the command: ";

			getline(cin, userCommand);

			char* cstr = new char[userCommand.length() + 1];

			strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

			//String tokenizer
			char* token;
			token = strtok(cstr, " ");

			//Creating and assigning multiple tokens
			while (token != NULL) {
				parameters.push_back(token);
				token = strtok(NULL, " ");
			}

			//Assigning command as the first value in parameters
			string command = parameters[0];
			//Getting size of parameters to compare to later.
			int parametersSize = parameters.size();

			//Getting size of shapes to compare to later.
			int shapesSize = shapes.size();

			// in the following code, consider checking for the arguments.
			// in case of too few arguments, you may remind the user the correct format

			if (command.compare("addR") == 0) {

				if (parametersSize < 5)
				{
					//Error message displayed to user
					cout << "Not enough parameters entered to construct a rectangle." << "\n";
					cout <<	"Please ensure you are adding 4 parameters" << "\n";
					cout << "Example input:  addR 150 50 25 25" << "\n";
					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}
				else if (parametersSize > 5) {
					cout << "Too many parameters entered. Any after the fourth ignored." << "\n";
					//Populating parameters for rectangle
					int x = std::stoi(parameters[1]);
					int y = std::stoi(parameters[2]);
					double h = std::stod(parameters[3]);
					double w = std::stod(parameters[4]);


					Rectangle* r = new Rectangle(x, y, h, w);
					shapes.push_back(r);
					cout << r->toString();
					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}
				else {
					//Populating parameters for rectangle
					int x = std::stoi(parameters[1]);
					int y = std::stoi(parameters[2]);
					double h = std::stod(parameters[3]);
					double w = std::stod(parameters[4]);


					Rectangle* r = new Rectangle(x, y, h, w);
					shapes.push_back(r);
					cout << r->toString();
					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}
				

			}

			else if (command.compare("addS") == 0) {
				if (parametersSize < 4)
				{
					//Error message: Not enough parameters displayed to user
					cout << "Not enough parameters entered to construct a square." << "\n";
					cout << "Please ensure you are adding 3 parameters" << "\n";
					cout << "Example input:  addS 100 75 15" << "\n";
					//Clearing parameters to allow new shapes to be created.
					parameters.clear();	
					cout << "\n";
				}
				else if (parametersSize > 4) {
					//Error message: Too many parameters displayed to user
					cout << "Too many parameters entered. Any after the third ignored." << "\n";
					//Square is created as usual, ignoring extra parameters.
					int x = std::stoi(parameters[1]);
					int y = std::stoi(parameters[2]);
					double e = std::stod(parameters[3]);

					Square* s = new Square(x, y, e);
					shapes.push_back(s);
					cout << s->toString();

					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}

				else {
					//Populating parameters for Square
					int x = std::stoi(parameters[1]);
					int y = std::stoi(parameters[2]);
					double e = std::stod(parameters[3]);

					Square* s = new Square(x, y, e);
					shapes.push_back(s);
					cout << s->toString();

					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}
				

			}

			if (command.compare("addC") == 0) {
				if (parametersSize < 4)
				{
					//Error message: Not enough parameters displayed to user
					cout << "Not enough parameters entered to construct a circle." << "\n";
					cout << "Please ensure you are adding 3 parameters" << "\n";
					cout << "Example input:  addC 250 50 30" << "\n";
					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}
				else if (parametersSize > 4) {
					//Error message: Too many parameters displayed to user
					cout << "Too many parameters entered. Any after the third ignored." << "\n";
					//Circle is created as usual, ignoring extra parameters.
					int x = std::stoi(parameters[1]);
					int y = std::stoi(parameters[2]);
					double r = std::stod(parameters[3]);

					Circle* c = new Circle(x, y, r);
					shapes.push_back(c);
					cout << c->toString();

					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";

				}
				else {
					int x = std::stoi(parameters[1]);
					int y = std::stoi(parameters[2]);
					double r = std::stod(parameters[3]);

					Circle* c = new Circle(x, y, r);
					shapes.push_back(c);
					cout << c->toString();

					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}
				



			}
			else if (command.compare("scale") == 0) {
				int shapeNo = std::stod(parameters[1]);

				//Assigning the values to be changed by
				int x = std::stod(parameters[2]);
				int y = std::stod(parameters[3]);

				if (parametersSize < 4)
				{
					//Error message: Not enough parameters displayed to user
					cout << "Not enough parameters entered to scale a shape." << "\n";
					cout << "Please ensure you are adding 3 parameters" << "\n";
					cout << "Example input:  scale 1 2 2" << "\n";
					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}

				else if(shapesSize < 1) {
					//Displaying error: No shapes currently exist, then prompted to create a shape.
					cout << "No shapes currently exist, please create a shape before using this function" "\n";
					parameters.clear();
					cout << "\n";
				}
				else if(shapeNo > shapesSize){
					//Display error: No shapes exist at that index.
					cout << "No shapes currently exist at that index." "\n";
					cout << "Create more shapes or try a different index." "\n";
					parameters.clear();
					cout << "\n";
				}
				else {
					Movable* k = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
					k->scale(x, y);
					cout << shapes[shapeNo - 1]->toString();
					parameters.clear();
					cout << "\n";
				}


				

			}
			else if (command.compare("move") == 0) {
				// move object at index 

				//Assigning parameters to allow movable to work
				//Selecting the shape from parameters
				int shapeNo = std::stoi(parameters[1]);

				//Assigning the values to be changed by
				double x = std::stod(parameters[2]);
				double y = std::stod(parameters[3]);

				// you may want to check if the index exists or not!

				// Study the following code. A Shape object is not Movable, but all derived classes are...
				// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting

				if (parametersSize < 4)
				{
					//Error message: Not enough parameters displayed to user
					cout << "Not enough parameters entered to scale a shape." << "\n";
					cout << "Please ensure you are adding 3 parameters" << "\n";
					cout << "Example input:  scale 1 2 2" << "\n";
					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}

				else if (shapesSize < 1) {
					//Displaying error: No shapes currently exist, then prompted to create a shape.
					cout << "No shapes currently exist, please create a shape before using this function" "\n";
					parameters.clear();
					cout << "\n";
				}
				else if (shapeNo > shapesSize) {
					//Display error: No shapes exist at that index.
					cout << "No shapes currently exist at that index." "\n";
					cout << "Create more shapes or try a different index." "\n";
					parameters.clear();
					cout << "\n";
				}
				else {
					Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
					m->move(x, y);
					cout << shapes[shapeNo - 1]->toString();
					//Clearing parameters to allow new shapes to be created.
					parameters.clear();
					cout << "\n";
				}
				

			}

			else if (command.compare("display") == 0) {
				//For loop to tostring() every shape in shapes
				for (int i = 0; i < shapesSize; i++)
				{
					cout << shapes[i]->toString();
					cout << "\n";
				}
				//Clearing parameters to allow new shapes to be created.
					parameters.clear();
			}

			

			//}
		}
	

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
