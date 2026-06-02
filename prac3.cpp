#include <iostream>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person()
    {
        name = "";
    }
    Person(string inpName) : name(inpName) {}

    virtual void getRole() = 0;

    virtual void displayInfo() = 0;

    virtual ~Person() {}
};

class Student : public Person
{
    int rollNo, marks;

public:
    Student()
    {
        rollNo = 0, marks = 0;
    }
    Student(string inpName, int inpRoll, int inpMarks) : Person(inpName)
    {
        rollNo = inpRoll;
        marks = inpMarks;
    }

    void getRole()
    {
        cout << "I am a Student" << endl;
    }

    void displayInfo()
    {
        cout << name << " has " << rollNo << " roll no. And got " << marks << " marks." << endl;
    }

    ~Student()
    {
        cout << "Student Object Destroyed." << endl;
    }
};

class Teacher : public Person
{
    string subject;
    int salary;

public:
    Teacher()
    {
        subject = "", salary = 0;
    }
    Teacher(string inpName, string inpSubject, int inpSalary) : Person(inpName)
    {
        subject = inpSubject;
        salary = inpSalary;
    }

    void getRole()
    {
        cout << "I am a Teacher" << endl;
    }

    void displayInfo()
    {
        cout << name << " teaches " << subject << ". And have Rs. " << salary << " salary." << endl;
    }

    ~Teacher()
    {
        cout << "Teacher Object Destroyed." << endl;
    }
};

int main()
{
    Person *arr[4];

    for (int i = 0; i < 2; i++)
    {
        arr[i] = new Student();
        arr[i + 2] = new Teacher();
    }

    for (int i = 0; i < 4; i++)
    {
        arr[i]->getRole();
        arr[i]->displayInfo();
    }

    for (int i = 0; i < 4; i++)
    {
        delete arr[i];
    }

    return 0;
}