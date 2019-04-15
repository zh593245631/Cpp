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
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
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
// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//public:
//	string _name; // 姓名
//private:
//	int _age; // 年龄
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
//		//_age = 18; //不能访问基类私有
//	}
//protected:
//	int _stunum; // 学号
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
//		//_age = 18; //不能访问基类私有
//	}
//protected:
//	int _stunum; // 学号
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
//		//_age = 18; //不能访问基类私有
//	}
//protected:
//	int _stunum; // 学号
//};
////protected：
//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void test()
//{
//	Student stu;
//	Person* ptr = &stu;
//}
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//public:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//public:
//	int _num = 999; // 学号
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
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
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
//	//b.fun(); //被隐藏了
//};
////a 重载   函数在同一个作用域中 函数名相同 参数不同
////b 重定义 
////c 覆盖
////d 重写
////e 隐藏
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
	string _name; // 姓名
};
class Student : public Person
{
public:

	Student(const char* name = "尹虎山", int num = 10)
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
	int _num; //学号
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