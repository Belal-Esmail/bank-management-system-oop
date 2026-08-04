#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUser.h"
class clsUpdateUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{

		cout << "\nUser Card:";
		cout << "\n-------------------------";
		cout << "\nFirst Name      : " << User.FirstName;
		cout << "\nLast Name       : " << User.LastName;
		cout << "\nFull Name       : " << User.FullName();
		cout << "\nEmail           : " << User.Email;
		cout << "\nPhone           : " << User.Phone;
		cout << "\nUser Name       : " << User.UserName;
		cout << "\nPermissions     : " << User.Permissions;
		cout << "\n-------------------------\n";
	}

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

public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t   Update User Screen");

		string UserName = "";

		cout << "\nPlease Enter a User Name : ";
		UserName = clsInputValidation::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Doesn't Exists! Enter Another One : ";
			UserName = clsInputValidation::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char Answer = 'Y';

		cout << "\nAre you sure you want to update this user [Y/N] : ";

		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\nUpdate User Info : ";
			cout << "\n====================\n";
			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResult;

			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUser Updated Succefully!" << endl;
				_PrintUser(User);
				break;
			}

			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError: user wasn't updated because it is empty.";
				break;
			}

			case clsUser::enSaveResults::svFaildUserExists:
			{
				cout << "\nError: user already exists.";
				break;
			}
			}
			
		}
		else
		{
			
		}
	}
};

