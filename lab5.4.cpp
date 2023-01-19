#include <iostream>
#include "Position.h"
#include "Circle.h"
#include "Square.h"
#include "CircleInSquare.h"

int main() {
	CircleInSquare cis(1, 2, 3);

	cis.print();
	cout << endl;
	cis.Circle::printData();
	cout << endl;
	cis.Square::printData();
	cout << endl;
	cis.changeCoordinate(3, 4);
	cis.print();
}