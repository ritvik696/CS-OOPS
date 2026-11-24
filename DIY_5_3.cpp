#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    int id;
    string item;
    static int nextId;           // shared by all Order objects

public:
    Order(const string &itemName) : id(nextId++), item(itemName) {}

    int getId() const { return id; }

    void display() const {
        cout << "Order #" << id << " : " << item << endl;
    }
};

int Order::nextId = 1001;        // first order gets 1001

int main() {
    Order o1("Laptop");
    Order o2("Keyboard");
    Order o3("Monitor");

    o1.display();
    o2.display();
    o3.display();

    Order *o4 = new Order("Mouse");
    o4->display();
    delete o4;

    Order o5("Webcam");          // ID keeps increasing even after delete
    o5.display();

    return 0;
}