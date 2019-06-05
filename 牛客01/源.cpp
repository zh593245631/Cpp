//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//
//	int ans = 0;
//	int cur = 0;
//	if (!v.empty())
//		ans = v[0];
//
//	for (int i = 0; i < n; ++i)
//	{
//		cur += v[i];
//
//		if (cur > ans)
//			ans = cur;
//		if (cur < 0)
//			cur = 0;
//	}
//	cout << ans << endl;
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
bool IFhw(string& s)
{
	string tmp(s);
	reverse(tmp.begin(), tmp.end());
	return tmp == s;
}
int main()
{
	string a;
	string b;

	getline(cin, a);
	getline(cin, b);
	int count = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		string tmp(a);
		tmp.insert(i, b);
		if (IFhw(tmp))++count;
	}
	string rtmp(b);
	rtmp.insert(0, a);
	if (IFhw(rtmp))++count;

	cout << count << endl;
	return 0;
}
//	int ret = 0;
//	for (int i = 0; i < a.size() - 1; ++i)
//	{
//		if (a[i] != a[i + 1]) {
//			ret = 1;
//			break;
//		}
//	}
//	//1.两个都是回文数
//	if (IFhw(a)) {
//		if (IFhw(b)) {
//			if (a.find(b)!=-1||b.find(a) != -1){
//				if (ret == 0) 
//					cout << a.size() + 1 << endl;
//				else {
//					int size = a.size()/2;
//					int count = 1;
//					cout << 2 + ((a.size() % 2) ^ 1) << endl;
//					
//				}
//			}
//			else if(a.size()%2){
//				cout << 0 << endl;
//			}
//			else {
//				cout << 1 << endl;
//			}
//		}
//		else {
//			cout << 0 << endl;
//		}
//	}
//	//3.两个都不是
//	else {
//		string tmp1;
//		string tmp2;
//		tmp1 = a + b;
//		tmp2 = b + a;
//		int count = 0;
//		if (a.find(b) == -1)
//		{
//			if (IFhw(tmp1)) {
//				++count;
//			}
//			if (IFhw(tmp2)) {
//				++count;
//			}
//		}
//		else {
//			for (int i = 0; i < a.size(); ++i)
//			{
//				string tmp(a);
//				tmp.insert(i, b);
//				if (IFhw(tmp))++count;
//			}
//			string rtmp(b);
//			rtmp.insert(0, a);
//			if (IFhw(rtmp))++count;
//		}
//		cout << count << endl;
//	}
//
//	//cout << a.find(b) << endl;
//	return 0;
//}