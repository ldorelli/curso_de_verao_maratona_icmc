#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int pai[200];
int main (void) {
	int n;
	char n1[21], n2[21];
	int i;
	while(scanf ("%d", &n) != EOF) {
		map<string, int> m;
		int cnt = 0;
		for (i = 0; i < n-1; i++) {
			scanf ("%s%s", n1, n2);
			if (!m.count(string(n1))) {
				m[string(n1)] = cnt++;
			}
			if (!m.count(string(n2))) {
				m[string(n2)] = cnt++;
			}
			pai[m[string(n1)]] = m[string(n2)];
		}
		scanf ("%s%s", n1, n2);
		int ger = 0, curr = m[string(n1)], end = m[string(n2)];
		while (curr != end)	curr = pai[curr], ger++;
		if (ger == 1)	printf ("pai\n");
		else if (ger == 2)	printf ("avo\n");
		else if (ger == 3)	printf ("bisavo\n");
		else {
			for (i = 3; i < ger; i++) {
				printf ("tatara");
			}
			printf ("vo\n");
		}
	}
}
