// Anderson Silva, 2014

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stack>

#define mp make_pair
using namespace std;

int main() {
	stack<int> s;
	char ch;
	
	while(scanf("%c", &ch) != EOF) {	

		if(ch == '\n') {	
			if(s.empty()) 
				printf("S\n");
			else 
				printf("N\n");

			while(!s.empty())
				s.pop();

		} else {
			if(!s.empty() && (s.top() == '(' && ch == ')'))
				s.pop();
			else
				s.push(ch);
		}
	}
	return 0;
}
