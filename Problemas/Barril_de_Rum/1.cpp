// Bianca Oe, 2015

#include <stdio.h>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;

char M[1001][1001];
bool used[1000][1000];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int n, m;

bool ok(pair<int, int> pos) {
	return pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < m;
}

int main (void) {
	int i;
	while (scanf ("%d%d", &n, &m) != EOF) {
		memset(used, 0, sizeof used);
		for (i = 0; i < n; i++) {
			scanf ("%s", M[i]);
		}
		queue<pair<int, int> > q;
		q.push(make_pair(0, 0));
		used[0][0] = 1;
		int ans = 1;
		while (!q.empty()) {
			pair<int, int> curr = q.front();
			q.pop();
			for (i = 0; i < 4; i++) {
				pair<int, int> next(curr.first+dir[i][0], curr.second+dir[i][1]);
				if (ok(next) && M[next.first][next.second] == '.' && !used[next.first][next.second]) {
					used[next.first][next.second] = true;
					ans++;
					q.push(next);
				}
			}
		}
		printf ("%d\n", ans);
	}
	
}
