// Filipe Nascimento, 2014

#include <string>
#include <set>
#include <iostream>

using namespace std;

int main(){
	set<string> d;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		d.insert(a);
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		if(d.find(a) != d.end())
			cout << "S\n";
		else cout << "N\n";
	}
	return 0;
}