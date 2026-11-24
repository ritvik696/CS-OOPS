#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

class Stack {
    unique_ptr<int[]> arr;                 // owns the array, frees it automatically
    int cap, top;
public:
    Stack(int c) : arr(make_unique<int[]>(c)), cap(c), top(-1) {}
    // no destructor, no copy constructor, no operator= needed (Rule of Zero)

    void push(int x) {
        if (top == cap - 1) throw overflow_error("Stack is full");
        arr[++top] = x;
    }
    int pop() {
        if (top == -1) throw underflow_error("Stack is empty");
        return arr[top--];
    }
};

int main() {
    auto s = make_unique<Stack>(3);        // the Stack object itself is also owned by a unique_ptr
    try {
        s->push(10); s->push(20); s->push(30);
        cout << "Pushed 10 20 30\n";
        s->push(40);                       // overflow
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
    try {
        for (int i = 0; i < 4; i++) cout << "Popped " << s->pop() << "\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
}   // no delete anywhere, and nothing leaks even when exceptions are thrown