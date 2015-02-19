#include <cstdio>
#include <sys/time.h>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

const int N = 1001;
const int M = 3001;
int vet[N], are[M][2], use[M];

void gen(int n, int m)
{
	for (int i = 1; i <= n; ++i)
		vet[i] = i;
	int mm = 0;
	
	// conecta grafo
	random_shuffle(vet+1, vet+n+1);
	for (int i = 1; i < n; ++i)
	{
		are[mm][0] = vet[i], are[mm][1] = vet[i+1], ++mm; 
	}
		
	int x = m-mm;
	while (x > 0)
	{
		--x;
		int a = rand()%n+1;
		int b = rand()%n+1;
		are[mm][0] = a;
		are[mm][1] = b;
		++mm;
	}
	
	printf("%d %d\n", n, mm);
		
	// printa arestas finais
	for (int i = 0; i < mm; ++i)
		use[i] = i;
	random_shuffle( use, use+mm);
	for (int i = 0; i < mm; ++i)
		printf("%d %d\n", are[use[i]][0], are[use[i]][1]);
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
		int m = rand()%100+1;
		gen(n, m);
	}
	t = 10;
	while (t--)
	{
		int n = rand()%1000+1;
		int m = rand()%3000+1;
		gen(n, m);
	}
	gen(1000, 3000);
}
