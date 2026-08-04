#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsCurrency.h"
class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency, string Title)
	{
		cout << "\n" << Title << "\n";
		cout << "\n____________________\n";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n____________________\n";
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode = "";

		cout << Message ;

		CurrencyCode = clsInputValidation::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, Choose another one : ";
			CurrencyCode = clsInputValidation::ReadFloatNumber();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static float _ReadAmount()
	{
		float Amount = 0;

		cout << "\nEnter Amount to Exchange : ";
		Amount = clsInputValidation::ReadFloatNumber();

		return Amount;
	}

	static void _PrintCurrencyCalculation(clsCurrency Currency1, clsCurrency Currency2, float Amount)
	{
		_PrintCurrencyCard(Currency1, "Convert From");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrrencyCode() << " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrrencyCode() == "USD")
		{
			return;
		}
		
		_PrintCurrencyCard(Currency2, "Convertirn From USD To : ");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		cout << Amount << " " << Currency1.CurrrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrrencyCode();

	}

	
public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'Y';
		while (toupper(Continue) == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency 1 Code : ");
			clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency 2 Code : ");
			float Amount = _ReadAmount();

			_PrintCurrencyCalculation(Currency1, Currency2, Amount);

			cout << "\n\nDo you want to perform another calculation? [Y/N] : ";
			cin >> Continue;
		}
	}
};

