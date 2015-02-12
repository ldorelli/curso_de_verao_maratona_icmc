#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define MAX 100000

using namespace std;

int main (void) {
	int t = 250, c;
	int n, i, j;
	srand(time(NULL));
	for (c = 0; c < t; c++) {
		vector<int> v[4];
		for (j = 0; j < 4; j++) {
			int n = 25;
			for (i = 0; i < n; i++) {
				v[j].push_back(rand()%(2*MAX+1)-MAX);
			}
		}
		if(!(rand()%3)) {
			printf ("%d\n", v[0][rand()%v[0].size()] + v[1][rand()%v[1].size()] + v[2][rand()%v[2].size()] + v[3][rand()%v[3].size()]);
		} else {
			printf ("%d\n", rand()%(2*MAX+1)-MAX);
		}
		for (j = 0; j < 4; j++) {
			printf ("%d ", v[j].size());
			for (i = 0; i < v[j].size(); i++) {
				printf ("%d ", v[j][i]);
			}
			printf ("\n");
		}
	}
}
