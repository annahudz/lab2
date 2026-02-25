#ifndef CPP_FIXEDSTACK_H
#define CPP_FIXEDSTACK_H
#include "Circle.h"
#include <iostream>
using namespace std;

class FixedStack {
private:
	static const int MAX_SIZE = 10000;
	Circle arr[MAX_SIZE];
	int topIndex = -1;

public:
	void create_empty() {
		topIndex = -1;
	}
	bool is_empty() const {
		return topIndex == -1;
	}
	bool push(const Circle& c ) {
		if (topIndex >= MAX_SIZE - 1) {
			cout << "Error: Stack overlow" << endl;
			return false;
		}
		arr[++topIndex] = c;
		return true;
	}
	bool pop(Circle& out) {
		if (is_empty()) {
			cout << "Error: Stack overflow" << endl;
			return false;
		}
		out = arr[topIndex--];
		return true;
	}
	bool peek(Circle& out) const {
		if (is_empty()) {
			cout << "Error:Stack is empty" << endl;
			return false;
		}
		out = arr[topIndex];
		return true;
	}
};

#endif