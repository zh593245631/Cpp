#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
/*���ɲ����Է���һ���µĻʺ�*/
bool place(int k, int* X)
{
	int i;
	i = 1;
	while (i < k)
	{
		if ((X[i] == X[k]) || (abs(X[i] - X[k]) == abs(i - k))) //�����ʺ���ͬ��/��/�Խ���
			return false;
		i++;
	}
	return true;
}
void Nqueens(int n, int* X)
{//k��ʾ��������ǵ�k�еĻʺ�X[k]��ʾ��k�лʺ����λ��
	int k;
	X[1] = 0;
	k = 1;
	while (k > 0)
	{
		X[k] = X[k] + 1; //�ӵ�ǰ�м�1��λ�ÿ�ʼ����
		while ((X[k] <= n) && (!place(k, X))) //��ǰ��λ���Ƿ���������
			X[k] = X[k] + 1; //����������,����������һ��λ��
		if (X[k] <= n) //����������������
		{
			if (k == n) //�����һ���ʺ�,�������
			{
				for (int i = 1; i <= n; i++) //������лʺ����λ��
					printf("%d ", X[i]);
				printf("\n");
			}
			else
			{
				k = k + 1; //�������һ��,������һ���ʺ�
				X[k] = 0; //��һ�еĻʺ�������λ����0
			}
		}
		else
		{//���ж���n�У���δ����������
			X[k] = 0; //��ǰ�и�λΪ0
			k = k - 1; //���ݵ�ǰһ��
		}
	}
}
void main()
{
	int n, i = 1;
	int* X;
	printf("|--------------THE N QUEENS PROBLEM--------------|\n");
	printf("|------         edited by Jill Chih        ------|\n");
	printf("|------------------------------------------------|\n\n");
	while (i)
	{
		printf("Please input the sum of Queens:\n");
		scanf("%d", &n);
		X = new int[n];
		printf("The solutions are:\n");
		Nqueens(n, X);
		printf("Press <1> to run again\n");
		printf("Press <0> to exit\n");
		scanf("%d", &i);
	}
}
