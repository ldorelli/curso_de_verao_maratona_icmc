#include <cstdio>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <set>
using namespace std;

const int N = 10000;
const int M = 1000000000;
int vet[N];

void gen(int n, int m)
{
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i)
	{
		if (i) printf(" ");
		vet[i] = rand()%m+1;
		printf("%d", vet[i]);
	}
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		if (i) printf(" ");
		vet[i] = rand()%vet[i]+1;
		printf("%d", vet[i]);
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
		int n = rand()%10+1;
		int m = rand()%10+1;
		gen(n, m);
	}
	t = 10;
	while (t--)
	{
		int n = rand()%N+1;
		int m = rand()%M+1;
		gen(n, m);
	}
	gen(N, M);
}
