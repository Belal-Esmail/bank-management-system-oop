#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"
class clsFindCurrency : protected clsScreen
{
private:
	

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card: \n";
		cout << "____________________\n";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n____________________\n";
	}
	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was Not Found :-(";
		}
	}
public:

	

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\nFind Currency Screen");

		
		
		cout << "\nFind By: [1] code or [2] Country? ";
		short Answer = 0;
		Answer = clsInputValidation::ReadShortNumberBetween(1,2 , "Wrong Input! Enter Number between [1-2].");

		if (Answer == 1)
		{
			string CurrencyCode = "";
			cout << "\nPlease Enter Currency Code : ";
			CurrencyCode = clsInputValidation::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);

			
		}

		else 
		{
			string CountryName = "";
			cout << "\nPlease Enter Country Name : ";
			CountryName = clsInputValidation::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
			_ShowResult(Currency);
		}

		
	}
};

