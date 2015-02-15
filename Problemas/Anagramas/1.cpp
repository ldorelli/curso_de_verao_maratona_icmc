// Anderson Silva, 2014

#include <iostream> 
#include <string> 

using namespace std;

string s[1003];

int v[1003][256], vis[1000];

bool cmp(int i, int j) {

	for(int k = 'a'; k <= 'z'; k++)
		if(v[i][k] != v[j][k])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	int n;

	while(cin >> n) {

		for(int i = 0; i < n; i++) {
			cin >> s[i];		

			for(int j = 0; j < s[i].size(); j++)
				v[i][s[i][j]]++;
		}

		for(int i = 0; i < n; i++) {
			if (vis[i]) continue;
			for(int j = i + 1; j < n; j++)
				if(cmp(i, j)) vis[j] = 1;
		}

		int result = 0;
		for (int i = 0; i < n; ++i)
			result += vis[i] == 0;

		for(int i = 0; i < n; i++)
		{
			vis[i] = 0;
			for(int j = 0; j <= 255; j++)
				v[i][j] = 0;
		}
		
		cout << result << '\n';
	}
	
	return 0;
}