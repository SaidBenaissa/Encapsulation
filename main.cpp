/*
 * In this example, the BankAccount class has three private member variables: accountNumber, balance, and interestRate.
 * These variables are not directly accessible from outside the class; instead, the class provides a public interface
 * that allows other code to interact with the object.
 * The public interface consists of several methods that can be used to deposit or withdraw
 * money from the account, retrieve the current balance, set the interest rate, and calculate
 * the amount of interest earned. These methods are the only way to interact with the BankAccount object from outside the class, and they enforce encapsulation @
 by hiding the internal implementation details of the class.
 * */


#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(string accNum, double bal, double intRate) {
        accountNumber = accNum;
        balance = bal;
        interestRate = intRate;
    }

    // Public interface methods
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double calculateInterest() const {
        return balance * interestRate;
    }
};

int main() {
    // Create a new BankAccount object
    BankAccount account("123456789", 1000.0, 0.05);

    // Use the public interface methods to interact with the object
    account.deposit(500.0);
    account.withdraw(200.0);
    cout << "Balance: " << account.getBalance() << endl;

    account.setInterestRate(0.06);
    cout << "Interest: " << account.calculateInterest() << endl;

    return 0;
}
