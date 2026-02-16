#include<iostream>
using namespace std;
int main() {
    int a[3][3], diagonal[3][3];
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << "Enter value for 1st array's " << r << " row, " << c << " column: ";
            cin >> a[r][c];
        }
        
    }

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (r == c)
            {
                diagonal[r][c] = a[r][c];
            }else{
                diagonal[r][c] = 0;
            }
        }
        
    }
    

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << diagonal[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}