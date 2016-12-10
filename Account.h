// Account.h
// Account class definition.
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

const char cuisine[21][16] = { "¨§¨F¤j¥]", "ªÛ³Â¤j¥]", "¨¡ªd¤j¥]", "ÂA¦×¤j¥]", "µæ¦×¤j¥]", "­»Û£¯À¥]",
                               "µæ¦×»]»å", "½¼¦×»]»å", "ÂA³½»]»å", "­»Û£¯À»å", "½¼¤¯¿N½æ", "¤pÅ¢¥]",
                               "ÂA¦×ºê¤l", "¨§¨Fºê¤l", "´ò¦{ºê¤l", "­ì¬ØÂû´ö", "¤¸¬Ø¤û¦×´ö", "¤KÄ_¶º",
                               "¨ª¨§ÃP¿|", "¤d¼hªo¿|", "»ñ±ù¶p" };

class Account
{
public:
   Account( string = "", string = "", string = "", string = "", string = "" , int* = 0 ); // constructor sets attributes
   
   bool validatePassword( string userPassword ) const; // determines whether a user-specified password
                                                       // matches password in Account

   // accessor functions for email
   void setEmail( string keyIn );
   string getEmail() const;

   // accessor functions for password
   void setPassword( string );
   string getPassword() const;

   // accessor functions for name
   void setName( string );
   string getName() const;

   // accessor functions for address
   void setAddress( string );
   string getAddress() const;

   // accessor functions for phone
   void setPhone( string );
   string getPhone() const;

   // accessor functions for cart
   void setCart( int * );
   int * getCart();

   void modifyCart( int code, int amount ); // cart[ code ] is modified to amount

   void displayAccountDetails() const; // display email, name, address and phone of Account

   void displayCart() const; // Code, Item and Quantity of each cuisine in the shopping cart
private:
	char email[40]; // used as the account number
	char password[20];
	char name[8];
	char address[80];
	char phone[12];
	int cart[21]; // cart[i] is the quantity of cuisine #i in the shopping cart
}; // end class Account

#endif // ACCOUNT_H