#include <iostream>

#include <string>

using namespace std;

class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
private:
    int pages;

public:
    Book(string t, string a, string d, int p)
        : LibraryItem(t, a, d)
    {
        pages = p;
    }

    void checkOut() override
    {
        cout << "Book checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "Book returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n--- Book Details ---\n";
        cout << "Title : " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Pages: " << pages << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        duration = dur;
    }

    void checkOut() override
    {
        cout << "DVD checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n--- DVD Details ---\n";
        cout << "Title : " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Duration: " << duration << " minutes\n";
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        issueNumber = issue;
    }

    void checkOut() override
    {
        cout << "Magazine checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "Magazine returned successfully.\n";
    }

    void displayDetails() override
    {
        cout << "\n--- Magazine Details ---\n";
        cout << "Title : " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Issue Number: " << issueNumber << endl;
    }
};

int main()
{
    LibraryItem *items[10];
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                string t, a, d;
                int p;
                cout << "Enter Title: ";
                cin >> t;
                cout << "Enter Author: ";
                cin >> a;
                cout << "Enter Due Date: ";
                cin >> d;
                cout << "Enter Pages: ";
                cin >> p;

                if (p <= 0)
                    throw "Invalid page number!";

                items[count++] = new Book(t, a, d, p);
            }
            else if (choice == 2)
            {
                string t, a, d;
                int dur;
                cout << "Enter Title: ";
                cin >> t;
                cout << "Enter Author: ";
                cin >> a;
                cout << "Enter Due Date: ";
                cin >> d;
                cout << "Enter Duration: ";
                cin >> dur;

                items[count++] = new DVD(t, a, d, dur);
            }
            else if (choice == 3)
            {
                string t, a, d;
                int issue;
                cout << "Enter Title: ";
                cin >> t;
                cout << "Enter Author: ";
                cin >> a;
                cout << "Enter Due Date: ";
                cin >> d;
                cout << "Enter Issue Number: ";
                cin >> issue;

                items[count++] = new Magazine(t, a, d, issue);
            }
            else if (choice == 4)
            {
                for (int i = 0; i < count; i++)
                {
                    items[i]->displayDetails();
                }
            }
            else if (choice == 5)
            {
                cout << "Exiting program...\n";
            }
            else
            {
                cout << "Invalid choice!\n";
            }
        }
        catch (const char *msg)
        {
            cout << "Error: " << msg << endl;
        }

    } while (choice != 5);

    for (int i = 0; i < count; i++)
    {
        delete items[i];
    }

    return 0;
}
