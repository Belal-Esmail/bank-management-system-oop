#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUser.h"
class clsDeleteUserScreen : protected clsScreen
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
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t  Delete User Screen");

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

		cout << "\nAre you sure you want to delete this user [Y/N] : ";

		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			User.Delete();
			cout << "\nUser Deleted Succefully :-)\n";

			_PrintUser(User);
		}
		else
		{
			cout << "\nError! User Wasn't Deleted.";
		}
	}

};

