#include <iostream>

using namespace std;

class Student
{
    string name;
    int age, rollNo;

public:
    Student()
    {
        name = "", age = 0, rollNo = 0;
    }

    Student(string inpName, int inpAge, int inpRoll) : name(inpName), age(inpAge), rollNo(inpRoll) {}

    void setData()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your rollNo: ";
        cin >> rollNo;
    }

    string getName() const { return name; }

    int getAge() const { return age; }

    int getRoll() const { return rollNo; }

    virtual void display() const
    {
        cout << "I am a Student" << endl;
    }

    void displayInfo() const
    {
        cout << getName() << "'s age is " << getAge() << " having roll no. " << getRoll() << endl;
    }

    virtual ~Student()
    {
        cout << "Object Destroyed" << endl;
    }
};

class GradStudent : public Student
{
    string researchTopic;

public:
    GradStudent() : Student()
    {
        researchTopic = "";
    }

    GradStudent(string inpName, int inpAge, int inpRoll, string inpResearch) : Student(inpName, inpAge, inpRoll)
    {
        researchTopic = inpResearch;
    }

    void display() const
    {
        cout << "I am a grad Student" << endl;
    }

    void displayAll() const
    {
        displayInfo();
        cout << "And research topic is " << researchTopic << endl;
    }

    ~GradStudent()
    {
        cout << "Destoying Child" << endl;
    }
};

int main()
{
    Student *ptr = new GradStudent("Anas", 20, 20, "research");
    Student st, st1("Anas", 20, 20);
    // st.setData();

    // st.displayInfo();
    // st1.displayInfo();
    // g.displayAll();
    ptr->display();

    delete ptr;
    return 0;
}