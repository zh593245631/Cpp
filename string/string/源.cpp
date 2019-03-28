#include<iostream>
#include<string>
#include<vector>
using namespace std;
//string类对象的常见构造
void TestString1()
{
	string s1;
	string s2("hello bit");
	string s3(10, 'a');
	string s4(s2);
	string s5(s3, 5);
}
//string类对象的容量操作
void TestString2()
{
	 string s1("hello bit");
	 cout << s1.size() << endl;
	 cout << s1.length() << endl;
	 cout << s1.capacity() << endl;
	 cout << s1.empty() << endl;
	 
	 s1.clear();
	 cout << s1.capacity() << endl;
	 cout << s1.size() << endl;
	 cout << s1 << endl;
	 
	 s1.resize(3);
	 cout << s1 << endl;
	 cout << s1.capacity() << endl;
	 cout << s1.size() << endl;
	 
	 s1.resize(8, 'c');
	 cout << s1 << endl;
	 cout << s1.capacity() << endl;
	 cout << s1.size() << endl;
	 
	 s1.reserve(10);
	 cout << s1 << endl;
	 cout << s1.capacity() << endl;
	 cout << s1.size() << endl;

	 s1.reserve(20);
	 cout << s1 << endl;
	 cout << s1.capacity() << endl;
	 cout << s1.size() << endl;



}
//string类对象的访问操作
void TestString3()
{
	string s1("hello world");
	const string s2("Hello World");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;

	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << endl;
	}
}
//string类对象的修改操作
void TestString4()
{
	string s1;
	s1.push_back(' ');
	s1.append("hello ");
	s1 += 'w';
	s1 += "orld";
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	string file1("string.cpp");
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;

	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;


}
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 1000; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << sz << endl;
		}
	}
}
void TestPushBack2()
{
	string s;
	s.reserve(1000);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 1000; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << sz << endl;
		}
	}
}
//string类非成员函数
//******************************
//OJ反转字符串
class Solution{
public:
	string reverseString(string s){
		if (s.empty())
			return s;
		size_t left = 0;
		size_t right = s.size() - 1;

		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		return s;
	}
};
class Solution2 {
public:
	void reverseString(vector<char> s) {
		if (s.empty())
			return;
		size_t left = 0;
		size_t right = s.size()-1;

		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
};
int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestPushBack();
	//TestPushBack2();
	//string str("aabbcc");
	//Solution s;
	//cout << str << endl;
	//str = s.reverseString(str);
	//cout << str << endl;
	return 0;
}