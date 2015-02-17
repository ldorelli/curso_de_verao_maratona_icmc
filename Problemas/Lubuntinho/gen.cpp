#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int pai[200];

void gen(int n) {
	memset(pai, 0, sizeof pai);
	printf ("%d\n", n);
	for (int i = 1; i < n; i++) {
		pai[i] = rand()%i;
		printf ("%d %d\n", i, pai[i]);
	}
	int des = rand()%(n-1)+1, as = des;
	int cntmax = 6;
	int cnt = rand()%cntmax + 1;
	for (int i = 0; i < cnt; i++) {
		as = pai[as];
	}
	printf ("%d %d\n", des, as);
}

int main (void) {
	srand(time(NULL));
	gen(5);
	printf ("\n");
	gen(10);
	printf ("\n");
	gen(15);
	for (int i = 0; i < 50; i++) {
		gen(200);
		printf ("\n");
	}
}
