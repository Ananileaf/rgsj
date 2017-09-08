#pragma once
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define mem(x, y) memset(x, y, sizeof(x));
#define mem0(x) mem(x,0)
#define rep(i,a,b) for(int i=a;i<(b);++i)
class generator
{
public:
	int n;					//输入 
	int ans;				//搜索到的方案数 
	int belong[10][10]; 	//每一个格子属于哪一个九宫格 
	char ways[10][10];	//搜索的方案 
	bool vis[10][10];		//每个九宫格中的数字标记 
	bool col[10][10];		//每一列中的数字标记 
	bool row[10][10];		//每一行的数字标记 
	bool flag;				//搜索的剪枝,当查询到的方案数大于等于输入的方案数时生效 
	char put[200];			//输出 
	int cnt;				//输出时需要使用到的变量
	generator();
	generator(int _n);		
	void dfs(int t);		//回溯
	void solve(int m);		//计算
	void init();			//初始化
	~generator();
};

