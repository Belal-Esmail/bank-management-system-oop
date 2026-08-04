#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <vector>

class clsListUserScreen : protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(25) << left << User.Email;
		cout << "| " << setw(12) << left << User.Permissions;
	}


public:
	static void ShowListUsersList()
	{
		vector<clsUser> vUsers = clsUser::GetUsersList();
		string Title = "\t   User List Screen";
		string SubTilte = "\t   (" + to_string(vUsers.size()) + ") User(s).";
		_DrawScreenHeader(Title, SubTilte);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(12) << "Permissions";

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\tNo Users Available In the System\n";
		}

		else
		{
			for (clsUser User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}
		}
		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________________\n" << endl;


	}
};

