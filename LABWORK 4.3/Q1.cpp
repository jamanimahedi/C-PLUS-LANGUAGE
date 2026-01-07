#include <iostream>

#include <string>

using namespace std;


class Employee
{

protected:
    int Employee_id;
    string emp_name;
    int age;
    double salary;

public:
    void setData(int id, string n, int a, double s)
    {

        Employee_id = id;
        emp_name = n;
        age = a;
        salary = s;
    }

    void display()
    {
        cout << "Employee Detail :" << endl;

        cout << "ID :" << Employee_id << endl;
        cout << "NAME :" << emp_name << endl;
        cout << "AGE :" << age << endl;
        cout << "SALARY :" << salary << endl;
    }
};

class FullTimeEmp : public Employee
{
protected:
    double Bonus;

public:
    virtual void FullTimeData(int id, string n, int a, double s, double b)
    {

        Employee::setData(id, n, a, s);

        Bonus = b;
    }

    virtual void display()
    {

        cout << "Full Time Employee " << endl;
        Employee::display();
        cout << "Bonus :" << Bonus << endl;
    }
};

class PartTimeEmp : public Employee
{
protected:
    float hour;

public:
    virtual void PartTimeData(int id, string n, int a, double s, float h)
    {

        Employee::setData(id, n, a, s);
        hour = h;
    }

    virtual void display()
    {

        cout << "part Time Employee " << endl;
        Employee::display();
        cout << "hour :" << hour << endl;
    }
};

int main()
{

    PartTimeEmp p;
    p.PartTimeData(101, "Rahul", 22, 15000, 6.5);
    p.display();

    return 0;
}