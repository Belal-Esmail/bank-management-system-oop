#pragma once
#include "clsScreen.h"
#include "clsString.h"
#include "clsBankClient.h"
#include <fstream>
#include <string>
#include <vector>
class clsTransferLogScreen : protected clsScreen
{
private:
	static void PrintTransferLogRecord(clsBankClient::stTransferLogRecord Record)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << Record.DataTime;
		cout << "| " << setw(15) << left << Record.SourceAccountNumber;
		cout << "| " << setw(15) << left << Record.DestinationAccountNumber;
		cout << "| " << setw(10) << left << Record.Amount;
		cout << "| " << setw(10) << left << Record.SourceBalanceAfter;
		cout << "| " << setw(10) << left << Record.DestinationBalanceAfter;
		cout << "| " << setw(10) << left << Record.UserName;
	}
public:
	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

		string Title = "\t Transfer Log List Screen";
		string SubTitle = "\t   (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(15) << "S.Acct";
		cout << "| " << left << setw(15) << "D.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(10) << "User";

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vTransferLogRecord.size() == 0)
		{
			cout << "\t\t\tNo Transfers Available in the System!" << endl;
		}
		else
		{
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
			{
				PrintTransferLogRecord(Record);
				cout << endl;
			}
		}


	}
};

