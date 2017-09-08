#include "generator.h"
using namespace std;

generator::generator():n(0),flag(0),ans(0)
{
	rep(i, 0, 10) ways[1][i] = i + '0';
	swap(ways[1][1], ways[1][4]);
	mem0(vis);
	mem0(col);
	mem0(row);
	mem0(belong);
	mem0(put);
}
generator::generator(int _n):n(_n),flag(0),ans(0)
{
	rep(i, 0, 10) ways[1][i] = i + '0';
	swap(ways[1][1], ways[1][4]);
	mem0(vis);
	mem0(col);
	mem0(row);
	mem0(belong);
	mem0(put);
}
void generator::dfs(int t)
{
	if (flag) return;
	if (t>81)						//������� 
	{
		if (ans++) puts("");			//��������֮���пո� 
		cnt = 0;				//��¼ 
		
		rep(i, 1, 10) rep(j, 1, 10)
			put[cnt++] = ways[i][j], ++cnt;	//��������֮���пո� 

		puts(put);					//���

		if (ans >= n) flag = true;	//�ж��ǲ����ѽ������n������
		return;
	}

	int x = (t - 1) / 9 + 1;	//��ǰ�������ĸ����� 	
	int y = (t - 1) % 9 + 1;
	int p = belong[x][y];	//��ǰ����������һ���Ź���		 
				
	rep(i, 1, 10)			//��ǰѡ����Էŵ����� 
	{
		if (row[x][i] || col[y][i] || vis[p][i]) continue;	//��ǰ�С��С��Ź�����ʹ�ù�

		row[x][i] = col[y][i] = vis[p][i] = true;		//��� 
		ways[x][y] = i + '0';								//��� 
		dfs(t + 1);										//��һ������ 
		row[x][i] = col[y][i] = vis[p][i] = false;		//ȥ��� 
	}
}
void generator::init()
{
	int x, y, t;
	cnt = 0;

	//Ԥ����9*9�ĸ�����,ÿ������������һ���Ź��� 
	rep(i, 1, 10) rep(j, 1, 10)
	{
		x = (i - 1) / 3;
		y = (j - 1) / 3;
		t = x * 3 + y;		//������һ���Ź��� 
		belong[i][j] = t;
	}

	//Ԥ����������ʽ 
	rep(i, 1, 10)
	{
		rep(i, 1, 9) put[cnt++] = 'X', put[cnt++] = ' ';	//	һ������,һ���ո� 
		put[cnt++] = 'X'; put[cnt++] = '\n';				//��ĩ�޿ո� 
	}
	put[--cnt] = '\0';
}

char s[200];
void generator::solve(int m)
{
	n = m;
	init();
	random_shuffle(ways[1] + 2, ways[1] + 10);	//ʵ�����ȫ����,����Ĺؼ� 

												//��һ��Ԥ���趨��,��������Ӧ�����ֱ�� 
	rep(i, 1, 10) col[i][ways[1][i] - '0'] = row[1][i] = vis[(i - 1) / 3][ways[1][i] - '0'] = true;
	dfs(10);//����,����+��֦
}


generator::~generator()
{
}
