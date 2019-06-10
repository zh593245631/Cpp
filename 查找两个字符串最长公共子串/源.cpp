#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1;
	string str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		int str1L = str1.size();
		int str2L = str2.size();
		if (str1L > str2L)
		{
			swap(str1, str2);
		}

		int maxleft = 0;
		int maxright = 0;
		for (int i = 0; i < str1.size(); ++i)
		{
			int left = i;
			for (int j = 0; j < str2.size(); ++j)
			{
				if (str1[i] == str2[j])
				{
					while (i < str1.size() && str1[i] == str2[j])
					{
						++i;
						++j;
					}
					int right = i;
					i = left;
					if (maxright - maxleft < right - left) {
						maxright = right;
						maxleft = left;
					}
				}
			}
		}
		cout << maxright - maxleft << endl;
		string ans = str1.substr(maxleft, maxright-maxleft);
		cout << ans << endl;
	}

	return 0;
}
//yrtqyfxyrmbasfmkbuudetaahxxgvcpkfhlkfxtjvguizsmwbnwamftshffyzumqfzqvirxgjjuocobvhvgstvrynduavkvntvxgnravjyfjkycguqyrnbnwnoqvhh
//tshffyzumqfzqvirxgjjuocobvhvgstvrynduavkvntvxgnravjyfjkyc
//tshenguhymzjxhkjstiwzgyudtfeddgqlegxesngnlbubkhzfmspalfajiqsvohghxhswjiimnyazfmgqazdewfptldiilrwkhuntvseohykutjecuhg
//xxzjrwyqtgzfgxyitvszmltcsdjweeycqgzsazahpqrvlgvwexcfwkusmuyltvtbjftkvwebmjctwbfcxfimoevbquznojlzkxygruhebhostshenguhymzjxhkjstiwzgyudtfeddgqlegxesngnlbubkhzfmspalfajiqsvohghxhswjiimnyazfmgqazdewfptldiilrwkhuntvseohykutjecuhg
