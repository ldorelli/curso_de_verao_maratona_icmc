// Tomás Fonseca 2015
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

int v[10];
int m[10][10];

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			v[i] = i;
			for(int j = 0; j < n; j++){
				cin >> m[i][j];
			}
		}
		int mx = 0;
		do{
			int total = 0;
			for(int i = 0; i < n; i++){
				total+= m[i][v[i]];
			}
			if(total > mx)
				mx = total;
		}while(next_permutation(v, v+n));

		cout << mx << endl;
	}
    return 0;
}