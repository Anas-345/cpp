#include <iostream>
using namespace std;

class Student
{
    string name;

public:
    void setData()
    {
        cout << "Enter student name: ";
        getline(cin, name);
    }
    void display()
    {
        cout << name << endl;
    }
};

int main()
{
    Student st1;
    st1.setData();
    st1.display();

    return 0;
}