// Bruno Sanches, 2014

#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define mod (ll)10e9
#define B 33
#define MAX 200010
#define eps 1e-7
#define ull unsigned long long
#define sync ios :: sync_with_stdio(0)

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;


map<int,int> m;
int x,y,n;
int main(void){
	while(scanf("%d",&n) != EOF){
		m.clear();
		for(int i=0; i<n; ++i){
			scanf("%d%d",&x,&y);
			m[x]++; m[y]++;
		}
		for(map<int,int> :: iterator it = m.begin(); it != m.end(); ++it)
			printf("%d %d\n",it->F, it->S);
		printf("*\n");
	}
	return 0;
}