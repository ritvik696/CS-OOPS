#include <iostream>
using namespace std;

class Time {
private:
    int hh, mm;

public:
    Time(int h = 0, int m = 0) : hh(h), mm(m) {}

    void display() const {
        if (hh < 10) cout << '0';
        cout << hh << ':';
        if (mm < 10) cout << '0';
        cout << mm;
    }

    // friend: not a member, but can read private hh and mm
    friend Time laterOf(Time t1, Time t2);
};

Time laterOf(Time t1, Time t2) {
    int m1 = t1.hh * 60 + t1.mm;     // private access allowed (friend)
    int m2 = t2.hh * 60 + t2.mm;
    return (m1 >= m2) ? t1 : t2;
}

int main() {
    Time a(9, 45), b(14, 5), c(14, 5), d(8, 30);

    Time later = laterOf(a, b);
    cout << "Later of 09:45 and 14:05 = ";
    later.display();
    cout << endl;

    later = laterOf(d, a);
    cout << "Later of 08:30 and 09:45 = ";
    later.display();
    cout << endl;

    later = laterOf(b, c);
    cout << "Later of 14:05 and 14:05 = ";
    later.display();
    cout << " (equal times)" << endl;

    return 0;
}