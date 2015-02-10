// Filipe Nascimento, 2014

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main(){
	char t[20];
	int n, id;
	while(scanf("%d",&n) != EOF){
		queue<unsigned int> q;
		for(int i = 0; i < n; i++){
			scanf(" %s ", t);
			if(t[0] == 'C'){
				scanf("%d", &id);
				q.push(id);
				cout << q.size() << endl;
			}
			else{
				if(!q.empty()){
					cout << q.front() << endl;
					q.pop();
				}
				else cout << "0\n";
			}
		}

	}
	return 0;
}