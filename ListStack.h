#ifndef CPP_LISTSTACK_H
#define CPP_LISTSTACK_H
#include <iostream>
#include "Circle.h"
using namespace std;

class ListStack {
private: 
	struct Node {
		Circle data;
		Node* next;
	};
	Node* head = nullptr;
public:
	~ListStack() {
		Circle tmp;
		while (!is_empty()) pop(tmp);
	}
	void create_empty() {
		Circle tmp;
		while (!is_empty()) pop(tmp);
	}
	bool is_empty() const {
		return head == nullptr;
	}
	bool push(const Circle& c) {
		Node* temp = new Node;
		temp->data = c;
		temp->next = head;
		head = temp;
		return true;
	}
	bool pop(Circle& out) {
		if (is_empty()) {
			cout << "Error: Stack underflow" << endl;
			return false;
		}
		Node* temp = head;
		out = head->data;
		head = head->next;
		delete temp;
		return true;
	}
	bool peek(Circle& out) {
		if (is_empty()) return false;
		out = head->data;
		return true;
	}
};
#endif