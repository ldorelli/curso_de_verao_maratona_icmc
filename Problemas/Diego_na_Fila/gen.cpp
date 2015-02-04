#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen(int n, int d)
{
	printf("%d %d\n", n, d);
	for (int i = 0; i < n; ++i)
	{
		if (i) printf(" ");
		printf("%d", rand()%100+1);
	}
	printf("\n");
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
		int d = rand()%100+1;
		gen(n, d);
	}
	t = 5;	
	while (t--)
	{
		int n = rand()%10000+1;
		int d = rand()%100+1;
		gen(n, d);
	}
	gen(10000, 100);
	gen(10000, 1);
}
