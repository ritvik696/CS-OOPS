#include <iostream>
#include <string>
using namespace std;

class InsufficientFunds : public exception {
    string msg;
public:
    InsufficientFunds(int balance, int requested)
        : msg("Insufficient funds: balance " + to_string(balance) +
              ", requested " + to_string(requested)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class BankAccount {
    int balance;
public:
    BankAccount(int b) : balance(b) {}
    void withdraw(int amt) {
        if (amt > balance) throw InsufficientFunds(balance, amt);   // instead of return false
        balance -= amt;
    }
    int getBalance() const { return balance; }
};

int main() {
    BankAccount acc(1000);
    try {
        acc.withdraw(300);
        cout << "Withdrew 300, balance: " << acc.getBalance() << "\n";
        acc.withdraw(900);                       // too much -> throws
        cout << "This line is never reached\n";
    } catch (const InsufficientFunds& e) {
        cout << "Error: " << e.what() << "\n";
    }
    cout << "Final balance: " << acc.getBalance() << "\n";
}