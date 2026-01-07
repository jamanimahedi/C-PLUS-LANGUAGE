#include <iostream>

using namespace std;

class RBI
{

protected:
    float rate;

public:
    void getROI()
    {

        rate = 0.0;

        cout << "RBI rate : " << rate << endl;
    }
};

class SBI : virtual public RBI
{

public:
    void getROI()
    {

        rate = 5.6;

        cout << "SBI rate : " << rate << endl;
    }
};

class BOB : virtual public RBI
{

public:
    void getROI()
    {

        rate = 5.6;

        cout << "BOB rate : " << rate << endl;
    }
};

class ICICI : virtual public RBI
{

public:
    void getROI()
    {

        rate = 6.6;

        cout << "ICICI rate : " << rate << endl;
    }
};

int main()
{
    RBI R;
    R.getROI();

    SBI S;
    S.getROI();

    BOB B;
    B.getROI();

    ICICI I;
    I.getROI();

    return 0;
}