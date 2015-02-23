#include <iostream>

using namespace std;

int main (void) {
	for (int i = 0; i < 25; ++i) {
		int n = rand()%100;
		cout << n << endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j) cout << (1 + rand()%256) << " ";
			cout << endl;
		}
	}
	return 0;
}
