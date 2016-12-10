// MakingOrder.h
// MakingOrder class definition.
#ifndef MAKING_ORDER_H
#define MAKING_ORDER_H

#include "AccountDatabase.h" // AccountDatabase class definition
#include "OrderDatabase.h" // OrderDatabase class definition

class MakingOrder
{
public:
   MakingOrder( AccountDatabase &, OrderDatabase & ); // constructor initializes data members
   void run( string email ); // start the MakingOrder
   int editCart(); // modify the quantity of some cuisine in the shopping cart
   void checkout( Account * userAccountPtr ); // creates an order, and push it into orderDatabase
private:
	char orderNumber[12];
	Account currentAccount; // current account
	AccountDatabase &accountDatabase; // account database
	OrderDatabase &orderDatabase; // order database

   int enterChoice(); // let user choose: 1. Continue Shopping, 2. Proceed to Checkout or 3. Abandon
}; // end class MakingOrder

#endif // MAKING_ORDER_H