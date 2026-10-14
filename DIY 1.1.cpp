#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    int vowels = 0, consonants = 0;

    cout << "Enter a sentence: ";
    getline(cin, s);

    for (char c : s) {
        c = tolower(c);

        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    return 0;
}