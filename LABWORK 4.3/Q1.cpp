

#include <iostream>
#include <string>
using namespace std;

class Employee
{

protected:
    int emp_id;
    string emp_name;
    int age;
    double salary;

public:
    virtual ~Employee() {}

    void setEmployee(int id, string n, int a, double s)
    {

        emp_id = id;
        emp_name = n;
        age = a;
        salary = s;
    }

    virtual void display()
    {

        cout << "\nEmployee Details are" << endl;

        cout << "id" << emp_id << endl;
        cout << "name" << emp_name << endl;
        cout << "age" << age << endl;
        cout << "salary" << salary << endl;
    }
};

class FullTimeEmployee : public Employee
{

protected:
    double bonus;

public:
    void setFullTimeEmployee(int id, string n, int a, double s, double b)
    {
        setEmployee(id, n, a, s);
        bonus = b;
    }

    void display() override
    {

        cout << "\nFullTime Employee" << endl;
        Employee::display();
        cout << "\n bonus" << bonus << endl;
    }
};

class PartTime : public Employee
{

protected:
    float hours;

public:
    void setPartTimeEmployee(int id, string n, int a, double s, float h)
    {

        setEmployee(id, n, a, s);

        hours = h;
    }

    void display() override
    {

        cout << "\n Part time employees";
        Employee::display();
        cout << "\n hours " << hours << endl;
    }
};

int main()
{

    const int MAX = 10;

    

   

    return 0;
}