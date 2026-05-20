#include <iostream>
using namespace std;

class Date
{
    int month, day, year;

public:
    Date()
    {
        month = 1, day = 1, year = 2000;
    }
    Date(int monthInput, int dayInput, int yearInput)
    {
        month = monthInput, day = dayInput, year = yearInput;
    }
    void check()
    {
        month = (month < 1 || month > 12) ? 1 : month;
    }
    void set()
    {
        cout << "Enter day number: ";
        cin >> day;
        cout << "Enter month number: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }
    void get()
    {
        check();
        cout << "Day: " << day << " | Month: " << month << " | Year: " << year << endl;
    }
    void displayDate()
    {
        check();
        cout << month << "/" << day << "/" << year << endl;
    }
};

main()
{
    Date obj(13, 12, 2023), obj1;
    obj1.set();
    obj.get();
    obj1.get();
    obj.displayDate();
    obj1.displayDate();
}