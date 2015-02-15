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

int vn[100001];
int vm[100001];

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin >> n >> m){
		ll l = 0, g = 0, e = 0;
		for(int i = 0; i < n; i++){
			cin >> vn[i];
		}
		for(int i = 0; i < m; i++){
			cin >> vm[i];
		}
		sort(vn, vn+n);
		sort(vm, vm+m);
		int j = 0;
		for(int i = 0; i < n; i++){
		while((vm[j] < vn[i])&&(j != m))
				j++;

			if(j == m)	{
				g += m;
			}

			else if(vn[i] == vm[j]){
				g += j;	
				int last = upper_bound(vm, vm+m, vm[j]) - vm;
				e += last - j;
				l += m - j - (last-j);
			}else{
				g += j;
				l += m - j;
			}
		}
		cout << g << " " << l << " " << e << endl;
	}

    return 0;
}