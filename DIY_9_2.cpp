#include <iostream>
using namespace std;

class Overflow  { public: const char* what() const { return "stack is full"; } };
class Underflow { public: const char* what() const { return "stack is empty"; } };

class Stack {
    int arr[3];
    int top;
public:
    Stack() : top(-1) {}
    void push(int x) {
        if (top == 2) throw Overflow();
        arr[++top] = x;
    }
    int pop() {
        if (top == -1) throw Underflow();
        return arr[top--];
    }
};

int main() {
    Stack s;
    try {
        for (int i = 10; i <= 40; i += 10) {
            s.push(i);
            cout << "Pushed " << i << "\n";
        }
    } catch (const Overflow& e) {
        cout << "Caught Overflow: " << e.what() << " (capacity 3)\n";
    }

    try {
        for (int i = 0; i < 4; i++)
            cout << "Popped " << s.pop() << "\n";
    } catch (const Underflow& e) {
        cout << "Caught Underflow: " << e.what() << "\n";
    }
}