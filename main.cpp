#include <iostream>
#include <chrono>
#include "Circle.h"
#include "FixedStack.h"
#include "VectorStack.h"
#include "ListStack.h"
#include "PriorityQueue.h"

using namespace std;
using namespace std::chrono;

// =======================
// STACK FUNCTIONS
// =======================
template <typename StackType>
void demoStack(StackType& stack) {
    Circle c1{ 1,1,1 }, c2{ 2,2,2 }, c3{ 3,3,3 };
    Circle tmp{};
    cout << "\n=== Demo Mode Stack ===\n";
    stack.create_empty();
    cout << "Stack created empty\n";
    stack.push(c1); stack.push(c2); stack.push(c3);
    cout << "Pushed 3 circles\n";
    if (stack.peek(tmp)) { cout << "Top element: "; tmp.print(); }
    while (!stack.is_empty()) { stack.pop(tmp); cout << "Popped: "; tmp.print(); }
    cout << "Stack is empty\n";
}

template <typename StackType>
void interactiveStack(StackType& stack) {
    int initialCount = 0;
    cout << "How many circles do you want to add initially? ";
    cin >> initialCount;

    Circle tmp{};
    for (int i = 0; i < initialCount; i++) {
        Circle c{};
        cout << "Enter Circle " << i + 1 << " (x y r): ";
        cin >> c.x >> c.y >> c.r;
        stack.push(c);
        cout << "Pushed: "; c.print();
        if (stack.peek(tmp)) { cout << "Top element now: "; tmp.print(); }
    }

    int choice = 0;
    do {
        cout << "\n1 Push\n2 Pop\n3 Peek\n4 Is empty\n0 Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Circle c{};
            cout << "Enter x y r: ";
            cin >> c.x >> c.y >> c.r;
            stack.push(c);
            cout << "Pushed: "; c.print();
            if (stack.peek(tmp)) { cout << "Top element now: "; tmp.print(); }
            break;
        }
        case 2:
            if (!stack.is_empty() && stack.pop(tmp)) {
                cout << "Popped: "; tmp.print();
                if (!stack.is_empty() && stack.peek(tmp)) { cout << "Top element now: "; tmp.print(); }
                else cout << "Stack is now empty\n";
            }
            else cout << "Stack empty\n";
            break;
        case 3:
            if (!stack.is_empty() && stack.peek(tmp)) {
                cout << "Top element: "; tmp.print();
            }
            else cout << "Stack empty\n";
            break;
        case 4:
            cout << (stack.is_empty() ? "Empty\n" : "Not empty\n");
            break;
        }
    } while (choice != 0);
}

// =======================
// PRIORITY QUEUE FUNCTIONS
// =======================
void demoPriorityQueue() {
    Node* pq = nullptr;
    pq = push(pq, 4, 2);
    pq = push(pq, 5, 1);
    pq = push(pq, 6, 3);
    pq = push(pq, 3, 0);
    cout << "Priority Queue Demo: ";
    while (!isEmpty(pq)) { cout << peek(pq) << " "; pq = pop(pq); }
    cout << endl;
}


void interactivePriorityQueueDemoStyle() {
    Node* pq = nullptr;
    int n = 0;
    cout << "How many elements do you want to add? ";
    cin >> n;

    cout << "Enter " << n << " values followed by " << n << " priorities:\n";

    int* values = new int[n];
    int* priorities = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Value " << i + 1 << ": ";
        cin >> values[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "Priority " << i + 1 << ": ";
        cin >> priorities[i];
    }

    for (int i = 0; i < n; i++) {
        pq = push(pq, values[i], priorities[i]);
        cout << "Pushed: Value=" << values[i] << ", Priority=" << priorities[i] << endl;
    }

    cout << "\nPriority Queue in order (highest priority first): ";
    while (!isEmpty(pq)) {
        cout << peek(pq) << " ";
        pq = pop(pq);
    }
    cout << endl;

    delete[] values;
    delete[] priorities;
}

// =======================
// BENCHMARK
// =======================
template <typename StackType>
void benchmarkStack(const string& name, int N) {
    StackType stack{};
    Circle c{ 1,2,3 }, tmp{};

    cout << "\n===== " << name << " =====\n";
    stack.create_empty();

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) stack.push(c);
    auto end = high_resolution_clock::now();
    cout << "Push: " << duration<double>(end - start).count() << " sec\n";

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) { if (!stack.is_empty()) stack.pop(tmp); }
    end = high_resolution_clock::now();
    cout << "Pop: " << duration<double>(end - start).count() << " sec\n";

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) { if (!stack.is_empty()) stack.peek(tmp); }
    end = high_resolution_clock::now();
    cout << "Peek: " << duration<double>(end - start).count() << " sec\n";

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) stack.is_empty();
    end = high_resolution_clock::now();
    cout << "IsEmpty: " << duration<double>(end - start).count() << " sec\n";

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) stack.create_empty();
    end = high_resolution_clock::now();
    cout << "CreateEmpty: " << duration<double>(end - start).count() << " sec\n";
}

void fullBenchmarkStack() {
    const int N=10000;
    benchmarkStack<FixedStack>("Fixed Array", N);
    benchmarkStack<VectorStack>("Vector", N);
    benchmarkStack<ListStack>("Linked List", N);
}

void benchmarkPriorityQueue() {
    Node* pq = nullptr;
    const int N = 10000;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) pq = push(pq, i, i % 100);
    while (!isEmpty(pq)) pq = pop(pq);
    auto end = high_resolution_clock::now();
    cout << "Priority Queue Benchmark\nOperations: " << N << "\nTime: "
        << duration<double>(end - start).count() << " sec\n";
}

// =======================
// MAIN
// =======================
int main() {
    int labChoice = 0;
    cout << "Select Lab:\n1 Lab A (Stack)\n2 Lab B (Priority Queue)\nChoice: ";
    cin >> labChoice;

    if (labChoice == 1) {
        int mode = 0, s = 0;
        cout << "\nLab A (Stack) - Select Mode:\n1 Demo\n2 Interactive\n3 Benchmark\nChoice: ";
        cin >> mode;

        if (mode == 1) {
            FixedStack fs{}; VectorStack vs{}; ListStack ls{};
            demoStack(fs); demoStack(vs); demoStack(ls);
        }
        else if (mode == 2) {
            cout << "Select stack: 1 Fixed 2 Vector 3 List: "; cin >> s;
            if (s == 1) { FixedStack fs{}; interactiveStack(fs); }
            else if (s == 2) { VectorStack vs{}; interactiveStack(vs); }
            else if (s == 3) { ListStack ls{}; interactiveStack(ls); }
        }
        else if (mode == 3) fullBenchmarkStack();
        else cout << "Invalid choice\n";
    }
    else if (labChoice == 2) {
        int mode = 0;
        cout << "\nLab B (Priority Queue) - Select Mode:\n1 Demo\n2 Interactive\n3 Benchmark\nChoice: ";
        cin >> mode;

        if (mode == 1) demoPriorityQueue();
        else if (mode == 2) interactivePriorityQueueDemoStyle();
        else if (mode == 3) benchmarkPriorityQueue();
        else cout << "Invalid choice\n";
    }
    else cout << "Invalid lab choice\n";

    return 0;
}
