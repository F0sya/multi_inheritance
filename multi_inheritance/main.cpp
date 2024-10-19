#include <iostream>
using namespace std;


class Square {
protected:
	int side;

public:
	Square(int s) : side(s) {}
	virtual ~Square() {
		cout << "Class Square destructor called" << endl;
	}
	virtual int getSide() const {
		return side;
	}
	virtual double getArea() const {
		return side * side;
	}
	virtual int getPerimeter() const {
		return 4 * side;
	}
};

class Circle {
protected:
	int radius;

public:
	Circle(int r) : radius(r) {}
	virtual ~Circle() {
		cout << "Class Circle destructor called" << endl;
	}
	virtual int getRadius() const {
		return radius;
	}
	virtual double getArea() const {
		return 3.14 * radius * radius;
	}
	virtual int getLength() const {
		return 2 * 3.14 * radius;
	}
};

class CircleInSquare : public Square, public Circle {
public:
	CircleInSquare(int side) :  Square(side), Circle(side / 2) {}
	~CircleInSquare() {
		cout << "Class CircleInSquare destructor called" << endl;
	}

	void show() const {
		cout << "Square parameters:\n"
			"-Square side:" << getSide() << "\n"
			"-Square area:" << Square::getArea() << "\n"
			"-Square perimeter:" << Square::getPerimeter() << "\n"
			"Circle parameters:\n"
			"-Circle radius:" << getRadius() << "\n"
			"-Circle area:" << Circle::getArea() << "\n" <<
			"-Circle length:" << Circle::getLength() << "\n" << endl;
	}
};


int main() {
	CircleInSquare* size = new CircleInSquare(10);

	size->show();

	delete size;
	return 0;

}