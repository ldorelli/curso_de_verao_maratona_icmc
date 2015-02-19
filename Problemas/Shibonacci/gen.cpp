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
#define T 50
#define N 10000
#define K 100


int main(int argc, char const *argv[])
{
	srand(clock());
	for(int i = 0; i < T; i++){
		int k = rand()%K + 1;
		int x = rand()%(N+1);
		cout << k << " " << x << endl;
	}

    return 0;
}