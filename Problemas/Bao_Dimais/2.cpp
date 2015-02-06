// Filipe Nascimento, 2014

#include <stack>
#include <iostream>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		stack<unsigned int> s;
		for(int i = 0; i < n; i++){
			unsigned int u; 
			cin >> u;
			s.push(u);
		}
		while(!s.empty()){
			cout << s.top() << endl;
			s.pop();
		}
	}
	return 0;
}