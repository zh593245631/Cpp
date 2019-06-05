//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//long long int Cal(int n, vector<int>& data)
//{
//	sort(data.rbegin(), data.rend());
//	long long int count = 0;
//	for (int i = 1;n>0; i+=2)
//	{
//		count += data[i];
//		--n;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	int num = 0;
//	vector<int> data;
//
//	while (cin >> n)
//	{
//		while (cin >> num)
//		{
//			data.push_back(num);
//		}
//		cout << Cal(n, data) << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	string str;
	string cstr;

	while (cin >> str >> cstr)
	{
		map<char, int> c;
		for (auto& e : cstr) {
			c[e] = 1;
		}
		auto vit = str.begin();
		while (vit != str.end())
		{
			if (c.count(*vit)) {
				vit = str.erase(vit);
			}
			else {
				vit++;
			}
		}
		cout << str << endl;
	}
	return 0;
}