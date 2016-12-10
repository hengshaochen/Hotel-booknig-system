// OrderDatabase.h
// OrderDatabase class definition. Represents the order's database.
#ifndef ORDER_DATABASE_H
#define ORDER_DATABASE_H

#include <vector>
#include "Order.h" // Order class definition

class OrderDatabase
{
public:
   OrderDatabase(); // constructor loads orders from Orders.dat
   ~OrderDatabase(); // destructor saves orders into Orders.dat
   void pushBack( Order &newOrder ); // Add newOrder at the end of orders
   void getOrders( string theEmail, vector< Order > &historicalOrders ); // puts all Order objects containing specified
private:                                                                 // email address into historicalOrders
   vector< Order > orders; // vector of the customer's orders

   void loadOrderDetails();
   void saveOrderDetails();
}; // end class OrderDatabase

#endif // ORDER_DATABASE_H