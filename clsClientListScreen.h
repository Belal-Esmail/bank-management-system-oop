#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>


class clsClientListScreen : protected clsScreen
{
private:

	static void PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(25) << left << Client.Email;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void ShowClientsList()
	{

		if (!CheckAccessRight(clsUser::enPermissions::pListClients))
		{
			return;//This Will exit the function and it will not continue..
		}


		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Clients";
		_DrawScreenHeader(Title, SubTitle);

		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(12) << "Balance";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;


		


		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System!";

		}
		else
		{
			for (clsBankClient Client : vClients)
			{

				
				PrintClientRecordLine(Client);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

	}

};

