#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int capacity;
    int topIndex;

    void grow() {
        int newCap = capacity * 2;
        int *bigger = new int[newCap];
        for (int i = 0; i <= topIndex; i++)
            bigger[i] = arr[i];
        delete[] arr;
        arr = bigger;
        capacity = newCap;
    }

public:
    Stack(int cap = 4) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
    }

    // Stack owns a buffer, so copying is blocked (a shallow copy would double free)
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
        delete[] arr;
        cout << "Stack buffer released\n";
    }

    void push(int x) {
        if (topIndex + 1 == capacity)
            grow();
        arr[++topIndex] = x;
    }

    bool pop(int &out) {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return false;
        }
        out = arr[topIndex--];
        return true;
    }

    bool isEmpty() const { return topIndex == -1; }
    int  size()    const { return topIndex + 1; }
};

int main() {
    Stack s;                          // initial capacity 4

    for (int i = 1; i <= 6; i++)      // 6 pushes force one resize
        s.push(i * 10);
    cout << "Size after pushes: " << s.size() << endl;

    int x;
    cout << "Popping: ";
    while (s.pop(x))
        cout << x << " ";
    cout << endl;

    return 0;
}