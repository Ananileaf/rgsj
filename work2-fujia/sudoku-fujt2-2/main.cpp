#include<cstdio>
#include "generator.h"
#define setI(x) freopen(x".txt","r",stdin);
#define setO(x) freopen(x".txt","w",stdout);


//�����Ƿ��д�����Ϣ�Լ�����n
int check(int argc, char *argv[])
{
	if (argc != 3) return -1;					//������������ 
	if (strcmp(argv[1], "-c") != 0) return -1;	//�������� -c ��ʽ 
	int len = strlen(argv[2]);
	int m = 0;

	//��������n 
	rep(i, 0, len)
	{
		if (argv[2][i]<'0' || argv[2][i]>'9') return -1;	//n�к��з�������Ϣ 
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
	if (m == -1)			//������� 
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
