// Order.cpp
// Member-function definitions for class Order.
#include <iostream>
#include <iomanip>
using namespace std;
#include "Order.h"


// constructor initializes data members
Order::Order( string theOrderNumber, string theEmail )
{
	setOrderNumber( theOrderNumber );
	setEmail( theEmail );
}

void Order::setOrderNumber( string theOrderNumber )
{
	int length = theOrderNumber.size();
	length = ( length < 12 ? length : 11 ) ;
	theOrderNumber.copy( orderNumber , length );
	orderNumber[ length ] = '\0' ;
}

string Order::getOrderNumber() const
{
   string buffer( orderNumber );
   return buffer;
}

void Order::setEmail( string theEmail )
{
	int length = theEmail.size();
	length = ( length < 40 ? length : 39 ) ;
	theEmail.copy( email , length );
	email[ length ] = '\0' ;
}

string Order::getEmail() const
{
   string buffer( email );
   return buffer;
}


void Order::setOrderDetails( int theOrderDetails[] )
{
	for ( int i=0 ; i < 21 ; i++ )
	{
		quantity[ i ] = theOrderDetails[ i ];
	}
}

void Order::displayOrderDetails() const
{
	int totalPrice = 0;
	cout << endl << "        Item  Price  Quantity  Subtotal" << endl;
	for ( int i=0 ; i < 21 ; i++ )
	{
		if ( quantity[ i ] != 0 )
		{
			cout << setw(12) << cuisine_D[ i ] << setw(7) << price[ i ] << setw(10) << quantity[ i ] << setw(10)  << ( price[ i ] * quantity[ i ] ) << endl;
			totalPrice = totalPrice + ( price[ i ] * quantity[ i ] ) ;
		} 
	}
	cout << endl << endl << "Total:" << totalPrice << endl << endl;
}