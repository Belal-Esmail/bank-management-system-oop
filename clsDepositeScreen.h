#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"
class clsDepositeScreen : protected clsScreen
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
	static void ShowDepositeScreen()
	{
		_DrawScreenHeader("\t Deposite Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] Does Not Exists." << endl;
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter Deposite Amount : ";
		Amount = clsInputValidation::ReadDblNumberBetween(0.01, numeric_limits<double>::max(),
			"Amount must be greater than zero. Enter again: ");

		cout << "\nAre you sure you want to deposite [" << Amount << "] to " << Client1.FullName() << "'s Balance ? [Y/N] : ";

		char Answer = 'Y';

		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client1.Deposite(Amount);
			_SetSuccessScreenColor();
			cout << "\nAmount Deposited Successfully!\n";
			cout << "\n" << Client1.FullName() << "'s New Balance is [" << Client1.AccountBalance << "]!" << endl;
		}
		else
		{
			cout << "\nOperation was cancelled!\n";
		}


	}
};

