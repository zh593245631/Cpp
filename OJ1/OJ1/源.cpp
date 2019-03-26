#include <iostream>
using namespace std;

class Solution
{
public:
	Solution()
	{
		++N;
		Sum += N;
	}

	static void Reset()
	{
		N = 0;
		Sum = 0;
	}

	static int GetSum()
	{
		return Sum;
	}
	int Sum_Solution(int n)
	{
		Reset();

		Solution *a = new Solution[n];
		delete[]a;
		a = 0;

		return GetSum();
	}
private:
	static int N;
	static int Sum;
};

int Solution::N = 0;
int Solution::Sum = 0;

int main()
{
	Solution p;
	int n;
	while (cin >> n)
	{
		cout << p.Sum_Solution(n) << endl;
	}
	cin >> n;
	return 0;

}