// Tomas Fonseca 2015
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

bool on[1000001];

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		for(int i = 1; i <= n; i++){
			on[i] = 1;
		}

		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j+=i){
				on[j] = !(on[j]);
			}
		}
		int t = 0;
		for(int i = 1; i <= n; i++){
			t += !on[i];
		}
		cout << t << endl;
	}
    return 0;
}