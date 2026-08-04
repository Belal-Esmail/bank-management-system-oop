#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <vector>
class clsCurrenciesListScreen : protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << Currency.Country();
		cout << "| " << setw(10) << left << Currency.CurrrencyCode();
		cout << "| " << setw(35) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:
	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t Cureencies List Screen";
		string SubTitle = "\t (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(35) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
		{
			cout << "\n\t\t\tNo Currencies Available in the System.\n";
		}

		for (clsCurrency Currency : vCurrencies)
		{
			_PrintCurrencyRecordLine(Currency);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}
};

