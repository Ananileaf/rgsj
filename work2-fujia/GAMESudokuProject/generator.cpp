#include "generator.h"
using namespace std;
generator::generator()
{
	rep(i, 0, 10) ways[1][i] = i + '0';
	swap(ways[1][1], ways[1][4]);
	mem0(res);
	mem0(put);
	mem0(belong);
	mem0(col); mem0(row); mem0(vis);
	mem0(visc); mem0(visr); mem0(viss);
	mem0(choice);
	mem0(put);
	flag = false;
	ans = tot = n = cnt = 0;
}


void generator::dfs3(int k,int p)
{
	if (flag) return;

	if (k >= 40)
	{
		int q = 0;
		++ans;

		//模拟缓冲区输出
		rep(i, 1, 10)
		{
			rep(j, 1, 10)
			{
				if (res[i][j] == '0')
				{
					if (choice[q]) put[cnt++] = '0';
					else put[cnt++] = ways[i][j];
					++q;
				}
				else put[cnt++] = ways[i][j];
				put[cnt++] = ' ';
			}
			put[cnt - 1] = '\n';
		}

		if (ans >= n)//方案数够了,输出
		{
			put[cnt - 1] = '\0';
			puts(put);
			cnt = 0;
			flag = true;
		}
		else if (cnt > 199000)//缓冲区满了，输出
		{
			puts(put);
			cnt = 0;
		}
		else put[cnt++] = '\n';
		return ;
	}

	choice[k] = true;
	dfs3(k + 1, p);
	choice[k] = false;
	if(p+1<=9) dfs3(k + 1, p+1);//满足至少31个挖空

}

void generator::dfs2(int k)
{
	if (tot>1) return;//方案数大于1,说明不满足唯一性
	if (k>81)
	{
		++tot;
		return;
	}

	int x = (k - 1) / 9 + 1;
	int y = (k - 1) % 9 + 1;
	int p = belong[x][y];

	if (res[x][y] != '0') { dfs2(k + 1); return; }

	rep(i, 1, 10)
	{
		if (visc[y][i] || visr[x][i] || viss[p][i]) continue;
		visc[y][i] = visr[x][i] = viss[p][i] = true;
		res[x][y] = i + '0';
		dfs2(k + 1);
		if (tot > 1) return;
		visc[y][i] = visr[x][i] = viss[p][i] = false;
		res[x][y] = '0';
	}

}

//检查唯一性,看能生成几个数独,只能生成一个则唯一
bool generator::check()
{
	mem0(visc); mem0(visr); mem0(viss);
	tot = 0;
	rep(i, 1, 10) rep(j, 1, 10)
		if (res[i][j] != '0')
		{
			visc[j][res[i][j] - '0'] = visr[i][res[i][j] - '0'] =
			viss[belong[i][j]][res[i][j] - '0'] = true;
		}
	dfs2(1);
	return tot == 1;
}

//随机选择挖空点
void generator::GetPoint()
{
	int x, y;
	while (true)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (res[x][y] == '0') continue;//不能重复选择挖空点
		res[x][y] = '0';
		break;
	}
}
void generator::dfs1(int t)
{
	if (flag) return;
	if (t > 81)//查找方案 
	{
		srand(time(NULL));
		//随机挖40个空,验证唯一性
		while (true)
		{
			rep(i, 1, 10) rep(j, 1, 10) res[i][j] = ways[i][j];
			for (int i = 1; i <= 40; ++i) GetPoint();
			if (check()) break;
		}
		flag = true;
		return;
	}

	//当前搜索到哪个格子 
	int x = (t - 1) / 9 + 1;
	int y = (t - 1) % 9 + 1;
	int p = belong[x][y];
	//当前选择可以放的数字 
	rep(i, 1, 10)
	{
		if (row[x][i] || col[y][i] || vis[p][i]) continue;
		row[x][i] = col[y][i] = vis[p][i] = true;
		ways[x][y] = i + '0';
		dfs1(t + 1);							//下一个格子 
		if (flag) return;
		row[x][i] = col[y][i] = vis[p][i] = false;
	}
}
void generator::init()
{
	int x, y, t;
	cnt = 0;
	rep(i, 1, 10) rep(j, 1, 10)
	{
		x = (i - 1) / 3;
		y = (j - 1) / 3;
		t = x * 3 + y;
		belong[i][j] = t;
	}
}

void generator::solve(int m)
{
	init();
	n = m;
	random_shuffle(ways[1] + 2, ways[1] + 10);	//实现随机全排列,随机的关键 
	rep(i, 1, 10) col[i][ways[1][i] - '0'] = row[1][i] = vis[belong[1][i]][ways[1][i] - '0'] = true;
	dfs1(10);//回溯,暴搜+剪枝 
	flag = false;
	dfs3(0,0);
}

generator::~generator()
{
}
