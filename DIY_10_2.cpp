#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    if (!in || !out) { cerr << "File error\n"; return 1; }

    string line;
    int n = 1;
    while (getline(in, line))          // getline keeps spaces, unlike >>
        out << n++ << ": " << line << "\n";

    cout << "Copied " << n - 1 << " lines to out.txt\n";
}