#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void gen(int wmax, int nmax) {
	int n = rand()%nmax+1;
	printf ("%d %d\n", (rand()%wmax+1)*1000+rand()%1000, n);
	for (int i = 0; i < n; i++) {
		printf ("%d %d\n", (rand()%wmax+1)*1000, rand()%100+1);
	}
}

int main (void) {
	srand(time(NULL));
	gen(10, 10);
	gen(20, 15);
	gen(100, 100);
	for (int i = 0; i < 50; i++) {
		gen(1000, 1000);
	}
}