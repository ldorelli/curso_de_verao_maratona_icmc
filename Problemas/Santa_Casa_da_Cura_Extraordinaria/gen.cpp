#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
	int t = 50, c, n = 100000, i, cmd;
	int cntPacientes;
	bool podeDenis;
	srand(time(NULL));
	for (c = 0; c < t; c++) {
		printf ("%d\n", n);
		cntPacientes = 0;
		podeDenis = 1;
		for (i = 0; i < n; i++) {
			if (cntPacientes)	cmd = rand()%3;
			else	cmd = 1;
			if (!cmd) {
				printf ("A\n");
				cntPacientes--;
				podeDenis = 1;
			} else {
				if (podeDenis && !(rand()%10)) {
					printf ("C Denis %d\n", rand()%100);
					podeDenis = 0;
				} else	printf ("C P%d %d\n", i, rand()%100);
				cntPacientes++;
			}
		}
	}
	return 0;
}
