// AccountDatabase.h
// AccountDatabase class definition.
#ifndef ACCOUNT_DATABASE_H
#define ACCOUNT_DATABASE_H

#include <vector>
#include "Account.h" // Account class definition

class AccountDatabase
{
public:
   AccountDatabase(); // constructor loads accounts from Accounts.dat
   ~AccountDatabase(); // destructor saves accounts into Accounts.dat
   bool authenticateUser( string, string );// determine whether email address and password match those of an Account
   void pushBack( Account &newAccount ); // Add newAccount at the end of accounts
   Account * getAccount( string ); // get pointer to the first Account object in accounts, containing specified email address
private:
   vector< Account > accounts; // vector of the customer's accounts

   void loadAccountDetails();
   void saveAccountDetails();
}; // end class AccountDatabase

#endif // ACCOUNT_DATABASE_H