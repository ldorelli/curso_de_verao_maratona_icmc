#include <iostream>
#include <cstdlib>

using namespace std;

int main (void) {
	for (int i = 0; i < 30; ++i) {
		int n = rand()%12 + 1;
		cout << n << endl;	
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j) cout << rand()%10000000 + 1 << " ";
			cout << endl;
		}
	}
}
