#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main (void) {
	int n, m, x;
	while (cin >> n >> m) {
		set<int> M;
		M.insert(0);
		for (int i = 0; i < n; ++i) {
			cin >> x;	
			vector <int> insert;
			for (set<int>::iterator it = M.begin(); it != M.end(); ++it) {
				insert.push_back(*it | x);
			}	
			for (int i = 0; i < insert.size(); ++i) {
				M.insert(insert[i]);
			}
		}
		for (int i = 0; i < m; ++i) {
			cin >> x;
			if (M.count(x)) cout << "Sim\n";
			else cout << "Nao\n";
		}
	}
	return 0;
}
