// Danilo Tadeschi 2015
#include <iostream>

using namespace std;
int n, k, vec[ 100010 ];

bool chk( int jum ) {

	int j = 0;
	int hant = 0;
	for( int i = 0 ;i < k && j < n; i++) {
		int ju = jum;
		while( ju > 0 && j < n )
		{
			if( ju - (vec[j]-hant) < 0 ) break;
			ju -= vec[j]-hant;
			hant = vec[j];
			j++;
		}

	}
	return j == n;
}

int main( ) {

	while( cin >> n >> k ) {
		for( int i = 0; i<n; i++ ) cin >> vec[i];

		int lo = 0, hi = vec[n-1], mi;
		while( lo != hi ) {
			mi = (lo+hi)/2;
			if( chk( mi ) )
				hi = mi;
			else lo = mi + 1;
		}
		cout << lo << endl;
	}
	return 0;
}
