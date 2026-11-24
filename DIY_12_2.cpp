#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;   // smallest on top

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minHeap.push(x);
        if (minHeap.size() > 3) minHeap.pop();   // drop the smallest, keep the 3 largest
    }

    vector<int> top;
    while (!minHeap.empty()) {
        top.push_back(minHeap.top());
        minHeap.pop();
    }

    cout << "Top " << top.size() << ": ";
    for (int i = top.size() - 1; i >= 0; i--) cout << top[i] << " ";   // heap gave ascending
    cout << "\n";
}