// Bianca Oe
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int n, m;
bool used[20];
int M[20][20];
int h[20];

long long solve(int curr, int cnt) {
	if (curr == n)	return 0;
	if (cnt == 0)	return 0;
	long long val = 0;
	for (int i = 0; i < curr; i++) {
		if (used[i])	val += M[i][curr] + M[curr][i];
	}
	long long ans = solve(curr+1, cnt);
	used[curr] = true;
	ans = max(ans, h[curr] + val + solve(curr+1, cnt-1));
	used[curr] = false;
	return ans;
}

int main (void) {
	int i, j;
	while (scanf ("%d%d", &n, &m) != EOF) {
		memset (used, 0, sizeof used);
		for (i = 0; i < n; i++)	scanf ("%d", &h[i]);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				scanf ("%d", &M[i][j]);
		}
		printf ("%lld\n", solve(0, m));
	}
}
