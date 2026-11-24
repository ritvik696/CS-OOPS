#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main() {
    ifstream in("nums.txt");
    if (!in) { cerr << "Cannot open nums.txt\n"; return 1; }

    int x, count = 0, mn = INT_MAX, mx = INT_MIN;
    long long sum = 0;

    while (in >> x) {              // stops at EOF or bad input, so the count can be unknown
        count++;
        sum += x;
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }

    if (count == 0) { cout << "File has no integers\n"; return 0; }

    cout << "Count: " << count << "\n"
         << "Sum:   " << sum   << "\n"
         << "Min:   " << mn    << "\n"
         << "Max:   " << mx    << "\n";
}