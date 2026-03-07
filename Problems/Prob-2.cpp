#include<iostream>
using namespace std;

class Rectangle
{
    int l,w;
public:
    Rectangle();
    Rectangle(int a, int b);
    void get();
    void area();
    void paremeter();
};

Rectangle::Rectangle()
{
    l = 0, w = 0;
}
Rectangle::Rectangle(int a, int b){
    l = a, w = b;
}
void Rectangle::get(){
    cout << "Enter length & width of rectangle: ";
    cin >> l >> w;
}
void Rectangle::area(){
    cout << l * w << endl;
}
void Rectangle::paremeter(){
    cout << 2*(l + w) << endl;
}

int main(){
    Rectangle r1, r2(10, 5), r3;
    r1.get();
    r1.area();
    r1.paremeter();
    r2.area();
    r2.paremeter();
    r3.area();
    r3.paremeter();
}