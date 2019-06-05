//#include<iostream>
//#include<queue>
//using namespace std;
//
//class LCA {
//public:
//	int getLCA(int a, int b) {
//		// write code here
//
//		queue<int> qa;
//		queue<int> qb;
//
//		while (a != 0)
//		{
//			qa.push(a);
//			a = a / 2;
//		}
//		while (b != 0)
//		{
//			qb.push(b);
//			b = b / 2;
//		}
//
//		while (qa.size() != qb.size())
//		{
//			if (qa.size() > qb.size())
//			{
//				qa.pop();
//			}
//			else {
//				qb.pop();
//			}
//		}
//		while (!qa.empty())
//		{
//			if (qa.front() == qb.front())
//			{
//				break;
//			}
//			else {
//				qa.pop();
//				qb.pop();
//			}
//		}
//		return qa.front();
//	}
//};
//
//int main()
//{
//	LCA a;
//	a.getLCA(2, 1);
//	return 0;
//}

#include<iostream>

using namespace std;

int main()
{
	int num;

	while (cin >> num)
	{
		int max = 0;
		int ret = 1;
		int count = 1;
		int prev = 0;
		int tmp = num;
		while (num >= ret)
		{
			tmp = num & ret;
			ret = ret << 1;
			if (tmp&&prev)
				++count;
			else {
				count = 1;
			}
			if (max < count)
				max = count;
			prev = tmp;
		}
		cout << max << endl;
	}
	return 0;
}