#include<iostream>
#include<string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name<<endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//
//
//int main()
//{
//	Person p;
//	p.Print();
//	Student s;
//	s.Print();
//	Teacher t;
//	s.Print();
//	return 0;
//}
// ʵ����ʾ���ּ̳й�ϵ�»����Ա�ĸ����ͳ�Ա���ʹ�ϵ�ı仯
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//public:
//	string _name; // ����
//private:
//	int _age; // ����
//protected:
//	int _id;
//};
//
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//public:
//	void fun1()
//	{
//		_id = 123;
//		//_age = 18; //���ܷ��ʻ���˽��
//	}
//protected:
//	int _stunum; // ѧ��
//};
//
//class Student : protected Person
////class Student : private Person
////class Student : public Person
//{
//public:
//	void fun1()
//	{
//		_id = 123;
//		_name = "yhs";
//		//_age = 18; //���ܷ��ʻ���˽��
//	}
//protected:
//	int _stunum; // ѧ��
//};
//
////class Student : protected Person
//class Student : private Person
////class Student : public Person
//{
//public:
//	void fun1()
//	{
//		_id = 123;
//		_name = "yhs";
//		//_age = 18; //���ܷ��ʻ���˽��
//	}
//protected:
//	int _stunum; // ѧ��
//};
////protected��
//class Person
//{
//protected:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//void test()
//{
//	Student stu;
//	Person* ptr = &stu;
//}
// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//public:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//public:
//	int _num = 999; // ѧ��
//};
//int main()
//{
//	Person p;
//	Student s;
//	cout << p._num << endl;
//	cout << s._num << endl;
//	cout << s.Person::_num << endl;
//	cout << s.Student::_num << endl;
//	return 0;
//}
// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//	//b.fun(); //��������
//};
////a ����   ������ͬһ���������� ��������ͬ ������ͬ
////b �ض��� 
////c ����
////d ��д
////e ����
//
//int main()
//{
//	Test();
//	return 0;
//}
class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}protected:
	string _name; // ����
};
class Student : public Person
{
public:

	Student(const char* name = "����ɽ", int num = 10)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //ѧ��
};
void Test()
{
	//Student s;
	Student s1("jack", 18);
	Student s2(s1);
	Student s3  = s1;
	//Student s1 = s3;
	//s1 = s3;
}int main(){	Test();	return 0;}