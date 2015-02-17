#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 12;
int m[12][12];
int n;

int funciona (int mid, int mask) {
	int cnt = __builtin_popcount(mask);
	cnt--;
	int menores = 0;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		if (((mask>>i)&1) == 0) continue;
		total += 60 * 60;
		int base = m[i][cnt];
		int end = base + 60 * 60 - 1;
		if (base <= mid) {
			if (mid <= end) menores += mid - base;
			else menores += end - base + 1;
		}
	}
	return menores >= total/2;
}



bool possivel (int mid) {
	for (int mask = 1; mask < (1<<n); ++mask) {
		if (!funciona(mid, mask)) return false;
	}
	return true;
}

int main (void) {
	while (cin >> n) {
		int lo = 0;
		int hi = 30000008;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> m[i][j];
		}
	
		while (lo < hi) {
			int mid = (lo + hi)/2;
			if (possivel(mid)) hi = mid;
			else lo = mid + 1;
		}
		cout << lo << endl;
	}
	return 0;
}