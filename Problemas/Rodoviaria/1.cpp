// Danilo Tadeschi
#include <iostream>
#include <vector>
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
#define N 100010

int vec[ N ], n, q;

int main(){
        
        while( cin >> n >> q ) {
                for( int i = 0; i<n; i++ ) cin >> vec[i];

                while( q-- ) {
                        int x;
                        cin >> x;
                        int p = upper_bound( vec, vec + n, x ) - vec;
                        if( p == n )
                                cout << "-1\n";
                        else
                                cout << p + 1 << "\n";
                }
        }
        

        return 0;
}
