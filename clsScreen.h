#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
#include <cstdlib>
using namespace std;

class clsScreen
{
protected:
	static void _ResetScreenColor()
	{
		system("color 0F");
	}

	static void _SetSuccessScreenColor()
	{
		system("color 2F");
	}

	static void _SetErrorScreenColor()
	{
		system("color 4F");
		cout << "\a";
	}

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		_ResetScreenColor();
		cout << "\n\t\t  ____    _    _   _ _  __  ______   ______ _____ _____ __  __";
		cout << "\n\t\t | __ )  / \\  | \\ | | |/ / / ___\\ \\ / / ___|_   _|  \\/  |";
		cout << "\n\t\t |  _ \\ / _ \\ |  \\| | ' /  \\___ \\  V /\\___ \\ | | | |\\/| |";
		cout << "\n\t\t | |_) / ___ \\| |\\  | . \\   ___) || |  ___) || | | |  | |";
		cout << "\n\t\t |____/_/   \\_\\_| \\_|_|\\_\\ |____/ |_| |____/ |_| |_|  |_|\n";
		cout << "\t\t\t\t_________________________________________";
		cout << "\n\n\t\t\t\t " << Title << endl;

		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t " << SubTitle << endl;
		}
		cout << "\t\t\t\t_________________________________________\n\n";

		cout << "\t\t\t\tUser : " << CurrentUser.UserName << endl;
		cout << "\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl;
		cout << "\t\t\t\t________________\n\n";

	}

	static bool CheckAccessRight(clsUser::enPermissions Permission)
	{

			if (!CurrentUser.CheckAccessPermission(Permission))
			{
				_SetErrorScreenColor();
			cout << "\t\t\t\t_________________________________________\n";
			cout << "\n\t\t\t\t    Access Denied! Contact your Admin.\n";
			cout << "\t\t\t\t_________________________________________\n";
			return false;
		}
			else
			{
				return true;
			}
	}
};

