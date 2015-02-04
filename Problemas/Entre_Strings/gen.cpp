#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

void gen(int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%c", rand()%26+'a');
	}
	printf(" ");
	for (int i = 0; i < m; ++i)
	{
		printf("%c", rand()%26+'a');
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
		int m = rand()%100+1;
		gen(n, m);
	}
	t = 5;	
	while (t--)
	{
		int n = rand()%10000+1;
		int m = rand()%10000+1;
		gen(n, m);
	}
	gen(10000, 10000);
}
