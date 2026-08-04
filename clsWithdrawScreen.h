#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

class clsWithdrawScreen : clsScreen
{
private:
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number : ";
		cin >> AccountNumber;
		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Accoutn Number [" << AccountNumber << "] Does not Exists.\n\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);


		cout << "\nPlease Enter Withdraw Amount : ";

		double Amount = 0;

		Amount = clsInputValidation::ReadDblNumberBetween(0.01, numeric_limits<double>::max(),
			"Amount must be greater than zero. Enter again: ");

		cout << "\nAre you sure you want to withdraw [" << Amount << "] from " << Client1.FullName() << "'s balance? [Y/N] : ";
		char Answer = 'Y';
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				_SetSuccessScreenColor();
				cout << "\nAmount withdrawn successfully!\n";
				cout << "\n" << Client1.FullName() << "'s new balance is : " << Client1.AccountBalance << endl;
			}
			
			else
			{
				_SetErrorScreenColor();
				cout << "\nCannot Withdraw, Insuffecient Balance!";
				cout << "\n___________________\n";
				cout << "\nAmount to Withdraw is : " << Amount << endl;
				cout << "\nYour Balance is       : " << Client1.AccountBalance << endl;
				cout << "\n___________________\n";
			}

		}
		else
		{
			cout << "Operation Cancelled!" << endl;
		}
	}
};

