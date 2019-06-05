#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int cur = nums[0];
		vector<int> result;
		for (size_t i = 1; i< nums.size(); i++)
		{
			cur ^= nums[i];
		}

		size_t count = 0;
		while (cur)
		{
			if (cur & 1)break;
			cur = cur >> 1;
			count++;
		}

		vector<int> v1;
		vector<int> v2;
		for (size_t i = 0; i< nums.size(); i++)// 1 2 1 3 2 5
		{
			if ((nums[i] >> count)&1)
				v1.push_back(nums[i]);
			else
				v2.push_back(nums[i]);
		}

		for (size_t i = 1; i< v1.size(); i++)
		{
			v1[0] ^= v1[i];
		}
		for (size_t i = 1; i< v2.size(); i++)
		{
			v2[0] ^= v2[i];
		}
		result.push_back(v1[0]);
		result.push_back(v2[0]);
		return result;

	}
};
class Solution2 {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int cur = nums[0];
		vector<int> result;
		for (size_t i = 1; i< nums.size(); i++)
		{
			cur ^= nums[i];
		}
		int mark = 1;
		while (cur)
		{
			if (cur & 1)break;
			cur = cur >> 1;
			mark = mark << 1;
		}

		vector<int> v1;
		vector<int> v2;
		for (size_t i = 0; i< nums.size(); i++)// 1 2 1 3 2 5
		{
			if ((nums[i]) & mark)
				v1.push_back(nums[i]);
			else
				v2.push_back(nums[i]);
		}

		for (size_t i = 1; i< v1.size(); i++)
		{
			v1[0] ^= v1[i];
		}
		for (size_t i = 1; i< v2.size(); i++)
		{
			v2[0] ^= v2[i];
		}
		result.push_back(v1[0]);
		result.push_back(v2[0]);
		return result;

	}
};
class Solution3 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		size_t n = numbers.size();
		size_t m = n / 2;
		vector<int> hash;
		hash.resize(n, 0);
		for (size_t i = 0; i<n; i++)
		{
			hash[numbers[i]]++;
			if (hash[numbers[i]]> m)
				return numbers[i];
		}

		return 0;
	}
};
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);

	Solution s2;
	vector<int> result;
	result = s2.singleNumber(v);

	return 0;
}