#include<iostream>
#include<string>
#include<vector>
using namespace std;
//char* _strstr(const char* _str, const char* str)
//{
//
//	while (_str)
//	{
//		char* _str1 = (char*)_str;
//		char* str1 = (char*)str;
//		while (str1&&_str1&&(*_str1) == (*str1))
//		{
//			_str1++;
//			str1++;
//		}
//
//		if (*str1 == '\0')return (char*)_str;
//		_str++;
//
//	}
//
//	return NULL;
//}
//string& operator+(const string& s1, const string& s2)
//{
//	string s3(s1);
//	s3 += s2;
//	return s3;
//}
//
//string& operator+(const string& s1, const char* s2)
//{
//	string s3(s1);
//	s3 += s2;
//	return s3;
//}
//
//string& operator+(const char* s1,const string& s2)
//{
//	string s3(s1);
//	s3 += s2;
//	return s3;
//}
//
//int main()
//{
//	char* a = "abcde";
//	char* b = "bcdf";
//
//	cout << _strstr(a, b) - a << endl;
//
//	getchar();
//	return 0;
//}

int main()
{
	//vector<char> v;
	//vector<char> v2(10, 'a');

	//string s("123");

	//vector<char>  v3(v.begin, v.end);

	vector<int> v4;

	v4.push_back(1);
	v4.push_back(2);
	v4.push_back(3);
	v4.push_back(4);

	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	auto vit = v4.begin();
	while (vit != v4.end())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;

	auto vitr = v4.end();
	while (vitr != v4.begin())
	{
		vitr--;
		cout << *vitr << " ";
	}
	cout << endl;

	getchar();
	return 0;
}