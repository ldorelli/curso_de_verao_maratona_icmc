#include <cstdio>
#include <sys/time.h>
#include <cstdlib>

char use[] = "v^<>#";

void gen(int n, int m, int z)
{
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int r = rand()%z;
			printf("%c", use[r]);
			
		}
		printf("\n");
	}
}

int main()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	srand(tv.tv_usec);

	int t = 1;
	while (t--)
	{
		int n = rand()%10+1;
		int m = rand()%10+1;
		//gen(n, m, 5);
		gen(n, m, 4);
	}
	/*t = 3;
	while (t--)
	{
		int n = rand()%1000+1;
		int m = rand()%1000+1;
		gen(n, m, 5);
		gen(n, m, 4);
	}
	gen(1000, 1000, 5);
	gen(1000, 1000, 4);*/
}
