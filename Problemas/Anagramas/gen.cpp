#include <cstdio>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <set>
using namespace std;

const int N = 1000;

void gen(int n, int m)
{
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		int r = rand()%m+1;
		for (int j = 0; j < r; ++j)
			printf("%c", rand()%26+'a');
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
		int n = rand()%10+1;
		int m = rand()%4+1;
		gen(n, m);
	}
	t = 10;
	while (t--)
	{
		int n = rand()%N+1;
		int m = rand()%20+1;
		gen(n, m);
	}
	gen(N, 20);
}
