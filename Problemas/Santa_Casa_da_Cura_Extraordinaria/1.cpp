// Bianca Oe, 2015

#include <stdio.h>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;

int main (void) {
	int n, i;
	char cmd[2], name[11];
	int age;
	while (scanf ("%d", &n) != EOF) {
		priority_queue<pair<int, int> > pq;
		for (i = 0; i < n; i++) {
			scanf ("%s", cmd);
			if (cmd[0] == 'A') {
				printf ("%d\n", pq.top().second);
				pq.pop();
			} else {
				scanf ("%s%d", name, &age);
				if (strcmp(name, "Denis"))	pq.push(make_pair(age, age));
				else	pq.push(make_pair(1000, age));
			}
		}
	}
}
