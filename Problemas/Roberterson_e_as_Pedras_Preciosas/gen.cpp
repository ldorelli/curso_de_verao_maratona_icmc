#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 2000000000
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

vi v;
int values[200][200];

int main(int argc, char const *argv[])
{
	srand(clock());

	for(int i = 0; i < 150*150; i++){
		v.pb(i+1);
	}

	for(int i = 0; i < 30; i++){
		srand(clock());
		int n, m, k;
		n = rand()%150+1;
		m = rand()%150+1;
		k = rand()%(n*m)+1;
		
		cout << n << " " << m << " " << k << endl;

		random_shuffle(v.begin(), v.end());

		for(int j = 0; j < n; j ++){
			for(int l = 0; l < m; l++){
				cout << v[m*j + l] << " ";
			}
			cout << endl;
		}

	}

    return 0;
}