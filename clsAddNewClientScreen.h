#pragma once

#include "clsScreen.h"
class clsAddNewClientScreen : protected clsScreen
{
private:
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
	static void ShowAddNewClientScreen()
	{

        if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient))
        {
            return;//This Will exit the function and it will not continue..
        }


		_DrawScreenHeader("\t  Add New Client Screen");

        string AccontNumber = "";

        cout << "Please enter Account Number : ";
        AccontNumber = clsInputValidation::ReadString();

        while (clsBankClient::IsClientExist(AccontNumber))
        {
            cout << "\nAccont Number is already used, please chooce another one : ";
            AccontNumber = clsInputValidation::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccontNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceded:
        {
            cout << "\nAccount Added Successfuly :-) \n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account wasn't saved because it's empty";
            break;
        }

        case clsBankClient::enSaveResults::svFailedAccountNumberExists:
        {
            cout << "\nAccont Number is already used, please chooce another one \n";
            break;
        }

        }
	}
};

