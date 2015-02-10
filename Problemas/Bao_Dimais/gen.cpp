#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen(int n)
{
	printf("%d\n", n);
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
		gen(n);
	}	
	gen(10000);
}
