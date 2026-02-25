#ifndef CPP_VECTORSTACK_H
#define CPP_VECTORSTACK_H 
#include <iostream>
#include <vector>
#include "Circle.h"

using namespace std;

class VectorStack {
private:
	vector<Circle> data;
public:
	void create_empty() {
		data.clear();
	}
	bool is_empty() const {
		return data.empty();
	}
	bool push(const Circle& c) {
		data.push_back(c);
		return true;
	}
	bool pop(Circle& out) {
		if (is_empty()) {
			cout << "Error: Stack overflow" << endl;
		}
		out = data.back();
		data.pop_back();
		return true;
	}
	bool peek(Circle& out) {
		if (is_empty()) {
			cout << "Error: Stack is empty" << endl;
			return false;
		}
		out = data.back();
		return true;
	}
};
#endif