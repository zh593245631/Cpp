#include<iostream>
using namespace std;
//��̬
class Person {
public:
	 virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
};
class Student : public Person {
public:
	 void BuyTicket() { cout << "��Ʊ-���" << endl; }
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