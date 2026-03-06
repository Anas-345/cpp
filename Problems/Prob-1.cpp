#include<iostream>
using namespace std;

int main(){
    int units;
    cout << "Enter units: ";
    cin >> units;

    if (units < 0)
    {
        cout << "Invalid units";
    }
    else if (units <= 100)
    {
        cout << "You consumed " << units << " units. ";
        cout << "Your total bill is " << units * 10;
    }
    else if (units <= 300)
    {
        cout << "You consumed " << units << " units. ";
        cout << "Your total bill is " << (100 * 10) + ((units - 100) * 15);
    }
    else
    {
        cout << "You consumed " << units << " units. ";
        cout << "Your total bill is " << (100 * 10) + (200 * 15) + ((units - 300) * 20) ;
    }
}