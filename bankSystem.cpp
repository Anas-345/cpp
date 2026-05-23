#include <iostream>
#include <cstring>
using namespace std;

class Account
{
protected:
    char name[20], accountNumber[10];
    float balance;

public:
    Account()
    {
        strcpy(name, "Empty Name");
        strcpy(accountNumber, "Empty");
        balance = 0;
    }
    Account(char defaultName[20], char defaultAccountNumber[10], float defaultBalance)
    {
        strcpy(name, defaultName);
        strcpy(accountNumber, defaultAccountNumber);
        defaultBalance < 0 ? balance = 0 : balance = defaultBalance;
    }
    void deposit(float amount)
    {
        if (amount < 0)
        {
            cout << "Please enter valid ammount!" << endl;
            return;
        }

        balance += amount;
    }
    void withDraw(float amount)
    {
        if (amount < 0)
        {
            cout << "Please enter valid ammount!" << endl;
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
            return;
        }

        balance -= amount;
    }
    virtual void displayDetails() const
    {
        cout << name << "'s account number " << accountNumber << " has a total balance of Rs. " << balance;
    }
    const char *getAccountNumber() const
    {
        return accountNumber;
    }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(char defaultName[], char defaultAccountNumber[], float defaultBalance) : Account(defaultName, defaultAccountNumber, defaultBalance) {}
    void addInterest(float interestRate)
    {
        balance += (balance * interestRate);
    }
    void displayDetails() const
    {
        Account::displayDetails();
        cout << "[Type: Savings Account]";
    }
};

class Bank
{
    Account accounts[10];
    int count = 0;

public:
    void addAccount(Account &acc)
    {
        accounts[count++] = acc;
    }
    void depositFromBank(const char *accNumber, float amount)
    {
        for (int i = 0; i < count; i++)
        {
            if (!(strcmp(accounts[i].getAccountNumber(), accNumber)))
            {
                accounts[i].deposit(amount);
                return;
            }
        }
        cout << "Account not found!" << endl;
    }
    void showAllAccounts() const
    {
        for (int i = 0; i < count; i++)
        {
            accounts[i].displayDetails();
        }
    }
};

int main()
{
    Bank bank1;
    Account obj1;
    SavingsAccount obj("Anas", "101D", 100);
    bank1.addAccount(obj1);
    bank1.depositFromBank("101", 10000);
    bank1.showAllAccounts();

    return 0;
}