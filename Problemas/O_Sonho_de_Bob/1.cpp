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

vi steps;
int n, k;

bool test(int h){
	int curpos = -1;
	int curheight= 0;
	int njumps = 0;

	for(int i = 0; i < n; i++){
		if(curheight + h < steps[i]){
			if(i - curpos == 1){
				njumps = 2000000000;
				break;	
			}
			njumps++;
			i--;
			curpos = i;
			curheight = steps[curpos];
		}
	}
	njumps++;
	if(njumps <= k)
		return true;
	else
		return false;
}

int main(int argc, char const *argv[]){
	while(cin >> n >> k){
		steps.clear();
		for(int i = 0; i < n; i++){
			int aux;
			cin >> aux;
			steps.pb(aux);
		}

		int hi = steps[steps.size() - 1];
		int lo = 0;

		while(hi - lo > 0){
			int mid = (hi+lo)/2;
			if(test(mid)){
				hi = mid;
			}else{
				lo = mid + 1;	
			}

		}

		cout << lo << endl;
	}
    return 0;
}