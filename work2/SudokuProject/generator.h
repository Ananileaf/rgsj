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
	int n;					//���� 
	int ans;				//�������ķ����� 
	int belong[10][10]; 	//ÿһ������������һ���Ź��� 
	char ways[10][10];	//�����ķ��� 
	bool vis[10][10];		//ÿ���Ź����е����ֱ�� 
	bool col[10][10];		//ÿһ���е����ֱ�� 
	bool row[10][10];		//ÿһ�е����ֱ�� 
	bool flag;				//�����ļ�֦,����ѯ���ķ��������ڵ�������ķ�����ʱ��Ч 
	char put[200];			//��� 
	int cnt;				//���ʱ��Ҫʹ�õ��ı���
	generator();
	generator(int _n);		
	void dfs(int t);		//����
	void solve(int m);		//����
	void init();			//��ʼ��
	~generator();
};

