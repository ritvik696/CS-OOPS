// race.cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex m;

void work() {
    for (int i = 0; i < 100000; i++) {
#ifdef USE_LOCK
        lock_guard<mutex> lock(m);         // released automatically at end of each iteration
#endif
        counter++;
    }
}

int main() {
    thread t1(work), t2(work);
    t1.join();
    t2.join();
    cout << "Total: " << counter << " (expected 200000)\n";
}