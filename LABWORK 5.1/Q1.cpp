#include <iostream>

using namespace std;

class Calculator
{
public:
    void calculate(int a, int b)
    {

        cout << "\n Division Result " << a / b << endl;
    }

    void calculate(int a, int b, int c)
    {

        cout << "\n substraction Result " << a - b - c << endl;
    }

    void calculate(int a, int b, int c, int d)
    {

        cout << "\n Multiplication Result " << a * b * c * d << endl;
    }

    void calculate(int a, int b, int c, int d, int e)
    {

        cout << "\n addition Result " << a + b + c + d + e << endl;
    }
};

int main()
{

    Calculator obj;
    obj.calculate(10, 20, 30, 40, 50);

    obj.calculate(10, 5);

    obj.calculate(100, 50, 20);

    obj.calculate(10, 20, 30, 40);

    return 0;
}