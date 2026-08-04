#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card: \n";
		cout << "\n____________________\n";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n____________________\n";
	}

	static float _ReadRate()
	{
		float NewRate = 0;

		cout << "\nEnter New Rate : ";
		NewRate = clsInputValidation::ReadFloatNumber();

		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t Update Rate Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code : ";
		CurrencyCode = clsInputValidation::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Does Not Exists! Please Try Another One : ";
			CurrencyCode = clsInputValidation::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrencyCard(Currency);

		cout << "\nAre you sure you want to update the rate of this Currency ? [Y/N] : ";
		char Answer = 'Y';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\nUpdate Currency Rate : \n";
			cout << "\n_______________________";
			

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :- )";

			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nUpdating Canceld!" << endl;
		}

	}

};

