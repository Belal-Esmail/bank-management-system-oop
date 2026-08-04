#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;
class clsCurrency
{

private:
	enum enMode
	{
		EmptyMode = 0, UpdateMode = 1
	};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData;

		vCurrencyData = clsString::Split(Line, Seperator);

		if (vCurrencyData.size() < 4)
		{
			return _GetEmptyCurrencyObject();
		}

		try
		{
			return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1],
				vCurrencyData[2], stof(vCurrencyData[3]));
		}
		catch (...)
		{
			return _GetEmptyCurrencyObject();
		}
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector<clsCurrency> vCurrency;

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
					if (!Currency.IsEmpty())
						vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrency;



	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string stCurrencyRecord = "";

		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> _vCurrency)
	{
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;

			for (clsCurrency Currency : _vCurrency)
			{
				DataLine = _ConvertCurrencyObjectToLine(Currency);
				MyFile << DataLine << endl;
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsCurrency> _vCurrency = _LoadCurrencyDataFromFile();

		for (clsCurrency& Currency : _vCurrency)
		{
			if (Currency.CurrrencyCode() == CurrrencyCode())
			{
				Currency = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(_vCurrency);

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	 }

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line.empty())
					continue;

				clsCurrency Currency =
					_ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(
					Currency.CurrrencyCode()) == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line.empty())
					continue;

				clsCurrency Currency =
					_ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(
					Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency1.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		else
		{
			return (float)(AmountInUSD * Currency2.Rate());
		}
	}
};

