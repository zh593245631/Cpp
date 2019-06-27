#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define MAX_VERTEX_NUM 50
typedef struct ArcNode
{
	int adjvex; //�û���ָ��Ķ����λ��
	int value;  //�ý�����ڽӽ���Ĵ���
	struct ArcNode* nextarc; //ָ����һ������ָ��
}ArcNode, * node;

typedef struct VNode
{
	int data; //������Ϣ
	ArcNode* firstArc; //ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct Graph
{
	AdjList vertices;
	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
}*ALGraph;
int build_adList(ALGraph G, int n, int a)
{ //�����ڽӱ�
	int v, m, i, t, h;
	node p, q;
	if (n < 0) return printf("ERROR");
	G->vexnum = n; //ͼ�Ķ�����
	if (a < 0) return printf("ERROR");
	G->arcnum = a; //ͼ�Ļ���
	for (m = 0; m < n; m++)
	{
		G->vertices[m].data = m;
		G->vertices[m].firstArc = NULL;
	}
	for (m = 1; m <= a; m++)
	{
		i = 1;
		printf("�����%d����:", m);
		scanf("%d%d%d", &t, &h, &v);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = h;
		p->value = v;
		p->nextarc = NULL;
		while (G->vertices[i].data != t) i++; //ת����һ�����
		if (!G->vertices[i].firstArc) //�յ�
			G->vertices[i].firstArc = p;
		else
		{ //����ǰ����к�̽ڵ������
			for (q = G->vertices[i].firstArc; q->nextarc; q = q->nextarc);
			q->nextarc = p; //�¿��ٽ��
		}
	}
	return v;
}
void print_Graph(ALGraph G)
{ //��ӡ�ڽӱ�
	ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
	int i;
	for (i = 1; i < G->vexnum; i++)
	{
		p = G->vertices[i].firstArc;
		printf("[%d]", i);
		while (p)
		{
			printf("->%d,%d", p->adjvex, p->value);//��i�������ڽӽ����Ϣ
			p = p->nextarc;
		}
		printf("\n");
	}
}

void fgraph(ALGraph G, int k, int n)
{ //���ͼALGraph G��nΪ�������kΪͼ�Ķ���
  //�����ǰ��ε�˳��������
	int cost[100];
	int d[100];
	int path[100];
	int j, r, i, min, w, value;
	node p;
	cost[n] = 0;
	for (j = n - 1; j >= 1; j--) //��ǰ������
	{
		p = G->vertices[j].firstArc;
		min = p->value + cost[p->adjvex]; //��ʼ��·����С����
		r = p->adjvex;
		value = p->value;
		while (p != NULL)
		{ //r��һ���������Ľ�㣬Ȩֵc(j,r)+cost[r]ȡ��Сֵ
			if ((p->value + cost[p->adjvex]) < min)
			{
				min = p->value + cost[p->adjvex]; //p->value=c(j,r)
				r = p->adjvex;
				value = p->value;
			}
			p = p->nextarc;
		}
		cost[j] = value + cost[r]; //��ǰ�ڵ�Ĵ���ֵ
		d[j] = r; //���߽׶Σ�����㵽�յ���С����·����ǰ������ı��
	}
	path[1] = 1; path[k] = n;
	for (i = 2; i <= k - 1; i++) //�ҳ���С����·���ϵĽ��
		path[i] = d[path[i - 1]];
	printf("��С�ɱ�Ϊ:%d\n", cost[1]);
	printf("��С�ɱ�·��Ϊ: ");
	for (w = 1; w <= k; w++)
		printf("%d->", path[w]);
}
void main()
{
	ALGraph g;
	int n, a, k;
	g = (ALGraph)malloc(sizeof(ALGraph));
	printf("��������ͼ�ڵ���Ŀ:");
	scanf("%d", &n);
	printf("��������ͼ�ߵ���Ŀ:");
	scanf("%d", &a);
	printf("��������ͼ�Ķ���:");
	scanf("%d", &k);
	printf("������ͼ�Ļ�����Ϣ����ͷ����β��Ȩֵ��\n");
	build_adList(g, n, a);
	printf("���ͼ���ڽӱ�Ϊ:\n");
	print_Graph(g);
	fgraph(g, k, n);
	getchar();
}
