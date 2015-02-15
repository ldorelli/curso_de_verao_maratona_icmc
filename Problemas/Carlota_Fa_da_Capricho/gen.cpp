#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
	{
		int n = 1+rand()%10000;
		cout << n << " " << 1+rand()%1000000000 << "\n"; 
		for (int j = 0; j < n; ++j)
			cout << 1+rand()%10000 << " ";
		cout << "\n";
	}
	return 0;
}