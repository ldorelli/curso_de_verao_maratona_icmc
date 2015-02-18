// Filipe Nascimento, 2014

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> g[1010];
bool vis[1010];
int langs[1010][2];
int _count;

void dfs(int v){
	vis[v] = 1;
	_count++;
	for(int i = 0; i < g[v].size(); i++)
		if(!vis[g[v][i]])
			dfs(g[v][i]);
}

int main(){
	while(cin >> n){
		for(int i = 1; i <= n; i++){
			vis[i] = 0;
			g[i].clear();
			cin >> langs[i][0] >> langs[i][1];
			for(int j = 1; j < i; j++){
				if(langs[j][0] == langs[i][0] || langs[j][0] == langs[i][1] || 
					langs[j][1] == langs[i][0] || langs[j][1] == langs[i][1]){
					g[j].push_back(i);
					g[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				_count = 0;
				dfs(i);
				ans = max(ans,_count);
			}
		}
		cout << ans << endl;	
	}

	return 0;
}