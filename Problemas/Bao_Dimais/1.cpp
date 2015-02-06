// Anderson Silva, 2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main () {

	stack<int> s;
	int n, x;

	while(cin >> n) {
		while(n--) 
			cin >> x, s.push(x);

		while(!s.empty())
			cout << s.top() << endl, s.pop();
	}

	return 0;
}
