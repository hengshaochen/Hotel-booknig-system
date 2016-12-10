// Registration.cpp
// Member-function definitions for class Registration.
#include <iostream>
using namespace std;
#include "Registration.h"

// constructor initializes data members
Registration::Registration( AccountDatabase &accountDatabase )
	:accountDatabase( accountDatabase )
{
}

// start the Registration
void Registration::run()
{
	string cinBuffer ;
	cout << endl << "Enter your e-mail address (account number) (0 to end): ";
	cin  >> cinBuffer;
	while ( accountDatabase.getAccount( cinBuffer ) != NULL ) 
	{
		cout << endl << "An account already exists with the e-mail!"  << endl;
	
		cout << endl << "Enter your e-mail address (account number) (0 to end): ";
		cin >> cinBuffer;

		if (  cinBuffer == "0" ) 
			return ;
	}

	newAccount.setEmail( cinBuffer );

	cout << endl << endl << "Enter your password�]8��20�Ӧr���^��r���μƦr�^: " ;
	cin  >> cinBuffer;
	while ( cinBuffer.size() < 8 || cinBuffer.size() > 20 ) 
	{
		cout << endl << endl << "Enter your password�]**���~:�K�X�Ӫ��Τӵu / 8��20�Ӧr���^��r���μƦr�^: " ;
		cin  >> cinBuffer ;
	}
	newAccount.setPassword( cinBuffer );

	cout << endl << endl << "Enter your name: " ;
	cin >> cinBuffer ;
	newAccount.setName( cinBuffer );

	cout << endl << endl << "Enter your physical address:" ;
	cin  >> cinBuffer ;
	newAccount.setAddress( cinBuffer );

	cout << endl << endl << "Enter your phone number: " ;
	cin  >> cinBuffer ;
	newAccount.setPhone( cinBuffer );

	cout << endl << endl << "Registration Successfully!" << endl << endl ;

	accountDatabase.pushBack( newAccount );  // �N�s�W�o���b���[�J�۸�Ʈw
}
