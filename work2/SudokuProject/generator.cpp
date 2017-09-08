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
	if (t>81)						//输出方案 
	{
		if (ans++) puts("");			//两个方案之间有空格 
		cnt = 0;				//记录 
		
		rep(i, 1, 10) rep(j, 1, 10)
			put[cnt++] = ways[i][j], ++cnt;	//两个数字之间有空格 

		puts(put);					//输出

		if (ans >= n) flag = true;	//判断是不是已近输出了n个方案
		return;
	}

	int x = (t - 1) / 9 + 1;	//当前搜索到哪个格子 	
	int y = (t - 1) % 9 + 1;
	int p = belong[x][y];	//当前格子属于哪一个九宫格		 
				
	rep(i, 1, 10)			//当前选择可以放的数字 
	{
		if (row[x][i] || col[y][i] || vis[p][i]) continue;	//当前行、列、九宫格中使用过

		row[x][i] = col[y][i] = vis[p][i] = true;		//标记 
		ways[x][y] = i + '0';								//标记 
		dfs(t + 1);										//下一个格子 
		row[x][i] = col[y][i] = vis[p][i] = false;		//去标记 
	}
}
void generator::init()
{
	int x, y, t;
	cnt = 0;

	//预处理9*9的格子中,每个格子属于哪一个九宫格 
	rep(i, 1, 10) rep(j, 1, 10)
	{
		x = (i - 1) / 3;
		y = (j - 1) / 3;
		t = x * 3 + y;		//属于哪一个九宫格 
		belong[i][j] = t;
	}

	//预处理出输出格式 
	rep(i, 1, 10)
	{
		rep(i, 1, 9) put[cnt++] = 'X', put[cnt++] = ' ';	//	一个数字,一个空格 
		put[cnt++] = 'X'; put[cnt++] = '\n';				//行末无空格 
	}
	put[--cnt] = '\0';
}

char s[200];
void generator::solve(int m)
{
	n = m;
	init();
	random_shuffle(ways[1] + 2, ways[1] + 10);	//实现随机全排列,随机的关键 

												//第一行预先设定好,并做好相应的数字标记 
	rep(i, 1, 10) col[i][ways[1][i] - '0'] = row[1][i] = vis[(i - 1) / 3][ways[1][i] - '0'] = true;
	dfs(10);//回溯,暴搜+剪枝
}


generator::~generator()
{
}
