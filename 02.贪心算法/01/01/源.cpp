#include <iostream>
using namespace std;
struct goodinfo
{
	float p; //��ƷЧ��
	float w; //��Ʒ����
	float X; //��Ʒ�÷ŵ�����
	int flag; //��Ʒ���
};//��Ʒ��Ϣ�ṹ��
void Insertionsort(goodinfo goods[], int n)
{
	int j, i;
	for (j = 2; j <= n; j++)
	{
		goods[0] = goods[j];
		i = j - 1;
		while (goods[0].p > goods[i].p)
		{
			goods[i + 1] = goods[i];
			i--;
		}
		goods[i + 1] = goods[0];
	}
}//����ƷЧ�棬������ֵ����������
void bag(goodinfo goods[], float M, int n)
{
	float cu;
	int i, j;
	for (i = 1; i <= n; i++)
		goods[i].X = 0;
	cu = M;  //����ʣ������
	for (i = 1; i < n; i++)
	{
		if (goods[i].w > cu)//������Ʒ��������ʣ����������
			break;
		goods[i].X = 1;
		cu = cu - goods[i].w;//ȷ�������µ�ʣ������
	}
	if (i <= n)
		goods[i].X = cu / goods[i].w;//����Ʒ��Ҫ�ŵ���
	for (j = 2; j <= n; j++)
	{
		goods[0] = goods[j];
		i = j - 1;
		while (goods[0].flag < goods[i].flag)
		{
			goods[i + 1] = goods[i];
			i--;
		}
		goods[i + 1] = goods[0];
	}
	cout << "���Ž�Ϊ:" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "��" << i << "����ƷҪ��:";
		cout << goods[i].X << endl;
	}
}
void main()
{
	cout << "|--------����̰�ķ��ⱳ������---------|" << endl;
	cout << "|-------------------------------------|" << endl;
	int j = 1;
	int n = 0;
	float M = 0.0;
	goodinfo* goods;//����һ��ָ��
	while (j)
	{
		cout << "��������Ʒ����������";
		cin >> n;
		goods = new struct goodinfo[n + 1];//
		cout << "�����뱳�������������";
		cin >> M;
		cout << endl;
		int i;
		for (i = 1; i <= n; i++)
		{
			goods[i].flag = i;
			cout << "�������" << i << "����Ʒ������:";
			cin >> goods[i].w;
			cout << "�������" << i << "����Ʒ��Ч��:";
			cin >> goods[i].p;
			goods[i].p = goods[i].p / goods[i].w;//�ó���Ʒ��Ч�棬������
			cout << endl;
		}
		Insertionsort(goods, n);
		bag(goods, M, n);
		cout << "press <1> to run agian" << endl;
		cout << "press <0> to exit" << endl;
		cin >> j;
	}
}
