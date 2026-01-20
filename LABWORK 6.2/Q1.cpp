#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void calculate() = 0;
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    void calculate()
    {
        float area = 3.14 * radius * radius;
        cout << "Area of Circle = " << area << endl;
    }
};

class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    void calculate()
    {
        float area = 0.5 * base * height;
        cout << "Area of Triangle = " << area << endl;
    }
};

class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }

    void calculate()
    {
        float area = length * width;
        cout << "Area of Rectangle = " << area << endl;
    }
};

int main()
{
    Shape *s;

    Circle c(5);
    Triangle t(4, 6);
    Rectangle r(7, 3);

    s = &c;
    s->calculate();

    s = &t;
    s->calculate();

    s = &r;
    s->calculate();

    return 0;
}