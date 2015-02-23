#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000;
int grd[N];
int pref[N];
int vis[N];

double solve (int i) {
	if (vis[i]) return grd[i];
	vis[i] = 1;
	return (grd[i] + solve(pref[i])) * 0.5;
}

int main (void) {
	int n;
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> grd[i] >> pref[i];
		}

		double res = 0.0;
		int melhor = 0;
		for (int i = 0; i < n; ++i) {
			memset(vis, 0, sizeof vis);
			double r = solve(i);
			if (r > res) {
				res = r;
				melhor = i;
			}
		}
		printf("%.3lf %d\n", res, melhor);
	}
	return 0;
}
