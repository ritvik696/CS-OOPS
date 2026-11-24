#include <iostream>
#include <stdexcept>
using namespace std;

class MathError : public runtime_error {
public:
    MathError(const string& m) : runtime_error(m) {}
};
class DivideByZero : public MathError {
public:
    DivideByZero() : MathError("Division by zero") {}
};

int divide(int a, int b) {
    if (b == 0) throw DivideByZero();
    return a / b;
}

int main() {
    try {
        divide(10, 0);
    }
    catch (const DivideByZero& e)  { cout << "DivideByZero handler: " << e.what() << "\n"; }
    catch (const MathError& e)     { cout << "MathError handler: " << e.what() << "\n"; }
}
