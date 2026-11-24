#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    string name;
    int marks;
public:
    Student() : name(""), marks(0) {}
    Student(string n, int m) : name(n), marks(m) {}
    int getMarks() const { return marks; }
    void show() const { cout << name << " " << marks << "\n"; }
};

int main() {
    // Step 1: store name, marks pairs in a file
    {
        ofstream out("students.txt");
        out << "Asha 78\n" << "Ravi 91\n" << "Meena 85\n" << "Kiran 67\n";
    }   // file closed here when 'out' goes out of scope

    // Step 2: read them back into an array of Student objects
    ifstream in("students.txt");
    if (!in) { cerr << "Cannot open students.txt\n"; return 1; }

    const int MAX = 100;
    Student arr[MAX];
    string n;
    int m, count = 0;
    while (count < MAX && in >> n >> m)
        arr[count++] = Student(n, m);

    cout << "Records read: " << count << "\n";
    for (int i = 0; i < count; i++) arr[i].show();

    // Step 3: find the topper
    if (count > 0) {
        int top = 0;
        for (int i = 1; i < count; i++)
            if (arr[i].getMarks() > arr[top].getMarks()) top = i;
        cout << "Topper: ";
        arr[top].show();
    }
}