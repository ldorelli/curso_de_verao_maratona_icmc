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
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD 1000000007

int m[100001];
int k;

int pd(int x){
	if (x < k){
		return 1;
	}else if(m[x] != -1){
		return m[x];
	}else{
		int sum = 0;
		for(int i = 1; i <= k; i++){
			sum = (sum + pd(x - i)) % MOD;
		}

		return m[x] = sum;
	}
}


int main(int argc, char const *argv[])
{
	int x;
	while(cin >> k >> x){
		memset(m, -1, sizeof m);
		cout << pd(x) << endl;
	}
    return 0;
}