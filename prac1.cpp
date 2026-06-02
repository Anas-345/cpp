#include <iostream>

using namespace std;

class Shape
{
public:
    virtual float area() = 0;
};

class Circle : public Shape
{
    int r;
    const float PIE = 3.14;

public:
    float area()
    {
        cout << "Enter radius of circle: ";
        cin >> r;
        return ((PIE) * (r * r));
    }
};

class Rectangle : public Shape
{
    int l, w;

public:
    float area()
    {
        cout << "Enter length of rectangle: ";
        cin >> l;
        cout << "Enter width of rectangle: ";
        cin >> w;
        return (l * w);
    }
};

int main()
{
    Shape *ptr = new Circle();
    Rectangle r;

    cout << ptr->area() << endl;
    cout << r.area() << endl;

    return 0;
}