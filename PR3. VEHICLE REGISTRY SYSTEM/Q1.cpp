#include <iostream>

#include <string>

using namespace std;


class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "N/A";
        model = "N/A";
        year = 0;
    }

    Vehicle(int id, string manu, string mod, int yr)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    virtual ~Vehicle() {}

    int getID() const { return vehicleID; }

    virtual void display() const
    {
        cout << "ID: " << vehicleID
             << " | Manufacturer: " << manufacturer
             << " | Model: " << model
             << " | Year: " << year;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    void display() const override
    {
        Vehicle::display();
        cout << " | Fuel: " << fuelType;
    }
};

class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void display() const override
    {
        Car::display();
        cout << " | Battery: " << batteryCapacity << " kWh";
    }
};

class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    SportsCar(int id, string manu, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    void display() const override
    {
        ElectricCar::display();
        cout << " | Top Speed: " << topSpeed << " km/h";
    }
};

class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft(int range) { flightRange = range; }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string manu, string mod, int yr, string fuel, int range)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void display() const
    {
        Car::display();
        cout << " | Flight Range: " << flightRange << " km";
    }
};

class Sedan : public Car
{
public:
    Sedan(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}
};

class SUV : public Car
{
public:
    SUV(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}
};

class VehicleRegistry
{
    Vehicle *vehicles[20];
    int count;

public:
    VehicleRegistry() { count = 0; }

    void addVehicle(Vehicle *v)
    {
        vehicles[count++] = v;
    }

    void displayAll()
    {
        if (count == 0)
        {
            cout << "\nNo vehicles available.\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            vehicles[i]->display();
            cout << endl;
        }
    }

    void searchByID(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getID() == id)
            {
                vehicles[i]->display();
                cout << endl;
                return;
            }
        }
        cout << "Vehicle not found.\n";
    }
};

int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout << "\n===== Vehicle Registry System =====\n";
        cout << "1. Add Sedan\n";
        cout << "2. Add SUV\n";
        cout << "3. Add Electric Car\n";
        cout << "4. Add Sports Car\n";
        cout << "5. Add Flying Car\n";
        cout << "6. View All Vehicles\n";
        cout << "7. Search Vehicle by ID\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, year, battery, speed, range;
        string manu, model, fuel;

        switch (choice)
        {
        case 1:
            cin >> id >> manu >> model >> year >> fuel;
            registry.addVehicle(new Sedan(id, manu, model, year, fuel));
            break;

        case 2:
            cin >> id >> manu >> model >> year >> fuel;
            registry.addVehicle(new SUV(id, manu, model, year, fuel));
            break;

        case 3:
            cin >> id >> manu >> model >> year >> fuel >> battery;
            registry.addVehicle(new ElectricCar(id, manu, model, year, fuel, battery));
            break;

        case 4:
            cin >> id >> manu >> model >> year >> fuel >> battery >> speed;
            registry.addVehicle(new SportsCar(id, manu, model, year, fuel, battery, speed));
            break;

        case 5:
            cin >> id >> manu >> model >> year >> fuel >> range;
            registry.addVehicle(new FlyingCar(id, manu, model, year, fuel, range));
            break;

        case 6:
            registry.displayAll();
            break;

        case 7:
            cout << "Enter Vehicle ID: ";
            cin >> id;
            registry.searchByID(id);
            break;
        }
    } while (choice != 0);

    cout << "\nTotal Vehicles Registered: " << Vehicle::totalVehicles << endl;
    return 0;
}
