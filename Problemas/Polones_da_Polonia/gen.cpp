#include <cstdio>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

void print(int u, int v)
{
	if (rand()%2) swap(u, v);
	printf("%d %d\n", u, v);
}

// altura pequena
int gen1(int v, int n, int& id, int d)
{
	int c = rand()%5, r = d;
	while (c--)
	{
		if (id <= n)
		{
			int u = id++;
			print(u, v);
			r = max(r, gen1(u, n, id, d+1));
		}
	}
	if (v == 1 && id <= n) return gen1(1, n, id, d);
	return r;
}

// altura grande
int gen2(int v, int n, int &id, int d)
{
	int c = rand()%3, r = d;
	while (c--)
	{
		if (id <= n)
		{
			int u = id++;
			print(u, v);
			r = max(r, gen1(u, n, id, d+1));
		}
	}
	if (v == 1 && id <= n) return gen2(1, n, id, d);
	return r;
}

int main()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	srand(tv.tv_usec);

	int t = 30;
	while (t--)
	{
		int n = rand()%100+1, id = 2;
		printf("%d %d\n", n, rand()%1000+1);
		fprintf(stderr, "%d\n", gen1(1, n, id, 0));
		printf("%d %d\n", n, rand()%1000+1);
		id = 2;
		fprintf(stderr, "%d\n", gen2(1, n, id, 0));
	}
	t = 10;
	while (t--)
	{
		int n = rand()%10000+1, id = 2;
		printf("%d %d\n", n, rand()%100000+1);
		fprintf(stderr, "%d\n", gen1(1, n, id, 0));
		printf("%d %d\n", n, rand()%100000+1);
		id = 2;
		fprintf(stderr, "%d\n", gen2(1, n, id, 0));
	}
	int n = 10000, id = 2;
	printf("%d %d\n", n, 10000);
	fprintf(stderr, "%d\n", gen1(1, n, id, 0));
	printf("%d %d\n", n, 10000);
	id = 2;
	fprintf(stderr, "%d\n", gen2(1, n, id, 0));
}
