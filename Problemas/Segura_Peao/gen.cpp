#include <cstdio>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <set>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define F first
#define S second
#define mp make_pair

const int N = 1000;
const int M = 100000;
const int C = 1000000000;

void gen(int n, int m)
{
	if (m < n-1) m = n-1;
	vector<pair<int, int> > vet;
	for (int i = 1; i < n; ++i)
	{
		vet.push_back(mp(i, i+1));
	}
	
	int mm = m-vet.size();
	while (mm--)
	{
		vet.push_back(mp(rand()%n+1, rand()%n+1));
	}
	
	random_shuffle(vet.begin(), vet.end());
	
	printf("%d %d\n", n, (int)vet.size());
	for (int i = 0; i < vet.size(); ++i)
		printf("%d %d %d\n", vet[i].F, vet[i].S, rand()%C+1);	
}

int main()
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	srand(tv.tv_usec);

	int t = 50;
	while (t--)
	{
		int n = rand()%20+1;
		int m = rand()%100+1;
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
