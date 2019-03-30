#include<iostream>
#include<string>
#include<vector>
using namespace std;
//string tel[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//void combinaton(string& digits,int depth,string& comStr,vector<string>& strVec)
//{
//	if (digits.size() == depth)
//	{
//		strVec.push_back(comStr);
//		return;
//	}
//	int mapnum = digits[depth] - '0';
//	string letters = tel[mapnum];
//	
//	for (auto e:letters)
//	combinaton(digits,depth+1,comStr+e,strVec);
//}
//vector<string> letterCombinations(string digits)
//{
//	vector<string> strVec;
//	if (digits.empty())
//	{
//		return strVec;
//	}
//	string comStr;
//	combinaton(digits,0,comStr,strVec);
//
//	return strVec;
//}
//int main()
//{
//	vector<string> tel;
//	tel = letterCombinations("23");
//
//	for (auto& e : tel)
//		cout <<" \""<<e << "\" ";
//	cout << endl;
//	return 0;
//}
int singleNumber(vector<int>& nums) {
	int a = 0, b = 0;
	for (auto x : nums) {
		a = (a ^ x) & ~b;
		b = (b ^ x) & ~a;
	}
	return a;
}
int main()
{
	vector<int> nums = { 3, 3, 3, 2 };
	int a = singleNumber(nums);

	cout << a << endl;

	return 0;
}