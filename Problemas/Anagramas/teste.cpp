#include <vector>
#include <iostream>

using namespace std;

int main (void) {
	vector<int> v(10);
	vector<int>::iterator it;
	cout << v.end()-v.begin() << endl;
}
