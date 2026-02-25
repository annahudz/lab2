#ifndef CPP_CIRCLE_H
#define CPP_CIRCLE_H
#include <iostream>
using namespace std;
struct Circle {
	double x;
	double y;
	double r;
	void print() const {
		cout << "Circle (x= " << x << ", y=" << y << ",r=" << r << endl;
	}
};
#endif