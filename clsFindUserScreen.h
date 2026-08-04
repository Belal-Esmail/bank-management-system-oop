#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUser.h"
class clsFindUserScreen : protected clsScreen
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

public:
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t Find User Screen");

		string UserName = "";

		cout << "\nPlease Enter a User Name : ";
		UserName = clsInputValidation::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Doesn't Exists! Enter Another One : ";
			UserName = clsInputValidation::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
			
		}
		else
		{
			cout << "\nUser Wasn't Found:-(\n";
		}

		_PrintUser(User);
	}
};

