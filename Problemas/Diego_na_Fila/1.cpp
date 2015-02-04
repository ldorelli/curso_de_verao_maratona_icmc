// Anderson Silva, 2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main () {
	priority_queue <int> s;
	int n, i, x;

	while(cin >> n >> i) {
		while(n--)
			cin >> x, s.push(x);

		while(!s.empty())
			x = s.top(), s.pop();

		if(x >= i)
			printf("S\n");
		else
			printf("N\n");
	}

	return 0;
}
