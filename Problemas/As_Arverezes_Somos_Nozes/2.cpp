// Filipe Nascimento, 2014

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> g[10010];
bool vis[10010];

void preorder(int v){
	vis[v] = 1;
	cout << v << ' ';
	for(int i = 0; i < g[v].size(); i++)
		if(!vis[g[v][i]]) 
			preorder(g[v][i]);
}

int main(){
	int a,b;
	while(cin >> n){
		for(int i = 0; i <= n; i++){
			vis[i] = 0;
			g[i].clear();
		}
		for(int i = 1; i < n; i++){
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		preorder(1);
		cout << '\n';
	}
	return 0;
}