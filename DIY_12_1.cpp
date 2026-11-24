#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> v = {
        {"Asha", 78}, {"Ravi", 91}, {"Meena", 85}, {"Kiran", 67}
    };

    sort(v.begin(), v.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second < b.second;      // ascending by marks
         });

    for (const auto& p : v)
        cout << p.first << " " << p.second << "\n";
}