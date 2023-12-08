#include <iostream>
#include <vector>

class Shape {
public:
    Shape() {};

    virtual double getPerimeter() {
        return .0;
    };
};

class Rectangle : public Shape {
public:
    int a, b;

    Rectangle(int a, int b) {
        this->a = a;
        this->b = b;
    }

    double getPerimeter() override {
        return this->a * 2 + this->b * 2;
    };
};

class Circle : public Shape {
public:
    int r;

    Circle(int r) {
        this->r = r;
    }

    double getPerimeter() override {
        return 2 * 3.141592653589793 * this->r;
    };
};

class Triangle : public Shape {
public:
    int a, b, c;

    Triangle(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double getPerimeter() override {
        if (a + b > c && b + c > a && c + a > b)
            return this->a + this->b + this->c;
        else
            return 0;
    };
};

int main() {
    int momentum;
    std::cin >> momentum;
    srand(momentum);
    std::vector <Shape*> shapes(rand() % 100 + 1);
    for (int i = 0; i < shapes.size(); i++) {
        int a = rand() % 10 + 1, b = rand() % 10 + 1, c = rand() % 10 + 1;
        if (rand() % 3 == 0) shapes[i] = new Rectangle(a, b);
        else if (rand() % 3 == 1) shapes[i] = new Circle(c);
        else shapes[i] = new Triangle(a, b, c);
    }

    double sum = 0;
    for (auto shape : shapes) { sum += shape->getPerimeter(); }
    std::cout << (int)sum;
}