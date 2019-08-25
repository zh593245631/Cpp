#include<iostream>
using namespace std;

int f(int x)
{
	if (x <= 1)
		return 0;
	if (x == 2)
		return 1;
	return (x - 1) * (f(x - 1) + f(x - 2));
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 1)
			cout << 1 << endl;
		else
		cout << n * f(n - 1) << endl;
	}
	return 0;
}
