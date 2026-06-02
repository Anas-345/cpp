#include <iostream>
using namespace std;

class Student
{
    struct Data
    {
        string name;
        int marks;
    };
    Data studentData;

public:
    Student()
    {
        studentData.name = "Anas";
        studentData.marks = 15;
    }
    void setData()
    {
        cout << "Enter your name: ";
        cin >> studentData.name;
        cout << "Enter your marks: ";
        cin >> studentData.marks;
    }

    Data getData()
    {
        return studentData;
    };

    ~Student()
    {
        cout << "Object Destroyed." << endl;
    }
};

int main()
{
    Student *ptr[3];
    for (int i = 0; i < 3; i++)
    {
        ptr[i] = new Student();
    }

    for (int i = 0; i < 3; i++)
    {
        ptr[i]->setData();
    }

    for (int i = 0; i < 3; i++)
    {
        cout << ptr[i]->getData().name << " got " << ptr[i]->getData().marks << " marks." << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete ptr[i];
    }

    return 0;
}