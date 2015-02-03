// Anderson Silva, 2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <vector>
#include <string.h>

#define N 1003
#define ll long long
#define mp make_pair
#define pb push_back
#define F first 
#define S second 
#define mod 10e9 + 7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

string field[N];
int n, m;
int result = 0;
int used[N][N];

void solve(int i, int j) {
	if(i < 0 || i >= n || j < 0 || j >= m || used[i][j] || field[i][j] == 'o') return;

	used[i][j] = 1;

	result++;
	solve(i, j + 1);
	solve(i, j - 1);
	solve(i + 1, j);
	solve(i - 1, j);
}

int main () {
	ios::sync_with_stdio(0);
	
	while(cin >> n >> m) {
		result = 0;
		memset(used, 0, sizeof used);

		for(int i = 0; i < n; i++) 
			cin >> field[i];

		solve(0, 0);
		cout << result << "\n";
	}
	return 0;
}