#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}
    void display() const {
        cout << "Name: " << name << ", ID: " << id << "\n";
    }
};

class Manager : public Employee {
    int teamSize;
public:
    Manager(string n, int i, int t) : Employee(n, i), teamSize(t) {}
    void display() const {
        cout << "[Manager] ";
        Employee::display();
        cout << "Team size: " << teamSize << "\n";
    }
};

class Engineer : public Employee {
    string skill;
public:
    Engineer(string n, int i, string s) : Employee(n, i), skill(s) {}
    void display() const {
        cout << "[Engineer] ";
        Employee::display();
        cout << "Skill: " << skill << "\n";
    }
};

int main() {
    Manager m("Asha", 101, 8);
    Engineer e("Ravi", 102, "C++");
    m.display();
    cout << "\n";
    e.display();
}