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

int main(int argc, char const *argv[])
{
	int t = 50;
	srand(clock());
	while(t--){
		int n = rand()%20 + 1;
		int m = rand()%n + 1;
		cout << n <<" "<< m << endl;
		for(int i = 0; i < n; i++){
			cout << rand()%200001 - 100000 << " ";
		}
		cout << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << rand()%200001 - 100000 << " ";
			}
			cout << endl;
		}

	}
    return 0;
}