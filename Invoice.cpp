#include <iostream>
#include <cstring>
using namespace std;

class Invoice
{
    char partNum[20], partDesc[50];
    int quantity, price;

public:
    Invoice()
    {
        strcpy(partNum, "Empty");
        strcpy(partDesc, "Empty");
        quantity = 0, price = 0;
    }
    Invoice(const char partNumber[20], const char partDescription[50], int quantityInput, int priceInput)
    {
        strcpy(partNum, partNumber);
        strcpy(partDesc, partDescription);
        quantity = quantityInput, price = priceInput;
    }
    void check()
    {
        quantity = quantity < 0 ? 0 : quantity, price = price < 0 ? 0 : price;
    }
    void set()
    {
        cout << "Enter part number: ";
        cin.get(partNum, 20);
        cin.ignore();
        cout << "Enter part description: ";
        cin.get(partDesc, 50);
        cin.ignore();
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price of that part: ";
        cin >> price;
    }
    void get()
    {
        check();
        cout << "Part [" << partNum << "] | Part Description [" << partDesc << "] | Quantity: " << quantity << " | Price: " << price << endl;
    }
    int getInvoiceAmount()
    {
        check();
        return price * quantity;
    }
};

main()
{
    Invoice obj("Hello", "Done", 1, 100), obj1;
    obj1.set();
    obj.get();
    obj1.get();
    cout << "Total Amount of obj is " << obj.getInvoiceAmount() << " | Total Amount of obj1 is " << obj1.getInvoiceAmount() << endl;
}