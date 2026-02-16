#include <iostream>
using namespace std;
int main(){
    string name = "Anas Munir";
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] >= 97 && name[i] <= 122)
        {
            name[i] = name[i] - 32;
        }
        
    }
    cout << name << endl;
    

    return 0;
}