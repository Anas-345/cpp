#include <iostream>
using namespace std;

int main() {
    cout << "ASCII Table" << endl;
    cout << "Code  Character" << endl;

    for (int i = 0; i < 128; i++) {
        cout << i << "\t";

        if (i < 32 || i == 127) {
            cout << "Non-printable";
        } else {
            cout << char(i);
        }

        cout << endl;
    }

    return 0;
}