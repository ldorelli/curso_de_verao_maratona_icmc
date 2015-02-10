// Anderson Silva, 2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main () {
	
	int n, x;
	char str[255];

	while(cin >> n) {
		queue <int> s;
		for(int i = 0; i < n; i++) {
			cin >> str;

			if(str[0] == 'C'){
				cin >> x;
				s.push(x), cout << s.size() << endl;
			}
			else {
				if(s.empty())
					printf("0\n");
				else printf("%d\n", s.front()), s.pop();
			}
		}
	}

	return 0;
}
