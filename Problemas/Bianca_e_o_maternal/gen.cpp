#include <iostream>

using namespace std;

int main (void) {
	for (int i = 0; i < 200; ++i) {
		int n = rand()%500 + 500;
		cout << n << endl;
		for (int i = 0; i < n; ++i) {
			cout << rand()%11 << " " << rand()%n << endl;
		}
	}
}
