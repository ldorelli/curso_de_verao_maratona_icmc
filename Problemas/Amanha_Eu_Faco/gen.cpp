#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen(int n, int k, int d)
{
	printf("%d %d %d\n", n, k, d);
	for (int i = 0; i < n; ++i)
	{
		if (i) printf(" ");
		printf("%d", rand());
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
		int n = rand()%10000+1;
		int k = rand()%n+1;
		int d = rand()%k+1;
		gen(n, k, d);
	}	
	gen(10000, 666, 333);
}
