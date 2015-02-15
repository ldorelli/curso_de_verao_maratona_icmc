#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct fly
{
	int use, get;
	
	bool operator < (const fly& b) const {
		return get - use > b.get - b.use;
	}
};

int main(void)
{
	int n;
	int f;
	while(cin >> n >> f)
	{
		vector<fly> v(n);
		
		for (int i = 0; i < n; ++i)
			cin >> v[i].use;
		for (int i = 0; i < n; ++i)
			cin >> v[i].get;
		
		sort (v.begin(), v.end());

		int res = 0;
		
		for (int i = 0; i < v.size(); ++i)
		{
			if (f - v[i].use + v[i].get < 0) break;
			f = f - v[i].use + v[i].get;
			++res;
		}
		
		cout << res << endl;
	}
	return 0;
}