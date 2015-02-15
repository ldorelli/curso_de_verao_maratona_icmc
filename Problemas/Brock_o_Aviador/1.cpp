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
#define MAX 100100
#define eps 1e-7
#define ull unsigned long long
#define sync ios :: sync_with_stdio(false)

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

int n;
int f;
struct costs
{
	int gasto, lucro;
	int taxa;
	bool operator < (costs a) const{
		return taxa < a.taxa;
	}

}c[MAX];

int main(void){
	while(cin >> n >> f){
		
		for(int i=0; i<n; ++i)
		{
			cin >> c[i].gasto;
		}

		for(int i=0; i<n; ++i)
		{
			cin >> c[i].lucro;
			c[i].taxa = c[i].gasto - c[i].lucro;
		}

		sort(c, c+n);
		int answ = 0;
		
		for(int i=0; i<n; ++i)
		{	
			if(f >= c[i].taxa)
			{
				f -= c[i].taxa;
				answ++;
			}
		}

		cout << answ << "\n";
	}
	return 0;
}