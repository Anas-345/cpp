#include<iostream>
using namespace std;
int main() {
    int a[3][3], b[3][3], subtract[3][3];
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << "Enter value for 1st array's " << r << " row, " << c << " column: ";
            cin >> a[r][c];
            cout << "Enter value for 2nd array's " << r << " row, " << c << " column: ";
            cin >> b[r][c];
        }
        
    }
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            subtract[r][c] = a[r][c] - b[r][c];
        }
        
    }
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << subtract[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}