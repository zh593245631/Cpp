#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.empty())cout << 0 << endl;
		vector<int> ans;
		//cout << str.rfind(str[0]) << endl;
		int max = 0;
		int prev = 0;
		int cur = 0;
		while (cur < str.size())
		{
			int tmp = str.rfind(str[cur]);
			if (tmp - prev + 1 > max) {
				max = tmp - prev + 1;
			}
			++cur;
			if (cur - prev + 1 == max || tmp - prev == 0) {
				ans.push_back(max);
				if (tmp - prev == 0)
					prev = cur;
				else
				prev = cur + 1;
				max = 0;
			}
		}
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i];
			if (i == ans.size() - 1)
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}