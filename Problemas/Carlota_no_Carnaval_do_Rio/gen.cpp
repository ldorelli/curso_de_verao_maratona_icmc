#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen(int n, int m)
{
	printf("%d %d\n", n, m);
	while (m--)
	{
		int a, b, c = 10;
		while (c)
		{
			a = rand()%n+1;
			b = rand()%n+1;
			if (a == 1 && b == n) --c;
			else if (a == n && b == n) --c;
			else break;
		}
		printf("%d %d\n", a, b);
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
		int n = rand()%100+2;
		int m = rand()%1000+1;
		gen(n, m);
	}
	t = 5;
	while (t--)
	{
		int n = rand()%999+2;
		int m = rand()%100000+1;
		gen(n, m);
	}
	gen(1000, 100000);
}
