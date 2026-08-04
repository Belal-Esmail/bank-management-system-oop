#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "Global.h"

class clsTransferScreen : protected clsScreen
{
private:
	

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber(string FromOrTo)
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number to Transfer " << FromOrTo << ": ";
		AccountNumber = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found! Choose another one : ";
			AccountNumber = clsInputValidation::ReadString();
		}

		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer Amount : ";

		float Amount = clsInputValidation::ReadFloatNumberBetween(0.01f,
			numeric_limits<float>::max(), "Amount must be greater than zero. Enter again: ");

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the availabe Balance, Enter another Amount : ";
				Amount = clsInputValidation::ReadFloatNumberBetween(0.01f,
					numeric_limits<float>::max(), "Amount must be greater than zero. Enter again: ");
		}

		return Amount;
	}
public:
	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\t  Transfer Screen");

		string SourceAccountNumber = _ReadAccountNumber("From");
		clsBankClient SourceClient = clsBankClient::Find(SourceAccountNumber);

		_PrintClient(SourceClient);

		string DestinationAccountNumber = _ReadAccountNumber("To");
		while (DestinationAccountNumber == SourceAccountNumber)
		{
			cout << "\nSource and destination accounts must be different.\n";
			DestinationAccountNumber = _ReadAccountNumber("To");
		}

		clsBankClient DestinationClient = clsBankClient::Find(DestinationAccountNumber);

		_PrintClient(DestinationClient);
		
		float Amount = ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this operation? [Y/N]: ";
		char Answer = 'Y';
		cin >> Answer;
		
		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				_SetSuccessScreenColor();
				cout << "\nTransfer completed successfully!\n";
			}

			else
			{
				_SetErrorScreenColor();
				cout << "\nTransfer Failed!\n";
			}
		}
		else
		{
			cout << "\nTransfer Canceld!\n";
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
		

		




	}
};

