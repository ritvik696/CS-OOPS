#include <iostream>
using namespace std;

template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMax(T arr[], int n) {
    T mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

int main() {
    int a = 5, b = 9;
    swapVals(a, b);
    cout << "int swap: a=" << a << " b=" << b << "\n";

    double x = 2.5, y = 7.25;
    swapVals(x, y);
    cout << "double swap: x=" << x << " y=" << y << "\n";

    int ia[] = {3, 17, 9, 4, 11};
    double da[] = {1.5, 9.75, 3.25};
    cout << "Max int: "    << findMax(ia, 5) << "\n";
    cout << "Max double: " << findMax(da, 3) << "\n";
}