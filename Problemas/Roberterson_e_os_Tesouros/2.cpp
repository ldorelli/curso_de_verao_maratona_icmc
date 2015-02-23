// Tomas Fonseca 2015
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
#define MOD 1000000007
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int n, k;		

int m[10001][101];
vi t;

int pd(int pos, int mod){
	if(pos >= n){
		if(mod == 0)
			return 1;
		else
			return 0;
	}
	else if(m[pos][mod] != -1)
		return m[pos][mod];
	else{
		ll total = 0;
		total = (total + pd(pos + 1, mod)) % MOD;
		total = (total + pd(pos + 1, (mod - (t[pos]%k) + k)%k)) % MOD;
		return m[pos][mod] = total;
	}
}

int main(int argc, char const *argv[])
{
	while(cin >> n >> k){

		memset(m, -1, sizeof m);
		t.clear();

		for(int i = 0; i < n; i++){
			int aux;
			cin >> aux;
			t.pb(aux);
		}

		cout << pd(0, 0) - 1 << endl;

	}
    return 0;
}