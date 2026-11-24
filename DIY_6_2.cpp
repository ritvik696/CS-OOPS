#include <iostream>
#include <stdexcept>
using namespace std;

int gcd(int a, int b) { a = abs(a); b = abs(b); return b == 0 ? a : gcd(b, a % b); }

class Fraction {
    int num, den;
    void simplify() {
        if (den == 0) throw invalid_argument("Denominator cannot be zero");
        if (den < 0) { num = -num; den = -den; }   // keep sign in numerator
        int g = gcd(num, den);
        if (g > 1) { num /= g; den /= g; }
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { simplify(); }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.num << "/" << f.den;
        return out;
    }
    friend istream& operator>>(istream& in, Fraction& f) {
        char slash;
        in >> f.num >> slash >> f.den;   // input like 6/8
        f.simplify();
        return in;
    }
};

int main() {
    Fraction f;
    cout << "Enter fraction (a/b): ";
    cin >> f;
    cout << "Simplified: " << f << "\n";   // 6/8 -> 3/4
}