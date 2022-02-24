/*
Title: Chapter Thirteen rectangleType Program -- Implementation file
Created by William Schaeffer
CPS 362
P. 997, Challenge 2, rectangleType Program, Week 5
2.17.2022
*/

#include <iostream>
#include "rectangleTypeClassFriends.hpp"

using namespace std;

//non-member functions

//overload the stream insertion operator
	//friend function
ostream& operator << (ostream& osObj, const rectangleType& rectangle)
{
	osObj << "Length = " << rectangle.length
		  << "; Width = " << rectangle.width;

	return osObj;
}

//overload the stream extraction operator
	//friend function
istream& operator >> (istream& isObj, rectangleType& rectangle)
{

	isObj >> rectangle.length >> rectangle.width;

	return isObj;
}

//Overload Operators

//overload the + operator
	//friend function
rectangleType operator+(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	rectangleType tempRec;

	tempRec.length = rectangleOne.length + rectangleTwo.length;
	tempRec.width = rectangleOne.width + rectangleTwo.width;

	return tempRec;
}

//overload the - operator
	//friend function
rectangleType operator-(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	rectangleType tempRec;
	double l, w;											//length and width values to test for negative

	l = rectangleOne.length - rectangleTwo.length;

	w = rectangleOne.width - rectangleTwo.width;

	if (l >= 0 && w >= 0)
		tempRec.setDimension(l, w);
	else
		cout << "Cannot perform operations that result in negative length or width.\n\n";

	return tempRec;
}

//overload the * operator
	//friend function
rectangleType operator*(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	rectangleType tempRec;

	tempRec.length = rectangleOne.length * rectangleTwo.length;
	tempRec.width = rectangleOne.width * rectangleTwo.width;

	return tempRec;
}

//overload the == operator
	//friend function
bool operator==(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	return ((rectangleOne.area()) == (rectangleTwo.area()));
}

//overload the != operator
	//friend function
bool operator!=(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	return ((rectangleOne.area()) != (rectangleTwo.area()));
}

//overload the <= operator
	//friend function
bool operator<=(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	return ((rectangleOne.area()) <= (rectangleTwo.area()));
}

//overload the < operator
	//friend function
bool operator<(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	return ((rectangleOne.area()) < (rectangleTwo.area()));
}

//overload the >= operator
	//friend function
bool operator>=(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	return ((rectangleOne.area()) >= (rectangleTwo.area()));
}

//overload the > operator
	//friend function
bool operator>(const rectangleType& rectangleOne, const rectangleType& rectangleTwo)
{
	return ((rectangleOne.area()) > (rectangleTwo.area()));
}

//overload the pre-increment operator
	//friend function
rectangleType& operator++(rectangleType& rectangle)
{
	++(rectangle.length);
	++(rectangle.width);

	return rectangle;
}

//overload the post-increment operator
	//friend function
rectangleType operator++(rectangleType& rectangle, int dummy)
{
	rectangleType temp = rectangle;

	(rectangle.length)++;
	(rectangle.width)++;

	return temp;
}

//overload the pre-decrement operator
	//friend function
rectangleType& operator--(rectangleType& rectangle)
{
	if ((rectangle.length) >= 1)
	{
		--(rectangle.length);
	}
	else
	{
		cout << "Cannot use pre-decrement operator to create negative length value.\n\n";
	}

	if ((rectangle.width) >= 1)
	{
		--(rectangle.width);
	}
	else
	{
		cout << "Cannot use pre-decrement operator to create negative width value.\n\n";
	}

	return rectangle;
}

//overload the post-decrement operator
	//friend function
rectangleType operator--(rectangleType& rectangle, int dummy)
{
	rectangleType temp = rectangle;

	if ((rectangle.length)-- >= 1)
	{
		(rectangle.length)--;
	}
	else
	{
		cout << "Cannot use post-decrement operator to create negative length value.\n\n";
	}

	if ((rectangle.width) >= 1)
	{
		(rectangle.width)--;
	}
	else
	{
		cout << "Cannot use post-decrement operator to create negative width value.\n\n";
	}

	return temp;
}

//Member functions
double rectangleType::area() const
{
	return length * width;
}

double rectangleType::perimeter() const
{
	return 2 * (length + width);
}

void rectangleType::print() const
{
	cout << "Length = " << length << "and Width = " << width;
}

//Setter or Mutator

void rectangleType::setDimension(double l, double w)
{
	if (l >= 0)
	{
		length = l;
	}
	else
	{
		while (l <= 0)
		{
			cout << "Invalid length entered. Please enter a non-negative value: ";
			cin >> l;
		}	
		length = l;
	}
		

	if (w >= 0)
	{
		width = w;
	}
	else
	{
		while (w <= 0)
		{
			cout << "Invalid width entered. Plese enter a non-negative value: ";
			cin >> w;
		}
		width = w;
	}
		
}

//Getter or Accessor

double rectangleType::getLength() const
{
	return length;
}

double rectangleType::getWidgth() const
{
	return width;
}

//Constructors

	//default constructor
rectangleType::rectangleType()
{
	length = 0;
	width = 0;
}

	//parameterized constructor
rectangleType::rectangleType(double l, double w)
{
	setDimension(l, w);
}