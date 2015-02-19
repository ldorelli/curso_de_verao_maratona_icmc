// Tomas Fonseca 2015
#include <bits/stdc++.h>

using namespace std;

vector<int> tree[201];

int dfs(int cur, int target){
	if(cur == target)
		return 0;
	else{
		for(int i = 0; i < tree[cur].size(); i++){
			int aux = dfs(tree[cur][i], target);
			if(aux >= 0)
				return aux + 1;
		}
		return -1;
	}
}


int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){

		for(int i = 0; i <= n; i++){
			tree[i].clear();
		}

		for(int i = 0; i < n-1; i++){
			int a, b;
			cin >> a >> b;
			tree[b].push_back(a);
		}

		int a, d;
		cin >> a >> d;
		int ans = dfs(d, a);
		if(ans == 1){
			cout << "pai" << endl;
		}else if( ans == 2){
			cout << "avo" << endl;
		}else if( ans == 3){
			cout << "bisavo" << endl;
		}else{
			string out = "vo";
			for(int i = 4; i <= ans; i++){
				out = "tatara" + out;
			}
			cout << out << endl;
		}
	}
    return 0;
}