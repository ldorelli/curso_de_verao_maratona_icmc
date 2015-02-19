#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen(int n, int m)
{
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		if (m == 0) a = rand(), b = rand();
		else a = rand()%m, b = rand()%m;
		printf("%d %d\n", a, b);
	}
}

int main()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	srand(tv.tv_usec);

	int t = 30;
	while (t--)
	{
		int n = rand()%100+1;
		gen(n, rand()%10+1);
	}
	t = 1;
	while (t--)
	{
		int n = rand()%100000+1;
		gen(n, rand()%1000000);
	}
	gen(100000, 0);
}
