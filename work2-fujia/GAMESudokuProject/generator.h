#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define mem(x, y) memset(x, y, sizeof(x));
#define mem0(x) mem(x,0)
#define rep(i,a,b) for(int i=a;i<(b);++i)

class generator
{
public:
	char ways[10][10] = { { 0 },{ '0','4','1','2','3','5','6','7','8','9' } };
	char res[10][10];
	bool flag;
	bool choice[50];
	bool col[10][10], row[10][10], vis[10][10];
	bool visc[10][10], visr[10][10], viss[10][10];
	int ans, tot, n, cnt;
	int belong[10][10];
	char put[200000];
	generator();
	void init();
	void dfs1(int t);
	void dfs2(int k);
	void dfs3(int k,int t);
	void GetPoint();
	void solve(int m);
	bool check();
	~generator();
};

