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

#define N 10e5
#define ll long long
#define mp make_pair
#define pb push_back
#define F first 
#define S second 
#define mod 10e9 + 7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main () {
	ios::sync_with_stdio(0);
	
	map<int,int> m;
	int n, a, b;
	while(cin >> n) {
		while(n--) {
			cin >> a >> b;
			m[a]++;
			m[b]++;
		}

		for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
			cout << (*it).F << " " << (*it).S << '\n';
		cout << "*\n";
		m.clear();
	}
	return 0;
}