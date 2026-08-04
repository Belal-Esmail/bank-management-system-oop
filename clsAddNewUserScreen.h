#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUser.h"
class clsAddNewUserScreen : protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name  : ";
		User.FirstName = clsInputValidation::ReadString();

		cout << "\nEnter Last Name   : ";
		User.LastName = clsInputValidation::ReadString();

		cout << "\nEnter Email       : ";
		User.Email = clsInputValidation::ReadString();

		cout << "\nEnter Phone       : ";
		User.Phone = clsInputValidation::ReadString();

		cout << "\nEnter Password    : ";
		User.Password = clsInputValidation::ReadString();

		cout << "\nEnter Permissions : ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'Y';

		cout << "\nDo you want to give full access [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n";
		cout << "\n===============================\n";
		cout << "\nShow Client List [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd Client       [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client    [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client    [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdaetClient;
		}

		cout << "\nFind Client      [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}


		cout << "\nTransactios      [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users     [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register   [Y/N] ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}

		return Permissions;
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n-------------------------";
		cout << "\nFirst Name  : " << User.FirstName;
		cout << "\nLast Name   : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n-------------------------\n";
	}


public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t Add New User Screen");

		string UserName = "";

		cout << "\nPlease Enter a User Name : ";
		UserName = clsInputValidation::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName is Already Used! Choose another one : ";
			UserName = clsInputValidation::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}

		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError! User wasn't saves becase it's empty.";
			break;
		}

		case clsUser::enSaveResults::svFaildUserExists:
		{
			cout << "\nError! User wasn't saves becase UserName is used!\n";
			break;
		}
		


		}




	}
};

