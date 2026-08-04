#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsPerson.h"
#include "clsBankClient.h"


class clsDeleteClientScreen : protected clsScreen
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

public:

	static void ShowDeleteClientScreen()
	{
        if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient))
        {
            return;//This Will exit the function and it will not continue..
        }


		_DrawScreenHeader("\t  Delete Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidation::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choose another one : ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre you sure you want to delete this client? [Y/N] : ";
       
        char Answer = 'Y';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintClient(Client1);
            }
            else
            {
                cout << "Error Client Wasn't Deleted!";
            }
        }



	}
};

