#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define mod (ll)10e9
#define B 33
#define MAX 100001
#define eps 1e-7
#define ull unsigned long long

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

vi v;
map<int,int> m;
int c;
int n,x;
int main(void){
	ios :: sync_with_stdio(0);
	while(cin >> n){
		v.clear();
		m.clear();
		for(int i=0; i<n; ++i){
			cin >> x;
			v.pb(x);
			m[x]++;
		}
		cin >> c;
		int ok = 0;
		for(int i=0; i<v.size(); ++i){
			if(c-v[i] != v[i] && m[c-v[i]] > 0)
				ok = 1;
			else if(c-v[i] == v[i] && m[c-v[i]] > 1)
				ok = 1;
		}
		if(ok) cout << 'S' << "\n";
		else cout << 'N' << "\n";
	}
	return 0;
}
