#ifndef CPP_PRIORITYQUEUE_H
#define CPP_PRIORITYQUEUE_H
#include <iostream>
using namespace std;

struct Node {
	int data;
	int priority;
	Node* next;
	Node(int x, int p) {
		data = x;
		priority = p;
		next = nullptr;
	}
};
int peek(Node* head) {
	return head->data;
}
Node* pop(Node* head) {
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}
Node* push(Node* head, int d, int p) {
	Node* start = head;
	Node* temp = new Node(d, p);
	if (head == nullptr || head->priority > p) {
		temp->next = head;
		head = temp;
	}
	else {
		while (start->next != nullptr && start->next->priority <= p) {
			start = start->next;
		}
		temp->next = start->next;
		start->next = temp;
	}
	return head;
}
bool isEmpty(Node* head) {
	return (head == nullptr);
}

#endif