// Danilo Tedeschi
#include <iostream>

using namespace std;
#define N 21

int skill[ N ];
int modsk[ N ][ N ];
int n,m;

int f( int cur, int res, int used ) {
	if( cur== n ) return res;
	if( __builtin_popcount( used ) == m ) return res; 
	int r1 = res + skill[ cur ];

	for( int i = 0; i<n; i++ ) if( used & (1<<i) )
	{
		r1 += modsk[ cur ][ i ];		
		r1 += modsk[ i ][ cur ];
	}

	r1 = f( cur + 1, r1, used | (1<<cur) ); 
	return max( r1, f( cur+1, res, used ) );
}

int main() {
	
	while( cin >> n >> m ) {
		for( int i = 0; i<n; ++i ) cin >> skill[i];

		for( int i = 0; i<n; i++ )
			for( int j = 0; j<n; j++ ) cin >> modsk[i][j];

		cout << f( 0, 0, 0 ) << endl;

	}

	return 0;
}
