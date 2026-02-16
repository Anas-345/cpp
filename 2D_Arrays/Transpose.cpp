#include<iostream>
using namespace std;
int main() {
    int a[3][3], transpose[3][3];
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << "Enter value for " << r << " row, " << c << " column: ";
            cin >> a[r][c];
        }
        
    }

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            transpose[r][c] = a[c][r];
        }
        
    }
    

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << transpose[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}