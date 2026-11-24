#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double b) : balance(b) {}
    virtual double calculateInterest() const = 0;   // pure virtual -> Account is abstract
    virtual const char* type() const = 0;
    virtual ~Account() {}
};

class Savings : public Account {
public:
    Savings(double b) : Account(b) {}
    double calculateInterest() const override { return balance * 0.04; }   // 4%
    const char* type() const override { return "Savings"; }
};

class Current : public Account {
public:
    Current(double b) : Account(b) {}
    double calculateInterest() const override { return balance * 0.01; }   // 1%
    const char* type() const override { return "Current"; }
};

int main() {
    Account* accts[3] = { new Savings(10000), new Current(25000), new Savings(5000) };

    for (int i = 0; i < 3; i++)
        cout << accts[i]->type() << " interest: " << accts[i]->calculateInterest() << "\n";

    for (int i = 0; i < 3; i++) delete accts[i];   // safe because ~Account is virtual
    // Account a(100);   // error: cannot instantiate abstract class
}