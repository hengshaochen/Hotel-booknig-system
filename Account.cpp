// Account.cpp
// Member-function definitions for class Account.
#include <iostream>
#include <iomanip>
using namespace std;
#include "Account.h"


// constructor sets attributes
Account::Account( string Theemail , string Thepassword , string Thename, string Theaddress, string Thephone , int* cart )
{
	setEmail( Theemail );
	setPassword( Thepassword );
	setName( Thename );
	setAddress( Theaddress );
	setPhone( Thephone );
	setCart( cart );
}

// determines whether a user-specified password
// matches password in Account
// 使用者輸入的密碼是否等同於Account的密碼
bool Account::validatePassword( string userPassword ) const
{
	if ( password == userPassword )
		return true;
	else
		return false;
}

void Account::setEmail( string keyIn )
{
	int length = keyIn.size();
	length = ( length < 40 ? length : 39 ) ;
	keyIn.copy( email , length );
	email[ length ] = '\0' ;
}

string Account::getEmail() const
{
   string buffer( email );
   return buffer;
}

void Account::setPassword( string keyIn )
{
	int length = keyIn.size();
	length = ( length < 20 ? length : 19 ) ;
	keyIn.copy( password , length );
	password[ length ] = '\0' ;
}

string Account::getPassword() const
{
	string buffer( password );
	return buffer;
}

void Account::setName( string keyIn )
{
	int length = keyIn.size();
	length = ( length < 8 ? length : 7 ) ;
	keyIn.copy( name , length );
	name[ length ] = '\0' ;
}

string Account::getName() const
{
	string buffer( name );
	return buffer;
}

void Account::setAddress( string keyIn )
{
	int length = keyIn.size();
	length = ( length < 80 ? length : 79 ) ;
	keyIn.copy( address , length );
	address[ length ] = '\0' ;
}

string Account::getAddress() const
{
	string buffer( address );
	return buffer;
}

void Account::setPhone( string keyIn )
{
	int length = keyIn.size();
	length = ( length < 12 ? length : 11 ) ;
	keyIn.copy( phone , length );
	phone[ length ] = '\0' ;
}

string Account::getPhone() const
{
	string buffer( phone );
	return buffer;
}


//******
void Account::setCart( int * )
{
	for ( int i=0 ; i < 21 ; i++ )
	{
		cart[ i ] = 0;
	}
}
//******
int * Account::getCart()
{
	return cart;
}

// cart[ code ] is modified to amount
void Account::modifyCart( int code, int amount )
{
	cart[ code ] = amount;
}

// display email, name, address and phone of Account
void Account::displayAccountDetails() const 
{
	//cout << endl << "Order Number: " << 
	cout << endl << "Full Name: " << getName() << endl 
		 << endl << "Shipping Address: " << getAddress() << endl
		 << endl << "Phone Number: " << getPhone() << endl ;
}

// Code, Item and Quantity of each cuisine in the shopping cart
void Account::displayCart() const
{
	//Code        Item  Quantity
	cout << endl << "Code        Item  Quantity" << endl;
	
	for ( int i=0 ; i < 21 ; i++ )
		cout << setw(4) << i << setw(12)  << cuisine[ i ] << setw(10) << cart[ i ] << endl;
	
}