#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <vector>
#include <string>
#include "clsString.h"
#include <fstream>

class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(15) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
		
	}
	
	
	

public:

	static void ShowLoginRegisterScreen()
	{

		if (!CheckAccessRight(clsUser::enPermissions::pLoginRegister))
		{
			return;//This Will exit the function and it will not continue..
		}


		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\t Login Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(10) << "Permissions";

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
		{
			cout << "\t\t\tNo Logins Available In the System.";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{
				PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
	}
};

