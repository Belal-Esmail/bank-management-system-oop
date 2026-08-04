#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsUtil.h"
class clsTotalBalancesScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "\t\t| " << setw(10) << left << Client.GetAccountNumber();
		cout << "\t\t| " << setw(25) << left << Client.FullName();
		cout << "\t\t| " << setw(10) << left << Client.AccountBalance;
	}

public:
	static void ShowTotalBalances()
	{
		vector<clsBankClient> vClient = clsBankClient::GetClientsList();

		string Title = "\t Balances List Screen";
		string SubTitle = "\t    (" + to_string(vClient.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t\t\n            __________________________________________________";
		cout << "__________________________________\n" << endl;

		cout << "\t\t| " << left << setw(10) << "Accout Number";
		cout << "\t\t| " << left << setw(25) << "Client Name";
		cout << "\t\t| " << left << setw(10) << "Balance";
		cout << "\t\t\n            __________________________________________________";
		cout << "__________________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClient.size() == 0)
		{
			cout << "\t\t\tNo Clients Available In the Syestem.\n";
		}
		else
		{
			for (clsBankClient Client : vClient)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}
		}

		cout << "\t\t\n            __________________________________________________";
		cout << "__________________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balances = $" << TotalBalances << endl << endl;
		cout << "\t\t\t\t\t   [" << clsUtil::NumberToText(TotalBalances) << "]";
	}
};

