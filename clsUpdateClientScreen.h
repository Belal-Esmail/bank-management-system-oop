#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n-------------------------";
		cout << "\nFirst Name      : " << Client.FirstName;
		cout << "\nLast Name       : " << Client.LastName;
		cout << "\nFull Name       : " << Client.FullName();
		cout << "\nEmail           : " << Client.Email;
		cout << "\nPhone           : " << Client.Phone;
		cout << "\nAcc. Number     : " << Client.GetAccountNumber();
		cout << "\nBalance         : " << Client.AccountBalance;
		cout << "\n-------------------------\n";
	}

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name : ";
		Client.FirstName = clsInputValidation::ReadString();

		cout << "\nEnter Last Name : ";
		Client.LastName = clsInputValidation::ReadString();

		cout << "\nEnter Email : ";
		Client.Email = clsInputValidation::ReadString();

		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidation::ReadString();

		cout << "\nEnter Pin Code : ";
		Client.PinCode = clsInputValidation::ReadString();



		cout << "\nEnter Account Balance : ";
		Client.AccountBalance = clsInputValidation::ReadFloatNumber();


	}
public:

	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRight(clsUser::enPermissions::pUpdaetClient))
		{
			return;//This Will exit the function and it will not continue..
		}


		_DrawScreenHeader("\t  Update Client Info");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, Choose another one : ";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\nAre you sure you want to update this client info? [Y/N] : ";
		char Answer = 'Y';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			cout << "\n\nUpdate Client Info: ";
			cout << "\n______________________\n";



			_ReadClientInfo(Client1);
			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client1.Save();

			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceded:
			{
				cout << "\nAccount Updated Successfully :-)\n";
				break;
			}

			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError: account wasn't saved because it is empty.";
				break;
			}

			case clsBankClient::enSaveResults::svFailedAccountNumberExists:
			{
				cout << "\nError: account number already exists.";
				break;
			}
			}
		}
	}
};

