#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
string  a[15] = { "3","4","5","6","7","8","9","1","J","Q","K","A","2","joker","JOKER" };
int main()
{
	string A;
	while (getline(cin, A)) {

		int start = 0;
		int last = 0;
		last = A.find('-', start);
		string str1 = A.substr(start, last - start);
		start = last + 1;
		last = A.find('-', start);
		string str2 = A.substr(start, last - start);
		map<string, int> _map;
		for (int i = 0; i < 15; ++i)
		{
			_map[a[i]] = i;
		}
		string str111(str1);
		string str222(str2);
		auto vit = str111.begin();
		while (vit != str111.end())
		{
			if (*vit == '0') {
				vit = str111.erase(vit);
			}
			else {
				++vit;
			}
		}
		 vit = str222.begin();
		while (vit != str222.end())
		{
			if (*vit == '0') {
				vit = str222.erase(vit);
			}
			else {
				++vit;
			}
		}
		//cout << str1 << endl;
		string w("joker JOKER");
		if (w == str1)
			cout << str1 << endl;
		else if (w == str2)
			cout << str2 << endl;
		else if (str111.size() != str222.size()) {
			if (str111.size() == 7)
				cout << str1 << endl;
			else if (str222.size() == 7)
				cout << str2 << endl;
			else {
				cout << "ERROR" << endl;
			}
		}
		else if (str111.size() <= 9) {
			string str11;
			str11 += str111[0];
			string str22;
			str22 += str222[0];
			if (_map[str11] > _map[str22])
				cout << str1 << endl;
			else
				cout << str2 << endl;
		}
	}
	return 0;
}