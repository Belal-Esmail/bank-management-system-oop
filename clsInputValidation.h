#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsDate.h"
#include "clsString.h"
using namespace std;

class clsInputValidation
{

public:
	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}
	
	static int ReadIntNumber(string ErrorMessage = "Invalid Number! Enter again \n")
	{
		//Error Message is Optional Parameter
		int Number;
		
		while (!(cin >> Number) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number! Enter again \n")
	{
		//Error Message is Optional Parameter
		double Number;

		while (!(cin >> Number) || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadshortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		
		return Number;
	}
	

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again: ")
	{
		short Number = ReadshortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadshortNumber();
		}

		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again: ")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is out of range!\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is out of range!\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}


	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract all the whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};

