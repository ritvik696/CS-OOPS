#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) { cout << "Person constructor: " << name << "\n"; }
    ~Person() { cout << "Person destructor\n"; }
};

class Student : virtual public Person {
protected:
    int roll;
public:
    Student(string n, int r) : Person(n), roll(r) { cout << "Student constructor\n"; }
    ~Student() { cout << "Student destructor\n"; }
};

class Employee : virtual public Person {
protected:
    int empId;
public:
    Employee(string n, int e) : Person(n), empId(e) { cout << "Employee constructor\n"; }
    ~Employee() { cout << "Employee destructor\n"; }
};

class TA : public Student, public Employee {
public:
    // most-derived class initialises the virtual base directly
    TA(string n, int r, int e) : Person(n), Student(n, r), Employee(n, e) {
        cout << "TA constructor\n";
    }
    void show() const {
        cout << "Name: " << name << ", Roll: " << roll << ", Emp ID: " << empId << "\n";
    }
    ~TA() { cout << "TA destructor\n"; }
};

int main() {
    TA t("Meena", 21, 7);
    t.show();
}