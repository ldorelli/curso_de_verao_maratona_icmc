// Bianca Oe, 2015

#include <stdio.h>
#include <iostream>
using namespace std;

int pd[1000][1001];
int w[1000], v[1000];
int n;

int solve(int curr, int tot) {
	if (curr == n)	return 0;
	if (!pd[curr][tot]) {
		pd[curr][tot] = solve(curr+1, tot);
		if (w[curr] <= tot)
			pd[curr][tot] = max(pd[curr][tot], solve(curr+1, tot-w[curr]) + v[curr]);
	}
	return pd[curr][tot];
}

int main (void) {
	int tot;
	while (scanf ("%d%d", &tot, &n) != EOF) {
		memset(pd, 0, sizeof pd);
		for (int i = 0; i < n; i++) {
			scanf ("%d%d", &w[i], &v[i]);
			w[i] /= 1000;
		}
		printf ("%d\n", solve(0, tot/1000));
	}
}