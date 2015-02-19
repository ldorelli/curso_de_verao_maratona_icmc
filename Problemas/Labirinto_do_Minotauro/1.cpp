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
int used[N][N];

bool solve(int i, int j) {
	if(i < 0 || i >= n || j < 0 || j >= m) return false;

	if(used[i][j] == 1) return true;
	if(used[i][j] == 2) return false;
	used[i][j] = 1;

	if(field[i][j] == '>' || field[i][j] == '#')  {
		if(solve(i, j + 1)) return true;
	}

	if(field[i][j] == '<' || field[i][j] == '#') {
		if(solve(i, j - 1)) return true;
	}
	if(field[i][j] == '^' || field[i][j] == '#') {
		if(solve(i - 1, j)) return true;
	}

	if(field[i][j] == 'v' || field[i][j] == '#') {
		if(solve(i + 1, j)) return true;
	}
	
	used[i][j] = 2;
	
	return false;
}

int main () {
	ios::sync_with_stdio(0);
	
	while(cin >> n >> m) {
		memset(used, 0, sizeof used);
		for(int i = 0; i < n; i++) 
			cin >> field[i];
		cout << (solve(0, 0) ? "S\n" : "N\n");
	}
	return 0;
}