// Tomas Fonseca
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);



int a[16];
int d[16][16];
ll m[16][17000];
int n;

ll pd(int pos, int mask){
	if(__builtin_popcount(mask) == n){
		return 0;
	}else if(m[pos][mask] != -1){
		return m[pos][mask];
	}else{
		int aux = mask;
		ll mn = 2000000000;

		int curw = 0;
		for(int i = 0; i < n; i++){
			if(!(aux & 1)){
				curw += a[i+1];
			}
			aux = aux >> 1;
		}
		aux = mask;

		for(int i = 0; i < n; i++){
			if(!(aux & 1)){
				mn = min(mn, curw*d[pos][i + 1] + pd(i+1, mask + (1 << i)) );
			}
			aux = aux >> 1;
		}
		return m[pos][mask] = mn;
	}
}

int main(int argc, char const *argv[])
{
	while(cin >> n)	{
		for(int i = 0; i< n; i++){
			cin >> a[i+1];
		}

		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				cin >> d[i][j];
			}
		}
		memset(m, -1, sizeof m);
		cout << pd(0, 0) << endl; }
    return 0;
}