// Anderson Silva, 2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>

#define mp make_pair
using namespace std;

	map<string, int> m;
	map<string, int>::iterator it;
	char str[255];

int main() {

	int n;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", str);
		m.insert(mp(str, 0));
	}

	scanf("%d", &n);
	while(n--) {
		scanf("%s", str);
		if(m.find(str) != m.end())
			printf("S\n");
		else 
			printf("N\n");
	}
}
		
