// Order.h
// Order class definition.
#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;


const char cuisine_D[21][16] = { "���F�j�]", "�۳¤j�]", "���d�j�]", "�A�פj�]", "��פj�]", "��ۣ���]",
                               "��׻]��", "���׻]��", "�A���]��", "��ۣ����", "�����N��", "�pŢ�]",
                               "�A�׺�l", "���F��l", "��{��l", "�������", "���ؤ��״�", "�K�_��",
                               "�����P�|", "�d�h�o�|", "����p" };

const int price[21] = { 175, 175, 200, 200, 200, 225,
                        144, 168, 168, 176, 384, 190,
                        375, 350, 725, 380, 380, 350,
                        420, 420, 228 };

class Order
{
public:
   Order( string = "", string = "" ); // constructor initializes data members
   void setOrderNumber( string theOrderNumber );
   string getOrderNumber() const;
   void setEmail( string theEmail );
   string getEmail() const;
   void setOrderDetails( int theOrderDetails[] );
   void displayOrderDetails() const;
private:
	char orderNumber[12];
	char email[40];
	int quantity[21]; // quantity[i] is the quantity of cuisine #i in the order
}; // end class Order

#endif // ORDER_H