// Anderson Silva, 2014

#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[10004];

void pre_ordem(int cur, int father) {
	cout << cur << " ";

	for(int i = 0; i < adj[cur].size(); i++) 
		if(adj[cur][i] != father) pre_ordem(adj[cur][i], cur);
}

int main() {
	ios::sync_with_stdio(0);
	int n, a, b;

	while(cin >> n) {

		for(int i = 1; i < n; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		pre_ordem(1, 0);
		cout << '\n';
		
		for(int i = 0; i <= n; i++)
			adj[i].clear();
	}

	return 0;
}