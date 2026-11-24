// leak.cpp
#include <iostream>
using namespace std;

#ifndef VIRT
#define VIRT            // empty by default -> non-virtual destructor (the bug)
#endif

class Base {
public:
    Base() { cout << "Base ctor\n"; }
    VIRT ~Base() { cout << "Base dtor\n"; }
};

class Derived : public Base {
    int* buf;
public:
    Derived() : buf(new int[100]) { cout << "Derived ctor (allocated 400 bytes)\n"; }
    ~Derived() { delete[] buf; cout << "Derived dtor (freed)\n"; }
};

int main() {
    Base* p = new Derived;
    delete p;           // deleting a Derived through a Base*
}