#include <iostream>
using namespace std;

class Student
{
    string name;
    int roll, age;
    char grade;

public:
    Student()
    {
        cout << "Student Class" << endl;
        roll = 0, age = 0, grade = 'F';
    }
    void setData()
    {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter your roll no.";
        cin >> roll;
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your grade: ";
        cin >> grade;
    }
    void display()
    {
        cout << "Name: " << name << endl << "Roll No. " << roll << endl << "Age: " << age << endl << "Grade: " << grade << endl;
    }
};

int main()
{
    Student st1;
    st1.setData();
    st1.display();

    return 0;
}