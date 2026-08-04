#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include <iomanip>

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions
	{
		eDeposite = 1, eWithdraw = 2, 
		eShowTotalBalance = 3,eTransfer = 4, eShowTransferLog ,eShowMianMenue = 6
	};

	static short ReadTransactionsMenueOptions()
	{
		cout << setw(20) << left << "\t\t\t\tChoose what do you want to do [1 - 6] : ";

	short Choice = clsInputValidation::ReadShortNumberBetween(1, 6, "Wrong Input! Please enter a number between [1 - 6].");

	return Choice;
	}

	static void _ShowDepositeScreen()
	{
		/*cout << "\n Deposite Screen Will be here.\n";*/
		clsDepositeScreen::ShowDepositeScreen();
	}

	static void _ShowWithDrawScreen()
	{
		/*cout << "\nWithdraw Screen Will be here.\n";*/
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		/*cout << "\nTotal Balance Will be here.\n";*/
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		/*cout << "\nTransfer Screen Will be here.." << endl;*/
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		/*cout << "\nShow Transfer Log Screen Will be here..";*/
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	

	static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
		case enTransactionsMenueOptions::eDeposite:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowMianMenue:
		{

		}
		}
	}
public:


	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pTransactions))
		{
			return;//This Will exit the function and it will not continue..
		}


		system("cls");

		_DrawScreenHeader("\t Transactions Menue");

		cout << setw(20) << left << "\t\t\t         Menue :" << endl;
		cout << "\t\t\t\t-----------\n\n";

		cout << setw(20) << left << "\t\t\t\t      [1] Deposite.\n";
		cout << setw(20) << left << "\t\t\t\t      [2] Withdraw.\n";
		cout << setw(20) << left << "\t\t\t\t      [3] Total Balance.\n";
		cout << setw(20) << left << "\t\t\t\t      [4] Transfer.\n";
		cout << setw(20) << left << "\t\t\t\t      [5] Transfer Log.\n";
		cout << setw(20) << left << "\t\t\t\t      [6] Main Menue.\n";
		

		cout << "\t\t\t\t_________________________________________\n\n";

		_PerformTransactionsMenueOptions(enTransactionsMenueOptions(ReadTransactionsMenueOptions()));
	}
};

