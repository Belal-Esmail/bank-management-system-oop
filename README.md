# Bank Management System (OOP)

A console-based banking system written in C++ to demonstrate object-oriented programming, reusable classes, permissions, file persistence, and transaction processing.

## Features

- Secure user login with role-based permissions
- Client account creation, search, update, and deletion
- Deposits and withdrawals with amount validation
- Account-to-account transfers with transaction logging
- Client balance summaries
- User management and login activity logs
- Currency listing, lookup, rate updates, and conversion
- Color-coded success and error feedback on Windows
- ASCII-style banking interface

## OOP Concepts

- Encapsulation through focused domain classes
- Inheritance for shared person and screen behavior
- Static utility and validation methods
- Method overloading and reusable components
- Separation between business logic and interface screens

## Project Structure

```text
BankManagementSystem.cpp       Application entry point
clsBankClient.h                Client and transaction logic
clsUser.h                      Authentication and permissions
clsCurrency.h                  Currency operations
clsScreen.h                    Shared console interface behavior
cls*.h                         Screens and reusable utility classes
examples/                      Small usage examples
*.example.txt                  Safe sample data templates
```

## Getting Started

1. Open `BankManagementSystem.sln` in Visual Studio.
2. If the data files do not exist, copy:
   - `Clients.example.txt` to `Clients.txt`
   - `Users.example.txt` to `Users.txt`
   - `TransferLog.example.txt` to `TransferLog.txt`
   - `LoginRegister.example.txt` to `LoginRegister.txt`
3. Build and run the project.
4. Use the sample administrator account:
   - Username: `Admin`
   - Password: `Admin1234`

`Currencies.txt` contains the currency data used by the exchange screens.


## Requirements

- C++17 or later
- Visual Studio with the Desktop development with C++ workload
- Windows console for the full color interface

## Security Note

This is an educational project. Its text-file persistence and simple Caesar-shift password encoding are designed to demonstrate programming concepts; they are not suitable for production banking software.

## Author

Belal Esmail
