#include<iostream>
#include<string>
#include<vector>
using namespace std;

//double Division(int a, int b)
//{
//	string s = "Division by zero condition!";
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw s;
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const string errmsg){
//		cout << errmsg << endl;
//	}
//	catch (...) {
//		cout << "unkown exception" << endl;
//	}//
//	return 0;


int main()
{
	try
	{
		vector<int> v;
		//v.reserve(1000000000000000000);
		v.at(100);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "don't no" << endl;
	}

	return 0;
}