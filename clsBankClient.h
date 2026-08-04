#pragma once

#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class clsBankClient : public clsPerson
{
public:
	struct stTransferLogRecord
	{
		string DataTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float SourceBalanceAfter;
		float DestinationBalanceAfter;
		string UserName;
	};

private:
	enum enMode
	{
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelte = false;

	

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		if (vClientData.size() != 7)
			return _GetEmptyClientObject();

		try
		{
			return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1],
				vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
		}
		catch (...)
		{
			return _GetEmptyClientObject();
		}
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
					clsBankClient Client = _ConvertLineToClientObject(Line);
					if (!Client.IsEmpty())
						vClients.push_back(Client);
			}

			MyFile.close();
		}
		return vClients;
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator; 
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static void  _SaveClientsDataToFile(vector<clsBankClient> vClient)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);
		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient c : vClient)
			{
				if (c.MarkForDelted() == false)
				{
					//We only write records that aren't marked for delete.
					DataLine = _ConvertClientObjectToLine(c);

					MyFile << DataLine << endl;
				}
				
			}

			MyFile.close();
		}
	}

	void _AddDateLineToFile(string stDataLine)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}

		
	}

	void _Update()
	{
		vector<clsBankClient> _vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& c : _vClients)
		{
			if (c.GetAccountNumber() == this->GetAccountNumber())
			{
				c = *this;
				break;
			}
        }
		_SaveClientsDataToFile(_vClients);

	}

	void _AddNew()
	{
		_AddDateLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _PrepareTransfterLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += GetAccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.GetAccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
		
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTransfterLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;

		vector<string> vTransferLogLine = clsString::Split(Line, Seperator);
		if (vTransferLogLine.size() != 7)
			return TransferLogRecord;

		try
		{
			TransferLogRecord.DataTime = vTransferLogLine[0];
			TransferLogRecord.SourceAccountNumber = vTransferLogLine[1];
			TransferLogRecord.DestinationAccountNumber = vTransferLogLine[2];
			TransferLogRecord.Amount = stof(vTransferLogLine[3]);
			TransferLogRecord.SourceBalanceAfter = stof(vTransferLogLine[4]);
			TransferLogRecord.DestinationBalanceAfter = stof(vTransferLogLine[5]);
			TransferLogRecord.UserName = vTransferLogLine[6];
		}
		catch (...)
		{
			return stTransferLogRecord{};
		}

		return TransferLogRecord;

	}


public:

	struct stTransferLog
	{
		string DateTime;
		string AccountNumber;

	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
    }

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkForDelted()
	{
		return _MarkForDelte;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = setAccountBalance)) float AccountBalance;

	string FullName()
	{
		return GetFirstName() + " " + GetLastName();
	}

	//No UI Related code inside object
	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n-------------------------";
		cout << "\nFirst Name      : " << FirstName;
		cout << "\nLast Name       : " << LastName;
		cout << "\nFull Name       : " << FullName();
		cout << "\nEmail           : " << Email;
		cout << "\nPhone           : " << Phone;
		cout << "\nAcc. Number     : " << _AccountNumber;
		cout << "\nBalance         : " << AccountBalance;
		cout << "\n-------------------------";

	}*/

	static clsBankClient Find(string AccountNumber)
	{
		

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //Read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();

	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //Read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client._AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();

	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	
	enum enSaveResults {svFaildEmptyObject = 0, svSucceded = 1, svFailedAccountNumberExists
	 = 2};
	
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
			
			}

		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceded;

			break;
		}

		case enMode::AddNewMode:


			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new Client
				_Mode = enMode::UpdateMode;

				return enSaveResults::svSucceded;
			}
			

		}
	}



	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}


	bool Delete()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& c : _vClients)
		{
			if (c.GetAccountNumber() == _AccountNumber)
			{
				c._MarkForDelte = true;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		double TotalBalance = 0;

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		for (clsBankClient Client : vClients)
		{
			TotalBalance += Client.AccountBalance;
		}

		return TotalBalance;
	}

	void Deposite(double Amount)
	{
		if (Amount <= 0)
			return;

		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount <= 0 || Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(float Amount , clsBankClient& DestinationClient, string UserName)
	{
		if (Amount <= 0 || Amount > AccountBalance ||
			GetAccountNumber() == DestinationClient.GetAccountNumber())
		{
			return false;
		}
		else
		{
			this->Withdraw(Amount);
			DestinationClient.Deposite(Amount);

			_RegisterTransferLog(Amount,DestinationClient, UserName);

			return true;
		}
		
	}

	static vector<stTransferLogRecord> GetTransferLogList()
	{
		vector<stTransferLogRecord> vTransferLogRecord;

		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			stTransferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{
				TransferRecord = _ConvertTransferLogLineToRecord(Line);

					if (!TransferRecord.DataTime.empty())
						vTransferLogRecord.push_back(TransferRecord);
			}
		}
		MyFile.close();

		return vTransferLogRecord;
	}
};

