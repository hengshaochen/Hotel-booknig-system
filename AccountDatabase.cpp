// AccountDatabase.cpp
// Member-function definitions for class AccountDatabase.
#include <iostream>
#include <fstream>
using namespace std;
#include "AccountDatabase.h"

// constructor of AccountDatabase --> Loading accounts from Accounts.dat
AccountDatabase::AccountDatabase()
{
	loadAccountDetails() ;
}

// destructor of AccountDatabase --> Saving accounts from AccountDatabase
AccountDatabase::~AccountDatabase()
{
	saveAccountDetails() ;
}

// determine whether email address and password match those of an Account
// 確認E-mail地址和密碼有沒有對應的 
bool AccountDatabase::authenticateUser( string keyEmail, string keyPassword )
{
	for ( int i=0 ; i < accounts.size() ; i++ )
	{
		if ( accounts[ i ].getEmail() == keyEmail && accounts[ i ].getPassword() == keyPassword )
		{
			return true;
		}
	}
	return false;
}

// Add newAccount at the end of accounts
// 加入一筆新帳號到accounts中
void AccountDatabase::pushBack( Account &newAccount )
{
	accounts.push_back( newAccount );
}

// get pointer to the first Account object in accounts, containing specified email address
// 從accounts中取出和傳入E-mail相同的 , 回傳該格
Account* AccountDatabase::getAccount( string keyEmail )
{
	for ( int i=0 ; i < accounts.size() ; i++ )
	{
		if ( accounts[ i ].getEmail().compare( keyEmail ) == 0 )
			return &accounts[ i ];
	}
	return NULL; // 沒找到
}

void AccountDatabase::loadAccountDetails()
{
	Account oneAccount;
	ifstream loadAccounts( "Accounts.dat" , ios::binary | ios::in );
	if ( !loadAccounts )
	{
		cerr << endl << "This program can't open the file 'Accounts.dat'. " 
			 << endl << "Please check again." << endl;
		system( "PAUSE" );
		exit ( 1 );
	}
	while ( !loadAccounts.eof() )
	{
		loadAccounts.read( reinterpret_cast < char * > ( &oneAccount ) , sizeof ( oneAccount ) );
		accounts.push_back( oneAccount );
	}
	loadAccounts.close();
}

void AccountDatabase::saveAccountDetails()
{
	ofstream saveAccounts( "Accounts.dat" , ios::binary | ios::out );
	if ( !saveAccounts ) 
	{
		cerr << endl << "This program can't save to the file 'Accounts.dat'. " 
			 << endl << "Please check again." << endl;
		system( "PAUSE" );
		exit ( 1 );
	}

	for ( int i=0 ; i < accounts.size() ; i++ )
		saveAccounts.write( reinterpret_cast < char * > ( &accounts[ i ] ) , sizeof ( accounts[ i ] ) );

	saveAccounts.close();
}