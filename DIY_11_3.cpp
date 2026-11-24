#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> freq;
    string w;

    cout << "Enter words (end with Ctrl+D, or Ctrl+Z then Enter on Windows):\n";
    while (cin >> w)
        freq[w]++;                             // missing key starts at 0

    string best;
    int bestCount = 0;
    for (const auto& p : freq) {
        cout << p.first << ": " << p.second << "\n";
        if (p.second > bestCount) { best = p.first; bestCount = p.second; }
    }

    if (bestCount > 0)
        cout << "Most frequent: " << best << " (" << bestCount << ")\n";
}