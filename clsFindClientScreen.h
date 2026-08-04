#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsBankClient.h"
class clsFindClientScreen : protected clsScreen
{

private:
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
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pFindClient))
		{
			return;//This Will exit the function and it will not continue..
		}


		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is not found, choose another one : ";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found :-)" << endl;
		}
		else
		{
			cout << "\nClient is not found:-(" << endl;
		}

		_PrintClient(Client1);
	}
};

