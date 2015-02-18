#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen(int n, int m)
{
	printf("%d %d\n", n, m);
	int u = rand()%10+1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 && j == 0) printf(".");
			else
			{
				int r = rand()%u;
				if (r == 0) printf("o");
				else printf(".");
			}
		}
		printf("\n");
	}
}

int main()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	srand(tv.tv_usec);

	int t = 50;
	while (t--)
	{
		int n = rand()%100+1;
		int m = rand()%100+1;
		gen(n, m);
	}
	t = 5;
	while (t--)
	{
		int n = rand()%1000+1;
		int m = rand()%1000+1;
		gen(n, m);
	}
	gen(1000, 1000);
}
