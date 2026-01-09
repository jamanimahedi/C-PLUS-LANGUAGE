#include <iostream>

using namespace std;

class Cricket
{

public:
    virtual int getTotalOvers()
    {
        return 0;
    }
};

class T20Match : public Cricket
{

public:
    int getTotalOvers() override
    {
        return 20;
    }
};

class TestMatch : public Cricket
{

public:
    int getTotalOvers() override
    {
        return 90;
    }
};

int main()
{

    Cricket *obj;

    T20Match t20;
    TestMatch test;

    obj = &t20;
    cout << "T20 Match Overs : " << obj->getTotalOvers() << endl;

    obj = &test;
    cout << "Test Match Overs : " << obj->getTotalOvers() << endl;

    return 0;
}