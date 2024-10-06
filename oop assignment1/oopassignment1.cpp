#include "class.h"

int main() {
	int accnumber;
	float amount;
	string username;
	double intibalance;
	cout << "Enter account number: " << endl;
	cin >> accnumber;

	cin.ignore();

	cout << "Enter account holder name: " << endl;
	getline(cin, username);
	cout << "Enter balance: " << endl;
	cin >> intibalance;
	BankAccount account(accnumber, username, intibalance);
	int op;
	do {
		system("cls");

		cout << "1.WANT TO DEPOSITE AMOUNT: " << endl;
		cout << "2.WANT TO WITHDRAW AMOUNT: " << endl;
		cout << "3.WANT TO CHECK BALANCE : " << endl;
		cout << "4.WANT TO READ FROM FILE : " << endl;
		cout << "5.EXIT : " << endl;
		cin >> op;
		switch (op) {
		case 1: {
			cout << "Enter your amount: " << endl;
			cin >> amount;
			account.depositing(amount);
			break;
		}
		case 2: {
			cout << "Enter your amount: " << endl;
			cin >> amount;
			account.withdraw(amount);
			break;
		}

		case 3: {
			account.checkingbalance();
			break;
		}
		case 4: {
			cout << "Information Saved : " << endl;
			account.save_to_file();
			account.readfromfile();
			break;
		}
		case 5:
			break;
		default:
			cout << "Invalid input" << endl;
		}
		system("pause");

	} while (op != 5);
	return 0;
}