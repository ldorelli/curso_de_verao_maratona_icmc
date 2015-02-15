// Bianca Oe, 2015

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main (void) {
	int n, i, m;
	string names[10];
	char name[21];
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		vector<int> ind(10);
		for (i = 0; i < n; i++) {
			cin >> names[i];
			ind[i] = i;
		}
		sort(names, names+n);

		for (i = 1; i < m; i++) {
			next_permutation(ind.begin(), ind.begin()+n);
		}
		
		for (i = 0; i < n; i++) {
			cout << names[ind[i]] << " ";
		}
		cout << "\n";
	}
}
