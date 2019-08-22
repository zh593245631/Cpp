#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define MAXI 7
typedef int KeyType;
typedef int ElemType;
struct rec {
	KeyType key;
	ElemType data;
};
typedef rec sqlist[MAXI];
class kuaisu
{
public:
	kuaisu(sqlist a, int m) :n(m)
	{
		for (int i = 0; i < n; i++) b[i] = a[i];
	}
	void quicksort(int s, int t)
	{
		int i;
		if (s < t) {
			i = part(s, t);
			quicksort(s, i - 1);
			quicksort(i + 1, t);
		}
		else return;
	}
	int part(int s, int t)
	{
		int i, j;
		rec p;
		i = s; j = t; p = b[s];
		while (i < j)
		{
			while (i < j && b[j].key >= p.key)j--;
			b[i] = b[j];
			while (i < j && b[i].key <= p.key)i++;
			b[j] = b[i];
		}
		b[i] = p;
		output();
		return i;
	}
	void output()
	{
		for (int i = 0; i < n; i++)
			cout << setw(4) << b[i].key;
		cout << endl;
	}
private:
	sqlist b;
	int n;
};

void main()
{
	cout << "kuaisu1.cpp运行结果:\n";
	sqlist a1;
	int i, n = MAXI, low = 0, high = 6;
	srand(time(0));
	//for (i = 0; i < n; i++)
	//	a1[i].key = rand() % 80;
	a1[0].key = 30;
	a1[1].key = 15;
	a1[2].key = 40;
	a1[3].key = 28;
	a1[4].key = 50;
	a1[5].key = 10;
	a1[6].key = 70;

	kuaisu px(a1, n);
	cout << "数组排序过程演示:\n";
	px.quicksort(low, high);
	cout << "排序后数组:\n";
	px.output();
	cin.get();
}
