#include<iostream>
using namespace std;
//多态
class Person {
public:
	 virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	 void BuyTicket() { cout << "买票-半价" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();}
int main()
{
	Person ps;
	Student st;

	Func(ps);
	Func(st);
	return 0;
}