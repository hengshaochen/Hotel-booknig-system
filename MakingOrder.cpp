// MakingOrder.h
// MakingOrder class definition. 
#include <iostream>
using namespace std;
#include "MakingOrder.h"

// constructor initializes data members
MakingOrder::MakingOrder( AccountDatabase &theAccountDatabase, OrderDatabase &theOrderDatabase )
	:accountDatabase( theAccountDatabase ) , orderDatabase( theOrderDatabase )
{
}

// start the makingOrder
void MakingOrder::run( string email ) 
{
	int bufCode ;
	int bufAmount;

	// 將使用者所輸入email的那筆資料的email   Full Name   Shipping Address   Phone Number 放入urrentAccount
	// 先找出使用者所輸入的email那筆資料是 accountDatabase 中的第幾筆
	currentAccount.setEmail ( accountDatabase.getAccount( email )->getEmail() );
	currentAccount.setPassword ( accountDatabase.getAccount( email )->getPassword() );
	currentAccount.setName ( accountDatabase.getAccount( email )->getName() );
	currentAccount.setPhone ( accountDatabase.getAccount( email )->getPhone() );
	currentAccount.setAddress ( accountDatabase.getAccount( email )->getAddress() );
	// --------------- End of setting currentAccount information .

	currentAccount.displayCart() ;
		
	cout << endl << "Enter cuisine code:" ;
	cin  >> bufCode;

	cout << endl << endl << "Enter quantity: " ;
	cin  >> bufAmount;

	currentAccount.modifyCart( bufCode , bufAmount );
	currentAccount.displayCart() ;


	while ( true )
	{
		cout << endl << endl << "1. Continue Shopping" << endl << "2. Proceed to Checkout" << endl << "3. Abandon" << endl << "?" ;
		int choice;
		cin  >> choice;

		while ( choice < 1 && choice > 3 )
		{
			cerr << "\nIncorrect choice" << endl;
			cin  >> choice ;
		}

		switch ( choice ) 
		{
		case 1: // 繼續購物
			cout << endl << "Enter cuisine code:" ;
			cin  >> bufCode;

			cout << endl << endl << "Enter quantity: " ;
			cin  >> bufAmount;

			currentAccount.modifyCart( bufCode , bufAmount );
			currentAccount.displayCart() ;
			break;
		case 2: // 結帳
			checkout( &currentAccount ); 
			return ;
		case 3: // 放棄
			break;
		} // end switch

		if ( choice ==2 && choice == 3 )
			break;
	}

}

// creates an order, and push it into orderDatabase
// 建立此訂單 , 把它放入orderDatabase中
void MakingOrder::checkout( Account* userAccountPtr )
{
	Order nowOrder ;  // 建立一個佔存的Order

	//orderNumber[ 0 ] = 41 + rand() % 89 ;
	for ( int i=0 ; i <= 9 ; i++ )
		orderNumber[ i ] = ( ( rand ()  % 10 ) + 48 );
	orderNumber[ 10 ] = '\0' ;

	// --------------- 設定Order --------------- //
	nowOrder.setOrderNumber( orderNumber );
	nowOrder.setEmail( userAccountPtr->getEmail() );
	nowOrder.setOrderDetails( userAccountPtr->getCart() );
	// --------------- 設定Order --------------- //

	cout << endl << endl << "Order Number: " << orderNumber 
		 << endl << "Full Name: " << userAccountPtr->getName()
		 << endl << "Shipping Address: " << userAccountPtr->getAddress()
		 << endl << "Phone Number: " << userAccountPtr->getPhone()
		 << endl << "Bank account: 合作金庫 0062013162077139" << endl ;
	
	orderDatabase.pushBack( nowOrder );  // 將nowOrder放入orderDatabase資料庫中

	nowOrder.displayOrderDetails() ;

}