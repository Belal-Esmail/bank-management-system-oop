#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>
class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:

	enum enCurrenciesMenueOptions
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short _ReadCurrencyMenueOption()
	{
		cout << setw(20) << left << "\t\t\t\tChoose what do you want to do [1 - 5] : ";
		short Choice = clsInputValidation::ReadShortNumberBetween(1, 5);

		return Choice;
	}

	static void _ShowCurrenciesListScreen()
	{
		/*cout << "\nList Currencies Screen Will be here..";*/
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		/*cout << "\nFind Currency Screen Will be here..";*/
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		/*cout << "\nUpdate Rate Screen Will be here..";*/
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		/*cout << "\nCurrency Calculator Screen Will be here..";*/
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void GoBackToCurrencyMenueScreen()
	{
		cout << setw(20) << left << "\n\nPress any key to go back to Currency Menue...\n";
		system("pause>0");

		ShowCurrenciesMenue();
	}
	static void _PerfromCurrenciesMenueOption(enCurrenciesMenueOptions CurrencyMenueOption)
	{
		switch (CurrencyMenueOption)
		{
		case enCurrenciesMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			GoBackToCurrencyMenueScreen();
			break;
		}

		case enCurrenciesMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			GoBackToCurrencyMenueScreen();
			break;
		}

		case enCurrenciesMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			GoBackToCurrencyMenueScreen();
			break;
		}

		case enCurrenciesMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			GoBackToCurrencyMenueScreen();
			break;
		}

		case enCurrenciesMenueOptions::eMainMenue:
		{
			
			
		}
		}
	}
public:

	static void ShowCurrenciesMenue()
	{
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen");

		cout << setw(20) << left << "\t\t\t        Currency Exchange Menue :" << endl;
		cout << "\t\t\t\t-----------------------\n\n";
		cout << setw(20) << left << "\t\t\t\t      [1] List Currencies.\n";
		cout << setw(20) << left << "\t\t\t\t      [2] Find Currency.\n";
		cout << setw(20) << left << "\t\t\t\t      [3] Update Rate.\n";
		cout << setw(20) << left << "\t\t\t\t      [4] Currency Claculator.\n";
		cout << setw(20) << left << "\t\t\t\t      [5] Main Menue.\n";
		 

		cout << "\t\t\t\t_________________________________________\n\n";

		_PerfromCurrenciesMenueOption(enCurrenciesMenueOptions(_ReadCurrencyMenueOption()));
	}
};

