// OrderHistory.h
// OrderHistory class definition.
#ifndef ORDER_HISTORY_H
#define ORDER_HISTORY_H

#include "AccountDatabase.h" // AccountDatabase class definition
#include "OrderDatabase.h" // OrderDatabase class definition

class OrderHistory
{
public:
   OrderHistory( AccountDatabase &, OrderDatabase & ); // constructor initializes data members
   void run( string email ); // start the OrderHistory
private:
   AccountDatabase &accountDatabase; // account database
   OrderDatabase &orderDatabase; // order database
}; // end class OrderHistory

#endif // ORDER_HISTORY_H