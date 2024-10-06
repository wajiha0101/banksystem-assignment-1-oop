#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class BankAccount {
	int accountnumber;
	string accountholdername;
	double balance;
public:
	BankAccount(int accountnumber, string accountholdername, double balance) :accountnumber(accountnumber), accountholdername(accountholdername), balance(balance) {};
	void depositing(float amount) {
		if (amount > 0) {
			balance += amount;
			cout << "The amount you deposite is: " << amount << endl;
		}
		else
			cout << "Invalid amount" << endl;
	}

	void withdraw(float amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			cout << "The amout which you withdraw is: " << amount << endl;
		}
		else
			cout << "Insuficiant amount" << endl;
	}

	void checkingbalance() {
		cout << "Total balance of your account is: " << balance << endl;
	}

	void save_to_file() {

		fstream bankfile;

		bankfile.open("bank.txt", ios::app);
		if (bankfile.is_open()) {
			bankfile << "------------------------------------------------------" << endl;
			bankfile << "Account Number is " << accountnumber << endl;
			bankfile<< "Account Holder Name " << accountholdername << endl;
			bankfile<< "Balance " << balance << endl;
			bankfile.close();
			bankfile << "------------------------------------------------------" << endl;
			cout << "Account information saved successfully!" << endl;
		}
		else {
			cout << "Unable to open file!" << endl;
		}
	}

	void readfromfile() {
		fstream bankfile;
		bankfile.open("bank.txt", ios::in);
		if (bankfile.is_open()) {
			string line;
			while (getline(bankfile, line)) {
				cout << line << endl;
			}
			bankfile.close();
		}
	}

};
