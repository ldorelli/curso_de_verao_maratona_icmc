// Tomas Fonseca
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

vi lim;

int main(int argc, char const *argv[])
{
	int n, q;
	while(cin >> n >> q){
		lim.clear();
		for(int i = 0; i < n; i++){
			int aux;
			cin >> aux;
			lim.pb(aux);
		}

		int last;
		last = lim[lim.size()-1];

		for(int i = 0; i < q; i++){
			int cq;
			cin >> cq;
			if(cq >=last)
				cout << -1 << endl;

			else{
				vi::iterator it = upper_bound(lim.begin(), lim.end(), cq);
				cout << it - lim.begin() + 1 << endl;
			}
		}
	}
    return 0;
}