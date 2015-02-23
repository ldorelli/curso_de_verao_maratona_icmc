#include <iostream>
#include <cstdio>

using namespace std;
const int MX = 1000000000;
int main (void) {
	int C = 20;
	for (int i = 0; i < C/2; ++i) {
		int n = rand()%8 + 1;
		int m = rand()%100 + 1;
		int d = rand()%MX;
		cout << n << " " << m << " " << d << endl;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) cout << rand()%MX << " ";	
			cout << endl;
		}
	}
	for (int i = 0; i < C/2; ++i) {
		int n = rand()%8 + 1;
		int m = rand()%100 + 1;
		int d = rand()%200;
		cout << n << " " << m << " " << d << endl;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) cout << rand()%300 << " ";	
			cout << endl;
		}
	}
	for (int i = 0; i < C/2; ++i) {
		int n =  8;
		int m = 100;
		int d = 50;
		cout << n << " " << m << " " << d << endl;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) cout << rand()%1000 << " ";	
			cout << endl;
		}
	}
	for (int i = 0; i < C/2; ++i) {
		int n =  8;
		int m = 100;
		int d = 1000;
		cout << n << " " << m << " " << d << endl;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) cout << rand()%1000 << " ";	
			cout << endl;
		}
	}
	return 0;
}
