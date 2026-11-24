#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int* data;
    size_t size;
public:
    SafeArray(size_t n) : size(n), data(new int[n]()) {}   // () zero-initialises
    SafeArray(const SafeArray& o) : size(o.size), data(new int[o.size]) {   // deep copy
        for (size_t i = 0; i < size; i++) data[i] = o.data[i];
    }
    SafeArray& operator=(const SafeArray& o) {
        if (this != &o) {
            delete[] data;
            size = o.size;
            data = new int[size];
            for (size_t i = 0; i < size; i++) data[i] = o.data[i];
        }
        return *this;
    }
    ~SafeArray() { delete[] data; }

    int& operator[](size_t i) {
        if (i >= size) throw out_of_range("Index out of range");
        return data[i];
    }
    const int& operator[](size_t i) const {
        if (i >= size) throw out_of_range("Index out of range");
        return data[i];
    }
};

int main() {
    SafeArray arr(5);
    arr[2] = 42;
    cout << arr[2] << "\n";
    try {
        arr[10] = 1;                       // out of range
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << "\n";
    }
}