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
#define N 20000
#define M 50000
#define T 30

set<ii> in;
vector<int> invec;

int main(int argc, char const *argv[])
{
	srand(clock());
	for(int i = 0;i < T; i++){
		int n = rand()%(N-1) + 2;
		int mdelta = ( min(M, (n*(n-1))/2) )-(n-1);
		int m =	rand()%(mdelta + 1) + (n-1);

		cout << n << " " << m << endl;

		invec.clear();
		for(int j = 1; j <= n; j++){
			invec.pb(j);
		}
		random_shuffle(invec.begin(), invec.end());

		for(int j = 0; j < n-1; j++){
			in.insert(mp(invec[j], invec[j+1]));
			in.insert(mp(invec[j+1], invec[j]));
			cout << invec[j] << " " << invec[j+1]<<endl;
		}

		for(int j = 0; j < m - (n-1); j++){
			int a,b;

			do{
				a = rand()%n + 1;
				b = rand()%n + 1;
			}while( in.count(mp(a,b)) || (a == b) );
			in.insert(mp(a,b));
			in.insert(mp(b,a));
			cout << a << " " << b << endl;
		}
	}
    return 0;
}