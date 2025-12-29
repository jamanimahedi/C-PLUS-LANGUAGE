#include <iostream>

using namespace std;

class Hotel
{
private:
    int hotel_id;
    string hotel_name;
    string hotel_type;
    int hotel_rating;
    string hotel_location;
    int hotel_establish_year;
    int hotel_staff_quantity;
    int hotel_room_quantity;
    int static totalCount;

public:
    void setData(int id, string name, string type, int rating, string location, int year, int staff, int room)
    {

        hotel_id = id;
        hotel_name = name;
        hotel_type = type;
        hotel_rating = rating;
        hotel_location = location;
        hotel_establish_year = year;
        hotel_staff_quantity = staff;
        hotel_room_quantity = room;

        totalCount++;
    }

    void getData(int i)
    {

        cout << "\n\nrecord of student: " << i + 1 << endl;

        cout << hotel_id << endl;
        cout << hotel_name << endl;
        cout << hotel_type << endl;
        cout << hotel_rating << endl;
        cout << hotel_location << endl;
        cout << hotel_establish_year << endl;
        cout << hotel_staff_quantity << endl;
        cout << hotel_room_quantity << endl;
    }

    static void count()
    {
        cout << "\nTotal Hotel Are :" << totalCount << endl;
    }
};

int Hotel::totalCount = 0;

int main()
{
    int n;

    cout << "Enter Total Hotel Index: ";
    cin >> n;
    Hotel h[n];

    for (int i = 0; i < n; i++)
    {
        int id, rating, year, staff, room;
        string name, type, location;

        cout << "\nEnter Detail Of Hotel: " << i + 1 << endl;

        cout << "ID       :";
        cin >> id;

        cout << "NAME     :";
        cin >> name;

        cout << "TYPE     :";
        cin >> type;

        cout << "RATING   :";
        cin >> rating;

        cout << "LOCATION :";
        cin >> location;

        cout << "YEAR     :";
        cin >> year;

        cout << "STAFF    :";
        cin >> staff;

        cout << "ROOM     :";
        cin >> room;

        h[i].setData(id, name, type, rating, location, year, staff, room);
    }

    for (int i = 0; i < n; i++)
    {
        h[i].getData(i);
    }

    Hotel::count();

    return 0;
}