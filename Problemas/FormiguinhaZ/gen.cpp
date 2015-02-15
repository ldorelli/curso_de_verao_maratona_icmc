#include <cstdio>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <set>
using namespace std;

const int D = 1000000000;
const int N = 1000000;
int vet[N];

void gen(int n, int d)
{
	printf("%d %d\n", n, d);
	set<int> s;
	for (int i = 0; i < n; ++i)
		s.insert(i);
	for (int i = 0; i < 1000; ++i)
		s.insert(rand()%(d+1));
	for (int i = 0; i < n; ++i)
	{
		auto it = s.lower_bound(rand()%(d+1));
		if (it == s.end()) --it;
		printf("%d %d\n", *it, rand()%2);
		s.erase(it);
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
		int n = rand()%50+1;
		int d = rand()%1000;
		if (d < n) d = n;
		gen(n, d);
	}
	t = 5;
	while (t--)
	{
		int n = rand()%100000+1;
		int d = rand()%D+1;
		if (d < n) d = n;
		gen(n, d);
	}
	gen(100000, 1000000000);
}

