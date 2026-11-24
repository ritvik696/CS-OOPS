#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
    T* data;
    int cap, frontIdx, count;
public:
    Queue(int c) : data(new T[c]), cap(c), frontIdx(0), count(0) {}
    ~Queue() { delete[] data; }
    Queue(const Queue&) = delete;              // owns heap memory, so block shallow copies
    Queue& operator=(const Queue&) = delete;

    void enqueue(const T& x) {
        if (count == cap) throw runtime_error("Queue is full");
        data[(frontIdx + count) % cap] = x;    // circular buffer
        count++;
    }
    T dequeue() {
        if (count == 0) throw runtime_error("Queue is empty");
        T v = data[frontIdx];
        frontIdx = (frontIdx + 1) % cap;
        count--;
        return v;
    }
    T& front() {
        if (count == 0) throw runtime_error("Queue is empty");
        return data[frontIdx];
    }
    bool empty() const { return count == 0; }
};

int main() {
    Queue<string> q(3);
    q.enqueue("alpha");
    q.enqueue("beta");
    q.enqueue("gamma");

    cout << "Front: " << q.front() << "\n";
    cout << "Dequeued: " << q.dequeue() << "\n";
    cout << "Front: " << q.front() << "\n";

    q.enqueue("delta");                        // reuses the freed slot
    cout << "Enqueued: delta\n";

    try { q.enqueue("epsilon"); }
    catch (const runtime_error& e) { cout << "Error: " << e.what() << "\n"; }

    try {
        while (true) cout << "Dequeued: " << q.dequeue() << "\n";
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << "\n";
    }
}