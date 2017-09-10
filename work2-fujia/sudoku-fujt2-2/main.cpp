#include<cstdio>
#include "generator.h"
#define setI(x) freopen(x".txt","r",stdin);
#define setO(x) freopen(x".txt","w",stdout);


//处理是否有错误信息以及返回n
int check(int argc, char *argv[])
{
	if (argc != 3) return -1;					//参数个数不对 
	if (strcmp(argv[1], "-c") != 0) return -1;	//参数不是 -c 形式 
	int len = strlen(argv[2]);
	int m = 0;

	//处理输入n 
	rep(i, 0, len)
	{
		if (argv[2][i]<'0' || argv[2][i]>'9') return -1;	//n中含有非数字信息 
		m = m * 10 + (argv[2][i] - '0');
	}
	return m;
}

/*
int main()
{
	int n = 1000000;
	setO("sudoku");
	//scanf("%d", &n);
	generator g;
	g.solve(n);
	return 0;
}
*/


int main(int argc, char *argv[])
{
	setO("sudoku");
	int m = check(argc, argv);
	if (m == -1)			//输入错误 
	{
		puts("Error!");
		return 0;
	}
	else if (m == 0)
	{
		puts("");
		return 0;
	}
	generator g;
	g.solve(m);
	return 0;
}
