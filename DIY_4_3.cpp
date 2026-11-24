#include <iostream>
using namespace std;

class Tracer {
private:
    int id;

public:
    Tracer(int i) : id(i) {
        cout << "  Tracer " << id << " created\n";
    }
    ~Tracer() {
        cout << "  Tracer " << id << " destroyed\n";
    }
};

int main() {
    const bool FORGET_DELETE = false;     // change to true to see the leak

    for (int i = 1; i <= 3; i++) {
        Tracer *t = new Tracer(i);

        if (!FORGET_DELETE)
            delete t;                     // destructor runs here
        // else: pointer t goes out of scope, memory is lost forever
    }

    cout << "Loop finished\n";
    return 0;
}