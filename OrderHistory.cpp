// OrderHistory.cpp
// Member-function definitions for class OrderHistory.
#include <iostream>
#include <iomanip>
using namespace std;
#include "OrderHistory.h"

// constructor initializes data members
OrderHistory::OrderHistory( AccountDatabase &theAccountDatabase, OrderDatabase &theOrderDatabase )
	: accountDatabase( theAccountDatabase ) , orderDatabase( theOrderDatabase )
{
}

// 進行查詢某個Email共訂了幾筆資料
// 首先,先查出那筆email是在orderDatabase資料庫中的第幾筆資料
void OrderHistory::run( string email )
{
	int choice ;
	vector< Order > history ;  // 宣告一個local vector< Order > 來儲存現在使用者這個email 的訂票歷史 用history來存
	orderDatabase.getOrders( email , history );
	
	if ( history.size() == 0 )
	{
		cout << endl << "Your have no order history!" << endl;
		return ;
	}
	

	cout << endl << "Your order history:" << endl
		 << "Code    Order no.     Name"  << endl;
		 
		 for ( int i=0 ; i < history.size() ; i++ )
		 {
			 cout << setw(4) << i << setw(13) << history[ i ].getOrderNumber() << setw(9) << accountDatabase.getAccount( email )->getName() << endl; // name;
		 }

	cout << endl << endl << "Email address: " << email << endl << endl;

	cout << "Choose a code (0 ~ " << history.size()-1 << " )  :" ;
	cin  >> choice;

	cout << endl << endl << "Your order details:";

	history[ choice ].displayOrderDetails();

}