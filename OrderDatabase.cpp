// OrderDatabase.cpp
// Member-function definitions for class OrderDatabase.
#include <iostream>
#include <fstream>
using namespace std;
#include "OrderDatabase.h"

// constructor loads orders from Orders.dat
OrderDatabase::OrderDatabase()
{
	loadOrderDetails();
}

// destructor saves orders into Orders.dat
OrderDatabase::~OrderDatabase()
{
	saveOrderDetails();
}

// Add newOrder at the end of orders
void OrderDatabase::pushBack( Order &newOrder )
{
	orders.push_back( newOrder );
}

// puts all Order objects containing specified
// email address into historicalOrders
// 由Email來看 , 這個Email 訂了什麼東西
// 所以 , 使用者輸入的theEmail , 則在Order資料表中找出這個theEmail所有訂的歷史清單放入historicalOrders
void OrderDatabase::getOrders( string theEmail, vector< Order > &historicalOrders )
{
	for ( int i=0 ; i < orders.size() ; i++ )
	{
		if ( orders[ i ].getEmail().compare( theEmail ) == 0 )    // orders資料庫中的Email 和使用者輸入的相符
		{
			historicalOrders.push_back( orders[ i ] );   // 將該筆吻合的資料放入historicalOrders
		}
	}
}

void OrderDatabase::loadOrderDetails()
{
	Order oneOrder;
	ifstream loadOrder( "Orders.dat" , ios::binary | ios::in );

	if ( !loadOrder )
	{
		cerr << endl << "This program can't open the file 'Orders.dat'. " 
			 << endl << "Please check again." << endl;
		system( "PAUSE" );
		exit ( 1 );
	}

	while( !loadOrder.eof() )
	{
		loadOrder.read( reinterpret_cast < char * > ( &oneOrder ) , sizeof ( oneOrder ) );
		orders.push_back( oneOrder );
	}
	orders.pop_back() ;  // ********************************************** Important 
						 // 一定要pop_back() , 因為我們讀進資料是使用 eof() , 一開始檔案為空
						 // 他還是會進去跑一次 , 第二次才會回傳eof 為true ..... 所以必定要pop_back()

	loadOrder.close();
}

void OrderDatabase::saveOrderDetails()
{
	ofstream saveOrder( "Orders.dat" , ios::binary | ios::out );

	if ( !saveOrder )
	{
		cerr << endl << "This program can't save to the file 'Orders.dat'. " 
			 << endl << "Please check again." << endl;
		system( "PAUSE" );
		exit ( 1 );
	}

	for ( int i=0 ; i < orders.size() ; i++ )
	{
		saveOrder.write( reinterpret_cast < char * > ( &orders[ i ] ) , sizeof ( orders[ i ] ) );
	}
	saveOrder.close();
}