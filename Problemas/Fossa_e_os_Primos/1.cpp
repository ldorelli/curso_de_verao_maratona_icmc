// Shi, 2014

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1001;
int np[N];


void pre()
{
	np[1] = 1;
	for (int x = 2; x < N; ++x)
		if(!np[x]) 
		{
			for (int y = x*x; y < N; y += x)
				np[y] = 1;
		}
}

bool good (int a, int b, int l, int k)
{
	int p = 0;
	for (int i = a; i < a+l; ++i) 
		if (!np[i]) ++p;

	int i = a, j = a+l;
	if (p < k) return false;
	
	while (j <= b) {
		if (!np[i]) --p;
		if (!np[j]) ++p;
		++i; ++j;

		if (p < k) return false;
	}
	return true;
}

int main(void)
{
	pre();
	int a, b, k;
	while(cin >> a >> b >> k)
	{
		int l = 0;
		for (; l <= (b-a)+1; ++l)
		{
			if (good(a, b, l, k)) break;
		}
		if (l > (b-a)+1) cout << -1 << endl;
		else cout << l << endl;
	}
	return 0;
}