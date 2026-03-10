#include <iostream>
using namespace std;

class Student
{
    char name[50];
    int marks;

public:
    void setData();
    void showData();
    void isTopper(Student s);
};

void Student::setData(){
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your marks: ";
    cin >> marks;
}
void Student::showData(){
    cout << name << " got " << marks << " marks " << endl;
}
void Student::isTopper(Student s){
    if (marks > s.marks)
    {
        cout << name << " got " << marks - s.marks << " more marks than " << s.name << endl;
    }else if (marks < s.marks)
    {
        cout << s.name << " got " << s.marks - marks << " more marks than " << name << endl;
    }else
    {
        cout << name << ", " << s.name << " got equal marks." << endl;
    }
    
}

int main()
{
    Student a, b;
    a.setData();
    a.showData();
    b.setData();
    b.showData();
    a.isTopper(b);

    return 0;
}