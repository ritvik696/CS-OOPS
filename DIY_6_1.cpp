#include <iostream>
using namespace std;

class Money {
    long rupees, paise;
    void normalize() {
        long total = rupees * 100 + paise;   // work in paise
        rupees = total / 100;
        paise  = total % 100;
    }
public:
    Money(long r = 0, long p = 0) : rupees(r), paise(p) { normalize(); }

    Money operator+(const Money& o) const {
        return Money(rupees + o.rupees, paise + o.paise);   // carry handled by normalize
    }
    Money operator-(const Money& o) const {
        return Money(rupees - o.rupees, paise - o.paise);   // borrow handled by normalize
    }
    void show() const { cout << "Rs " << rupees << "." << (paise < 10 ? "0" : "") << paise << "\n"; }
};

int main() {
    Money a(5, 75), b(3, 50);
    (a + b).show();   // Rs 9.25  (75+50 = 125 paise -> carry 1 rupee)
    (a - b).show();   // Rs 2.25
    (b - a).show();   // negative result: -2.25 gives rupees=-2, paise=-25 (see note)
}