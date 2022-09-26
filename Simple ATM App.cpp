#include<iostream>
using namespace std;
// globale variables
double balance = 500;
double withdrawAmount = 0;
double depositAmount = 0;
// 
void showMenu()
{
	cout << "\t\t****************** Options ******************" << endl;
	cout << "\t\t\t1- Check Balance ." << endl;
	cout << "\t\t\t2- Deposit amount." << endl;
	cout << "\t\t\t3- Withdraw amount." << endl;
	cout << "\t\t\t4- Exit." << endl;
}

void Check_Balance() {
	cout << " Balance is :" << balance << " $" << endl;
}
void deposit()
{
	cout << "Deposit amount : ";
	cin >> depositAmount;
	balance += depositAmount;
}
void withdraw_Amount()
{
	cout << "withdraw amount : ";
	cin >> withdrawAmount;
	balance -= withdrawAmount;
}

void ATMsystem()
{
	int option;
	do {
		showMenu();
		cin >> option;
		switch (option)
		{
		case 1:
			Check_Balance();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdraw_Amount();
			break;
		}
	} while ( option !=4);

}
int main()
{
	ATMsystem();
	return 0;
}