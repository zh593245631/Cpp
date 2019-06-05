#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

//¼ÆËãÔ¼Êý
void divsornum(int n, vector<int>& v)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0) {
			v.push_back(i);
			if (n / i != i)
				v.push_back(n / i);
		}
	}
}
int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<int> map(M + 1, 0);
		map[N] = 1;
		for (int i = N; i < M; ++i)
		{
			if (map[i] == 0)continue;
			vector<int> v;
			divsornum(i, v);
			for (int j = 0; j < v.size(); ++j)
			{
				if (v[j] + i <= M && map[v[j] + i] != 0)
					map[v[j] + i] = min(map[v[j] + i], map[i] + 1);
				else if (v[j] + i <= M)
					map[v[j] + i] = map[i] + 1;
			}
		}
		if (map[M] == 0)
			cout << -1 << endl;
		else
			cout << map[M] - 1 << endl;
	}
	return 0;
}