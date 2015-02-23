#include <bits/stdc++.h>
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define error(x) cerr << #x << " = " << (x) <<endl
#define INF 0x3f3f3f3f
#define mk make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair< int, ii > iii;
typedef vector< iii > viii;
typedef vector<ii> vii;
#define N 50010
vii adj[N];
int n,m,c;
ii dist[N][2];

int bfs( ){
        queue<int>Q;
        memset( dist, INF, sizeof( dist ));
        Q.push( 0 );

        For( i,0,n)
        {
                dist[i][0].second = dist[i][1].second = INF;
                dist[i][0].first = dist[i][1].first = -1;
        }
        dist[0][0].second = dist[0][1].second = 0;

        while( !Q.empty() ){
                int u = Q.front();
                //cout << u << endl;
                Q.pop();

                for( int i = 0; i<adj[u].size(); i++ ){
                        int v = adj[u][i].second;
                        int cv = adj[u][i].first;
                        int ui = 0;
                        if( dist[u][0].first == cv )
                                ui = 1;
                        if( dist[u][ui].second + 1 < dist[v][0].second ) {
                                dist[v][0].second = dist[u][ui].second + 1;
                                dist[v][0].first = cv;
                                Q.push( v );
                        }
                        else if( dist[u][ui].second + 1 < dist[v][1].second && cv != dist[v][0].first ) {
                                dist[v][1].second = dist[u][ui].second + 1;
                                dist[v][1].first = cv;
                                Q.push( v );
                        }
                }
        }
        return min( dist[n-1][1].second, dist[n-1][0].second );
}

int main(){

        while( cin >> n >> m >> c ) {
                For(i,0,n) adj[i].clear();
                For( i,0,m)
                {
                        int u,v,c;
                        cin >> u >> v >> c;u--;v--;
                        adj[u].pb( mk(c,v ) );
                        adj[v].pb( mk(c,u ) );
                }
                int ans = bfs();
                
                cout << ((ans>=INF)?-1:ans) << "\n";
        }

        return 0;
}
