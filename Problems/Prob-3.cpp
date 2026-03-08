#include<iostream>
using namespace std;

class BankAccount
{
    int accountNumber, balance, depositAmount, withdrawAmount;
    char accountName[50];
public:
    BankAccount();
    void getData();
    void deposit();
    void withdraw();
    void display();
};

BankAccount::BankAccount()
{
    cout << "Welcome to Bank" << endl;
    balance = 0, depositAmount = 0, withdrawAmount = 0;
}
void BankAccount::getData(){
    cout << "Enter your account name: ";
    cin.getline(accountName, 50);
    cout << "Enter your account number: ";
    cin >> accountNumber;
    cout << "Enter initial balance: ";
    cin >> balance;
}
void BankAccount::deposit(){
    cout << "Enter the amount you want to deposit: ";
    cin >> depositAmount;
    balance += depositAmount;
    depositAmount = 0;
}
void BankAccount::withdraw(){
    cout << "Enter the amount you want to withdraw: ";
    cin >> withdrawAmount;
    if (withdrawAmount > balance)
    {
        cout << "Insufficient Balance" << endl;
        return;
    }
    
    balance -= withdrawAmount;
    withdrawAmount = 0;
}
void BankAccount::display(){
    cout << "Account Number: " << accountNumber << endl;
    cout << "Name: " << accountName << endl;
    cout << "Balance : " << balance << endl;
}

int main(){
    BankAccount acc1;
    acc1.getData();
    int choice;
    while (true)
    {
        cout << "1- Deposit" << endl;
        cout << "2- Withdraw" << endl;
        cout << "3- Details" << endl;
        cout << "4- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            acc1.deposit();
        }else if (choice == 2)
        {
            acc1.withdraw();
        }else if (choice == 3)
        {
            acc1.display();
        }else if (choice == 4)
        {
            return 0;
        }else{
            cout << "Invalid Input";
        }
    }
    

    return 0;
}