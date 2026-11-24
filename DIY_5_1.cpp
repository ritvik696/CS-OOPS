#include <iostream>
using namespace std;

class Counter {
private:
    int count;
    static int totalCreated;     // objects ever created
    static int alive;            // objects currently alive

public:
    Counter() : count(0) {
        totalCreated++;
        alive++;
    }

    // Copies are objects too, so they must be counted
    Counter(const Counter &other) : count(other.count) {
        totalCreated++;
        alive++;
    }

    ~Counter() {
        alive--;
    }

    void increment() { count++; }
    void reset()     { count = 0; }
    int  get() const { return count; }

    static int getTotalCreated() { return totalCreated; }
    static int getAlive()        { return alive; }
};

// Static members must be defined outside the class
int Counter::totalCreated = 0;
int Counter::alive = 0;

int main() {
    cout << "Start       -> created: " << Counter::getTotalCreated()
         << ", alive: " << Counter::getAlive() << endl;

    Counter a, b;
    cout << "After a, b  -> created: " << Counter::getTotalCreated()
         << ", alive: " << Counter::getAlive() << endl;

    {
        Counter arr[3];               // inner block
        arr[0].increment();
        cout << "Inside block-> created: " << Counter::getTotalCreated()
             << ", alive: " << Counter::getAlive() << endl;
    }                                 // arr destroyed here

    cout << "After block  -> created: " << Counter::getTotalCreated()
         << ", alive: " << Counter::getAlive() << endl;

    Counter *p = new Counter;
    cout << "After new    -> created: " << Counter::getTotalCreated()
         << ", alive: " << Counter::getAlive() << endl;
    delete p;

    cout << "After delete -> created: " << Counter::getTotalCreated()
         << ", alive: " << Counter::getAlive() << endl;
    return 0;
}