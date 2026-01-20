#include <iostream>

using namespace std;

class Admin
{
private:
    bool can_terminate;
    double total_annual_revenue;

protected:
    double manager_salary;
    double employee_salary;

public:
    string company_name;
    int total_staff;

    Admin()
    {
        company_name = "RD PVT. LTD.";
        manager_salary = 50000;
        employee_salary = 30000;
        total_staff = 150;
        total_annual_revenue = 500000;
        can_terminate = true;
    }

    virtual void myAccess()
    {
        cout << "\n========= Admin Details ===========";
        cout << "\nCompany Name   : " << company_name;
        cout << "\nManager Salary : " << manager_salary;
        cout << "\nEmployee Salary: " << employee_salary;
        cout << "\nTotal Staff    : " << total_staff;
        cout << "\nAnnual Revenue : " << total_annual_revenue;
        cout << "\nCan terminate  : " << can_terminate;
    }
};

class Manager : public Admin
{
public:
    void myAccess() override
    {
        cout << "\n\n=========== Manager View ===========";
        cout << "\nManager Salary : " << manager_salary;
        cout << "\nEmployee Salary: " << employee_salary;
        cout << "\nTotal Staff    : " << total_staff;
    }
};

class Employee : public Manager
{
public:
    void myAccess() override
    {
        cout << "\n\n============= Employee View ===========";
        cout << "\nEmployee Salary: " << employee_salary;
        cout << "\nTotal Staff    : " << total_staff;
    }
};

int main()
{
    Admin a;
    a.myAccess();

    Manager m;
    m.myAccess();

    Employee e;
    e.myAccess();

    return 0;
}