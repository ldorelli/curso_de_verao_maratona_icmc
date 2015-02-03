#include <cstdio>
#include <sys/time.h>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

const int N = 100001;
const int M = 1000001;
set<int> adj[N];
int vet[N], are[M][2], use[M], col[N];

void gen(int n, int m, bool k)
{
	for (int i = 1; i <= n; ++i)
		adj[i].clear(), vet[i] = i;
	int mm = 0;
	
	// conecta grafo
	random_shuffle(vet+1, vet+n+1);
	col[vet[1]] = 1;
	for (int i = 1; i < n; ++i)
	{
		are[mm][0] = vet[i], are[mm][1] = vet[i+1], ++mm; 
		adj[vet[i]].insert(vet[i+1]);
		adj[vet[i+1]].insert(vet[i]);
		col[vet[i+1]] = !col[vet[i]];
	}
		
	int x = m-mm;
	while (x > 0)
	{
		--x;
		int a = rand()%n+1;
		int b = rand()%n+1;
		if (a == b || adj[a].count(b)) continue;
		if (k == 1 && col[a] == col[b]) continue; // deixe bipartido fera
		adj[a].insert(b);
		adj[b].insert(a);
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

	int t = 10;
	while (t--)
	{
		int n = rand()%10+1;
		int m = rand()%100+1;
		gen(n, m, 0);
		gen(n, m, 1);
	}
	t = 1;
	while (t--)
	{
		int n = rand()%100000+1;
		int m = rand()%1000000+1;
		gen(n, m, 0);
		gen(n, m, 1);
	}
	gen(100000, 1000000, 0);
	gen(100000, 1000000, 1);
}
