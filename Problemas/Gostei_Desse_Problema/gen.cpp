#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen(int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (rand()&1) printf("%c", rand()%26+'a');
		else printf("%c", rand()%26+'A');
	}
	printf("\n");
}

int main()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	srand(tv.tv_usec);

	int n = 100000-13;
	printf("100000\n");
	while (n--)
	{
		gen(rand()%100+1);
	}
	gen(100);
	gen(100);
	int q = 100000-8;
	printf("100000\n");
	while (q--)
	{
		gen(rand()%100+1);
	}
	gen(100);
	gen(100);
}
