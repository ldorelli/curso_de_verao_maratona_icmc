#include <iostream>
#include <queue>

using namespace std;


typedef pair<int, int> ii;

#define ll long long
#define mp make_pair
#define F first
#define S second

bool inserted[1000][1000];
int value[1000][1000];
priority_queue<pair<int, pair< int, int > > > pq;
int n,m,k;

void insertpq(int l, int c){
	if(!inserted[l][c]){
		pq.push(mp(value[l][c],mp(l,c)));
		inserted[l][c] = 1;
	}
}

void mine(int l, int c){
	if(l > 0){
		insertpq(l-1,c);
	}
	if(l < n-1){
		insertpq(l+1,c);
	}
	if(c > 0){
		insertpq(l, c-1);
	}
	if(c < m-1){
		insertpq(l, c+1);
	}
}


int main(int argc, char const *argv[])
{
	while(cin >> n >> m >> k){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				inserted[i][j] = 0;
				cin >> value[i][j];
			}
		}

		while(!pq.empty()){
			pq.pop();
		}

		for(int i = 0; i < n; i++){
			insertpq(i,0);
			insertpq(i,m-1);
		}
		for(int i = 0; i < m; i++){
			insertpq(0,i);
			insertpq(n-1,i);
		}

		ll total = 0;
		for(int i = 0; i < k; i++){
			pair<int , ii> aux = pq.top();
			pq.pop();

			total+=aux.first;
			mine(aux.S.F, aux.S.S);
		}
		cout<< total << endl;
	}



    return 0;
}