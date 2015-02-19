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
#define N 13
#define A 100
#define D 10000
#define T 30

int d[16][16];

int main(int argc, char const *argv[])
{
	srand(clock());
	for(int i = 0; i < T; i++){
		int n = rand()%N + 1;
		cout << n << endl;
		for(int j = 0; j < n; j++){
			cout << rand()%A + 1 << " ";
		}
		cout << endl;

		for(int j = 0; j <= n; j++)	{
			for(int k = j; k <= n; k++){
				if(k==j){
					d[k][j] = 0;
				}else{
					int aux = rand()%D + 1;
					d[k][j]	= aux;
					d[j][k] = aux;
				}
			}
		}

		for(int k = 0; k <= n; k++){
			for(int j = 0; j <=n; j++){
				cout << d[k][j] << " ";
			}
			cout << endl;
		}
	}
    return 0;
}