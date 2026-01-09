#include <iostream>

#include <cstring>

using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    // Default Constructor
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int number, const char *name, const char *src, const char *dest, const char *time)
    {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setters
    void setTrainNumber(int number)
    {
        trainNumber = number;
    }

    void setTrainName(const char *name)
    {
        strcpy(trainName, name);
    }

    void setSource(const char *src)
    {
        strcpy(source, src);
    }

    void setDestination(const char *dest)
    {
        strcpy(destination, dest);
    }

    void setTrainTime(const char *time)
    {
        strcpy(trainTime, time);
    }

    // Getters
    int getTrainNumber() const
    {
        return trainNumber;
    }

    const char *getTrainName() const
    {
        return trainName;
    }

    const char *getSource() const
    {
        return source;
    }

    const char *getDestination() const
    {
        return destination;
    }

    const char *getTrainTime() const
    {
        return trainTime;
    }

    // Input Method
    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Method
    void displayTrainDetails() const
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    // Static Method
    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

// Railway System Class
class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains < 100)
        {
            cout << "\n--- Add New Train Record ---\n";
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }
        else
        {
            cout << "Train storage is full!\n";
        }
    }

    void displayAllTrains() const
    {
        if (totalTrains == 0)
        {
            cout << "\nNo train records available.\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1 << " details:\n";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) const
    {
        bool found = false;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nTrain with number " << number << " not found!\n";
        }
    }
};

int main()
{
    RailwaySystem system;
    int choice, number;

    do
    {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addTrain();
            break;

        case 2:
            system.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number to search: ";
            cin >> number;
            system.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting the system. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
