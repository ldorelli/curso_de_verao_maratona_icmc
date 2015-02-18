// Anderson Silva, 2014

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > adj[1004];
int used[1004];

void dfs(int cur, int& size) {
	used[cur] = 1;

	for(int i = 0; i <  adj[cur].size(); i++) {

		size++;
		if(!used[adj[cur][i]]) {
			dfs(adj[cur][i], size);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	int n, a, b;

	while(cin >> n) {

		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int result = 0;
		for(int i = 1; i <=n ; i++) {		

			int size = 0;
			if(!used[i]) {
				dfs(i, size);
				result = max(result, size);
			}
		}

		cout << (int) result/2 << "\n";
		for(int i = 0; i <= n; i++) {
			used[i] = 0;
			adj[i].clear();
		}
	}

	return 0;
}