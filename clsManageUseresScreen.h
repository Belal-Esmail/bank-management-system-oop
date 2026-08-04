#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsListUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUseresScreen : protected clsScreen
{
private:
	enum enManageUsersOptions
	{
		eListUsers = 1 , eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4,
		eFindUser = 5, eMainMenue = 6
	};

	static short ReadManageUsersMenueOptions()
	{
		short Choice = 0;
		cout << setw(20) << left << "\t\t\t\tChoose what do you want to do [1 - 6] : ";
		Choice = clsInputValidation::ReadShortNumberBetween(1, 6, "Wrong Input, please enter number between [1-6]: ");

		return Choice;
	}

	static void _ShowListUsersScreen()
	{
		/*cout << "List User Screen Will Be Here...";*/
		clsListUserScreen::ShowListUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		/*cout << "Add Users Screen Will Be Here...";*/
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		/*cout << "Delete Users Screen Will Be Here...";*/
		clsDeleteUserScreen::ShowDeleteUserScreen();

	}

	static void _ShowUpdateUserScreen()
	{
		/*cout << "Update Users Screen Will Be Here...";*/
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		/*cout << "Find Users Screen Will Be Here...";*/
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to manage users menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOptions(enManageUsersOptions ManageUsersOptions)
	{
		switch (ManageUsersOptions)
		{
		case enManageUsersOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eMainMenue:
		{
			//Do nothing here, the main menue will handlde it.
		}
		}
	}

public:
	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pManageUsers))
		{
			return;//This Will exit the function and it will not continue..
		}



		system("cls");

		_DrawScreenHeader("\t  Manage Users Menue");

		cout << setw(20) << left << "\t\t\t         Menue :" << endl;
		cout << "\t\t\t\t-----------\n\n";

		cout << setw(20) << left << "\t\t\t\t      [1] List Users.\n";
		cout << setw(20) << left << "\t\t\t\t      [2] Add New User.\n";
		cout << setw(20) << left << "\t\t\t\t      [3] Delete User.\n";
		cout << setw(20) << left << "\t\t\t\t      [4] Update User.\n";
		cout << setw(20) << left << "\t\t\t\t      [5] Find User.\n";
		cout << setw(20) << left << "\t\t\t\t      [6] Main Menue.\n";


		cout << "\t\t\t\t_________________________________________\n\n";

		_PerformManageUsersMenueOptions(enManageUsersOptions(ReadManageUsersMenueOptions()));

	} 
};

