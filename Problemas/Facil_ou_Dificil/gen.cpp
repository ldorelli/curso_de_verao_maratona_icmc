#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen1(int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (rand()&1) printf("(");
		else printf(")");
	}
	printf("\n");
}

void gen2(int n)
{
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		if (n-i-1 <= c) printf(")"), --c;
		else if (rand()&1) printf("("), ++c;
		else 
		{
			if (c == 0) printf("("), ++c;
			else printf(")"), --c;
		}
	}
	printf("\n");
}

int main()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	srand(tv.tv_usec);

	int t = 20;
	while (t--)
	{
		int n = rand()%100+1;
		gen1(n);
		gen2(n);
	}
	t = 5;	
	while (t--)
	{
		int n = rand()%10000+1;
		gen1(n);
		gen2(n);
	}
	gen1(10000);
	gen2(10000);
}
