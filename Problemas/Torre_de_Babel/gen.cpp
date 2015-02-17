#include <cstdio>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

void gen(int n)
{
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d %d\n", rand()%n+1, rand()%n+1);
	}
}

void genmal(int n)
{
	printf("%d\n", n);
	while (n--)
	{
		printf("1 2\n");
	}
}

int main()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	srand(tv.tv_usec);

	int t = 40;
	while (t--)
	{
		int n = rand()%100+1;
		gen(n);
	}
	t = 10;
	while (t--)
	{
		int n = rand()%1000+1;
		gen(n);
	}
	gen(1000);
	genmal(1000);
}
