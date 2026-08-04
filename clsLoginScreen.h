#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		string UserName, Password;
		bool LoginField = false;
		short FieldLoginCount = 0;
		do
		{
			if (LoginField)
			{
				FieldLoginCount++;

				_SetErrorScreenColor();
				cout << "\nInvalid UserName/Password!\n";
				cout << "\nYou have " << 3 - FieldLoginCount << " Trial(s) to Login" << endl;
			}

			if (FieldLoginCount == 3)
			{
				cout << "\nYou Are Locked After 3 Trials.";
				return false;
			}
					
					
			
			cout << "\nEnter UserName : ";
			cin >> UserName;

			cout << "\nEnter Password : ";
			cin >> Password;


			CurrentUser = clsUser::Find(UserName, Password);

			LoginField = CurrentUser.IsEmpty();
			
			

		} while (LoginField);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();

		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\t Login Screen");
		return _Login();
	}
};

