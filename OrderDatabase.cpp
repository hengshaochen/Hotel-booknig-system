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
// ��Email�Ӭ� , �o��Email �q�F����F��
// �ҥH , �ϥΪ̿�J��theEmail , �h�bOrder��ƪ���X�o��theEmail�Ҧ��q�����v�M���JhistoricalOrders
void OrderDatabase::getOrders( string theEmail, vector< Order > &historicalOrders )
{
	for ( int i=0 ; i < orders.size() ; i++ )
	{
		if ( orders[ i ].getEmail().compare( theEmail ) == 0 )    // orders��Ʈw����Email �M�ϥΪ̿�J���۲�
		{
			historicalOrders.push_back( orders[ i ] );   // �N�ӵ��k�X����Ʃ�JhistoricalOrders
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
						 // �@�w�npop_back() , �]���ڭ�Ū�i��ƬO�ϥ� eof() , �@�}�l�ɮ׬���
						 // �L�٬O�|�i�h�]�@�� , �ĤG���~�|�^��eof ��true ..... �ҥH���w�npop_back()

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