#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct order
{
    int id;
    string sender;
    string receiver;
    string address;
    float distance;
    float charges;
    string status;
};
const int ratePerKm = 20;

void displayHead()
{
    cout << left
         << setw(5) << "ID"
         << setw(15) << "Sender"
         << setw(15) << "Receiver"
         << setw(20) << "Address"
         << setw(12) << "Status"
         << setw(10) << "Distance"
         << setw(10) << "Charges"
         << endl;

    cout << string(87, '-') << endl;
}

void displayBoady(const order &o)
{
    cout << left
         << setw(5) << o.id
         << setw(15) << o.sender
         << setw(15) << o.receiver
         << setw(20) << o.address
         << setw(12) << o.status
         << setw(10) << fixed << setprecision(1) << o.distance
         << setw(10) << fixed << setprecision(2) << o.charges
         << endl;
}

order addNewOrder(int id)
{
    order newOrder;

    cout << "Enter sender name: ";
    getline(cin, newOrder.sender);
    cout << "Enter receiver name: ";
    getline(cin, newOrder.receiver);
    cout << "Enter address: ";
    getline(cin, newOrder.address);
    cout << "Enter distance(km): ";
    cin >> newOrder.distance;

    newOrder.id = id;
    newOrder.status = "Pending";
    newOrder.charges = ratePerKm * newOrder.distance;
    return newOrder;
}

void viewOrders(const vector<order> &orders)
{
    displayHead();

    for (int i = 0; i < orders.size(); i++)
    {
        displayBoady(orders[i]);
    }
}

void searchById(vector<order> &orders)
{
    int searchId;
    cout << "Enter id: ";
    cin >> searchId;
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].id == searchId)
        {
            displayHead();
            displayBoady(orders[i]);
            if (orders[i].status == "Pending")
            {
                char ch;
                cout << "Do you want to update status(y/n): ";
                cin >> ch;
                if (ch == 'y')
                {
                    orders[i].status = "Delivered";
                }
            }
            return;
        }
    }
    cout << "Invalid ID.No records found." << endl;
}

void displayMenu()
{
    cout << "\n"
         << string(30, '=') << endl;
    cout << "     COURIER ORDER SYSTEM" << endl;
    cout << string(30, '=') << endl;
    cout << " 1. Add Order" << endl;
    cout << " 2. View Orders" << endl;
    cout << " 3. Search" << endl;
    cout << " 4. Exit" << endl;
    cout << string(30, '=') << endl;
    cout << "Enter choice: ";
}

int main()
{
    vector<order> orders = {};

    bool leave = false;
    int choice;
    while (!leave)
    {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            orders.push_back(addNewOrder(orders.size() + 1));
            break;
        case 2:
            viewOrders(orders);
            break;
        case 3:
            searchById(orders);
            break;
        case 4:
            leave = true;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}