#include <iostream>
using namespace std;

class test
{
    int num;
public:
test();
void get();
test change(test s);
void show();
};

test::test(){
    cout << "Returning an Object" << endl;
    num = 0;
}
void test::get(){
    cout << "Enter a number: ";
    cin >> num;
}
test test::change(test s){
    s.num = num + s.num;
    return s;
}
void test::show(){
    cout << num << endl;
}

int main(){
    test t, n, result;
    t.get();
    t.show();
    n.get();
    n.show();
    result = t.change(n);
    result.show();
}