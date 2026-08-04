#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsDate.h"
class clsUtil
{
public:
    enum enCharType {
        SamallLetter = 1, SmallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        if (From > To)
        {
            int Temp = From;
            From = To;
            To = Temp;
        }

        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        // This function generates a random character
// based on the selected character type.
// It can generate:
// Capital letters (A-Z)
// Small letters (a-z)
// Digits (0-9)
// Special characters (! to /)


        // If MixChars is selected, choose a random type:
        // 1 = CapitalLetter
        // 2 = SamallLetter
        // 3 = Digit
        if (CharType == MixChars)
        {
            CharType = enCharType(RandomNumber(1, 3));
        }

        switch (CharType)
        {
        case enCharType::SamallLetter:

            // ASCII codes:
            // a = 97
            // z = 122
            // Generate a random lowercase letter (a-z)
            return char(RandomNumber(97, 122));

        case enCharType::CapitalLetter:

            // ASCII codes:
            // A = 65
            // Z = 90
            // Generate a random uppercase letter (A-Z)
            return char(RandomNumber(65, 90));

        case enCharType::SpecialCharacter:

            // ASCII codes from 33 to 47:
            // ! " # $ % & ' ( ) * + , - . /
            // Generate a random special character
            return char(RandomNumber(33, 47));

        case enCharType::Digit:

            // ASCII codes:
            // 0 = 48
            // 9 = 57
            // Generate a random digit character (0-9)
            return char(RandomNumber(48, 57));

        default:

            // Fallback value:
            // Return a random capital letter if CharType is invalid
            return char(RandomNumber(65, 90));
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        string key = "";

        key = GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4) ;
        return key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    // Shuffle (randomly mix) the array elements.
// We swap two random positions many times to randomize the order.
    static void ShuffleArray(int arr[100], int ArrLength)
    {
        // Repeat as many times as the number of elements.
        for (int i = 0; i < ArrLength; i++)
        {
            // RandomNumber returns a number from 1 to ArrLength.
            // Array indexes start from 0, so we subtract 1.
            //
            // Example:
            // RandomNumber(1,5) -> 3
            // 3 - 1 -> index 2
            // arr[2] means the third element in the array.
            //
            // The random numbers are used as ARRAY INDEXES,
            // not as values to print or store.
            //
            // Pick two random positions and swap their values.
            Swap(arr[RandomNumber(1, ArrLength) - 1],
                arr[RandomNumber(1, ArrLength) - 1]);
        }
    }
    // Shuffle (randomly mix) the string array elements.
// Works exactly like the integer version,
// but swaps strings instead of integers.
    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            // Generate two random indexes.
            // Subtract 1 because RandomNumber starts from 1,
            // while array indexes start from 0.
            //
            // Example:
            // arr[0] = "Ali"
            // arr[1] = "Ahmed"
            // arr[2] = "Omar"
            //
            // If random indexes are 0 and 2,
            // Swap(arr[0], arr[2]) exchanges
            // "Ali" with "Omar".
            Swap(arr[RandomNumber(1, arrLength) - 1],
                arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static string Tab(short NumberOfTabs)
    {
        string Tab = "";

        for (short i = 1; i <= NumberOfTabs; i++)
        {
            Tab += "\t";
        }
        return Tab;
    }

    static void FillArrayWithRandomNumbers(int Arr[100], int ArrLength, int From, int To)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string Arr[100], int ArrLength, enCharType CharType, short WordLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Arr[i] = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static string EncryptText(string Text, short EncryptionKey = 2)
    {
        // Loop through every character in the string
        for (size_t i = 0; i < Text.length(); i++)
        {
            // Convert character to ASCII value,
            // add the encryption key,
            // then convert back to character.
            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        // Return encrypted text
        return Text;
    }

    static string DecryptText(string Text, short EcncryptionKey = 2)
    {
        for (size_t i = 0; i < Text.length(); i++)
        {
            Text[i] = char(int(Text[i]) - EcncryptionKey);
        }
        return Text;
    }

    static string NumberToText(int Number)
    {

        if (Number == numeric_limits<int>::min())
        {
            return "Number is out of supported range";
        }

        if (Number < 0)
        {
            return "Minus " + NumberToText(-Number);
        }

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }



};




