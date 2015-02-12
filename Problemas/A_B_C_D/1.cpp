// Bianca Oe, 2015

#include <stdio.h>
#include <vector>

using namespace std;

int main (void) {
	int e;
	while (scanf ("%d", &e) != EOF) {
		vector<int> listas[4];
		int i, j, k, l, x, n;
		bool ok = false;
		for (i = 0; i < 4; i++) {
			scanf ("%d", &n);
			for (j = 0; j < n; j++) {
				scanf ("%d", &x);
				listas[i].push_back(x);
			}
		}
		for (i = 0; i < listas[0].size() && !ok; i++) {
			for (j = 0; j < listas[1].size() && !ok; j++) {
				for (k = 0; k < listas[2].size() && !ok; k++) {
					for (l = 0; l < listas[3].size() && !ok; l++) {
						if (listas[0][i] + listas[1][j] + listas[2][k] + listas[3][l] == e)	ok = true;
					}
				}
			}
		}
		if (ok)	printf ("S\n");
		else	printf ("N\n");
	}
}
