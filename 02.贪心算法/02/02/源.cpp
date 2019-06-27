#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<Windows.h>
using namespace std;
#define INFINITY INT_MAX 
#define MAX_VERTEX_NUM 20 
typedef int VRType;
typedef int InfoType;
typedef char VerTexType;
typedef struct ArcCell
{
	VRType adj;
	InfoType* info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VerTexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
}MGraph;
typedef struct
{
	VerTexType adjvex;
	VRType lowcost;
}closedge[MAX_VERTEX_NUM];

void CreateGraph(MGraph& G);
void MiniSpanTree_PRIM(MGraph G, VerTexType u);
int LocateVex(MGraph G, VerTexType u);
int minimum(closedge close);
void main(void)
{
	int i, j;
	MGraph G;
	CreateGraph(G);
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			cout << G.arcs[i][j].adj;
			cout << " ";
		}
		cout << endl;
	}
	MiniSpanTree_PRIM(G, 'a');
	system("pause");
}
void CreateGraph(MGraph& G)
{
	int weigh;
	int i, j = 0, k = 0;
	char hand, tide;
	cout << "input the number for vexnum and arcnum:";
	cin >> G.vexnum >> G.arcnum;
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = 88;
	}
	cout << endl;
	cout << "input" << G.vexnum << "char for vexs:";
	for (i = 0; i < G.vexnum; i++)
		cin >> G.vexs[i];
	cout << endl;
	cout << "input" << G.arcnum << "arc(char,char,weigh):" << endl;
	j = 0;
	k = 0;
	for (i = 0; i < G.arcnum; i++)
	{
		cout << i << ":";
		cin >> hand;
		cin >> tide;
		cin >> weigh;
		while (hand != G.vexs[j])
			j++;
		while (tide != G.vexs[k])
			k++;
		G.arcs[j][k].adj = weigh;
		G.arcs[k][j].adj = weigh;
		j = 0;
		k = 0;
		cout << endl;
	}
}
void MiniSpanTree_PRIM(MGraph G, VerTexType u)
{
	int i, j, k = 0;
	closedge close;

	k = LocateVex(G, u);
	for (j = 0; j < G.vexnum; j++)
	{
		if (j != k)
		{
			close[j].adjvex = G.vexs[k];
			close[j].lowcost = G.arcs[k][j].adj;
		}
	}
	close[j].lowcost = 88;
	close[j].adjvex = '\0';
	close[k].lowcost = 0;
	close[k].adjvex = u;
	for (i = 1; i < G.vexnum; i++)
	{
		k = minimum(close);
		cout << close[k].adjvex;
		cout << "---->";
		cout << G.vexs[k] << " ";
		cout << close[k].lowcost << endl;
		close[k].lowcost = 0;
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[k][j].adj < close[j].lowcost)
			{
				close[j].adjvex = G.vexs[k];
				close[j].lowcost = G.arcs[k][j].adj;
			}
		}
	}
}
int LocateVex(MGraph G, VerTexType u)
{
	int k = 0;
	while (G.vexs[k++] == u)
		return k - 1;
	return 0;
}
int minimum(closedge close)
{
	int j1 = 0, client = 88, j2 = 0;
	while (close[j1].adjvex != '\0')
	{
		if (client > close[j1].lowcost && close[j1].lowcost != 0)
		{
			client = close[j1].lowcost;
			j2 = j1;
		}
		j1++;
	}
	return j2;
}
