// Bianca Oe, 2015

#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 1000;
int dp[N + 1][N + 1];
int w[N], v[N], n;

int main (void) {
	int tot;
	while (scanf ("%d%d", &tot, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf ("%d%d", &w[i], &v[i]);
			w[i] /= 1000;
		}
	
		for (int i = 0; i <= tot; ++i)
			if (w[0] <=i) dp[0][i]  = v[i];
			else dp[0][i] = 0;

		for (int i = 1; i < n; ++i) 
			for (int p = 0; p <= tot; ++p) 
				if (w[i] < p) dp[i][p] = dp[i-1][p];
				else dp[i][p] = max(v[i] + dp[i-1][p - w[i]], dp[i-1][p]);
	
		printf ("%d\n", dp[n-1][N]);
	}
}
