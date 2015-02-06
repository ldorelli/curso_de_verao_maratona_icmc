// Anderson Silva, 2014

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int n, k, d, ni;

	while(cin >> n >> k >> d) {
		int auxk = k, auxd = d;

		for(int i =0; i < n;i++) {
			cin >> ni;
			auxk--;
			
			if(auxd > 0) {
				cout << ni << endl;
				auxd--;
			}

			if(auxk == 0) {
				auxk = k;
				auxd = d;
			}
		}
	}

	return 0;
}