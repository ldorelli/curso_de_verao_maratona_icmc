// Bianca Oe 2015
#include <stdio.h>
#include <queue>

using namespace std;

bool used[10000];
vector<int> g[10000], w[10000];
int v[10000];

int main (void) {
	int n, m, a, i, v1, v2, x;
	while (scanf ("%d%d%d", &n, &m, &a) != EOF) {
		g[0].clear();
		w[0].clear();
		for (i = 1; i < n; i++) {
			scanf ("%d", &v[i]);
			g[i].clear();
			w[i].clear();
		}
		for (i = 0; i < m; i++) {
			scanf ("%d%d%d", &v1, &v2, &x);
			g[v1].push_back(v2);
			g[v2].push_back(v1);
			w[v1].push_back(x);
			w[v2].push_back(x);
		}
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		memset(used, 0, sizeof used);
		pq.push(make_pair(0, 0));
		bool ok = true;
		while (ok && !pq.empty()) {
			int curr = pq.top().second;
			int l = pq.top().first; pq.pop();
			if (used[curr])	continue;
			used[curr] = true;
			if (a <= l)	ok = false;
			a += v[curr];
			for (i = 0; i < g[curr].size(); i++) {
				int next = g[curr][i];
				if (!used[next]) {
					pq.push(make_pair(w[curr][i], next));
				}
			}

		}
		printf("%s\n", ok? "SIM": "NAO");
	}
}