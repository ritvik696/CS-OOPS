#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() const override { return 3.14159 * r * r; }
    string name() const override { return "Circle"; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() const override { return w * h; }
    string name() const override { return "Rectangle"; }
};

class Triangle : public Shape {            // new in v2
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    string name() const override { return "Triangle"; }
};

// factory: builds a shape from its name, returns nullptr if the name is unknown
unique_ptr<Shape> createShape(const string& type) {
    if (type == "circle") {
        double r; cout << "  radius: "; cin >> r;
        return make_unique<Circle>(r);
    }
    if (type == "rectangle") {
        double w, h; cout << "  width height: "; cin >> w >> h;
        return make_unique<Rectangle>(w, h);
    }
    if (type == "triangle") {
        double b, h; cout << "  base height: "; cin >> b >> h;
        return make_unique<Triangle>(b, h);
    }
    return nullptr;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    string type;

    while (true) {
        cout << "Shape (circle/rectangle/triangle/quit): ";
        cin >> type;
        if (type == "quit") break;
        auto s = createShape(type);
        if (s) shapes.push_back(std::move(s));   // unique_ptr can't be copied, only moved
        else   cout << "  Unknown shape\n";
    }

    cout << "\nCreated " << shapes.size() << " shapes:\n";
    for (const auto& s : shapes)
        cout << s->name() << " area = " << s->area() << "\n";
}