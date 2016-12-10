//----------------------------------------------//
// s1003352_hw10 程式設計(二) 陳恒劭            　 //
// 鼎泰豐訂餐     2013/06/08                    　//
// ---------------------------------------------//
#include <iostream>
#include <ctime>
#include "Registration.h" // Registration class definition
#include "MakingOrder.h" // Order class definition
#include "OrderHistory.h" // Member class definition

int enterChoice(); // 
void signIn( AccountDatabase &accountDatabase );
int enterChoice2();

int main()
{
	srand( static_cast< unsigned int >( time( 0 ) ) );

   cout << "Welcome to DintaiFung Shopping Mall!\n";

   AccountDatabase accountDatabase;

   Registration registration( accountDatabase );

   int choice;

   while ( ( choice = enterChoice() ) != 3 ) 
   {
      switch ( choice ) 
      {
         case 1:
				signIn( accountDatabase );
            break;
         case 2:
				registration.run();
            break;
         default:
            cerr << "\nIncorrect choice" << endl;
            break;
      }
   }

   cout << endl;
   system("pause");
}

int enterChoice()
{
   cout << "\nEnter your choice\n"
        << "1. Sign in\n"
        << "2. Registration\n"
        << "3. End\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}

void signIn( AccountDatabase &accountDatabase )
{
	char email[40];
	char password[20];

	while( true )
	{
		cout << "\nEnter your e-mail address (0 to end): ";
		cin >> email;

		if( strcmp( email, "0" ) == 0 )
			return;

      if( accountDatabase.getAccount( email ) == NULL )
      {
         cout << "\nNo account exists with the e-mail!\n";
         continue;
      }

      cout << "\nEnter your password (8～20 English letters or digits): ";
		cin >> password;
   
      // check whether authentication succeeded
	  // 從資料表中找是否有和使用者輸入的EMAIL 和 PASSWORD 都相符 , 相符 跳出此迴圈
      if ( accountDatabase.authenticateUser( email, password ) )
         break;

      cout << "Invalid e-mail address or password. Please try again." << endl;
	}

   OrderDatabase orderDatabase;


   MakingOrder makingOrder( accountDatabase, orderDatabase );

   OrderHistory orderHistory( accountDatabase, orderDatabase );

   int choice;

   while ( ( choice = enterChoice2() ) != 3 ) 
   {
      switch ( choice ) 
      {
         case 1:
			makingOrder.run( email );
            break;
         case 2:
            orderHistory.run( email );
            break;
         default: // display error if user does not select valid choice
            cerr << "\nIncorrect choice" << endl;
            break;
      } // end switch
   } // end while
 }

int enterChoice2()
{
   cout << "\nEnter your choice\n"
		  << "1. Making order\n"
        << "2. Order history\n"
		  << "3. Back to top\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}