#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty() || array[0][0]>target)
			return false;
		int i = array.size() - 1;
		int j = 0;
		while (i >= 0 && j<array[0].size())
		{
			if (array[i][j] == target)
				return true;

			if (target>array[i][j])
			{
				j++;
			}
			else{
				i--;
			}
		}
		return false;
	}
};
int main()
{
	
	vector<vector<int>> vv = { { 1, 2, 3 }, {4,5,6}, {7,8,9} };
	Solution s;
	cout << s.Find(10, vv) << endl;
	//cout << vv[0][0] << endl;
	//cout << vv.size() << endl;
	//cout << vv[0].size() << endl;
	////cout << vv[3] << endl;
	return 0;
}