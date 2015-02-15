#include <bits/stdc++.h>

using namespace std;

void gen(int n, int m)
{
	cout << n << " " << m << "\n";

	for (int i = 0; i < n; ++i)
	{
		printf("%d", rand()%1000000000);
		if (i == n - 1)
		{
			printf("\n");
		}
		else
			printf(" ");
	}

	for (int i = 0; i < m; ++i)
	{
		printf("%d", rand()%1000000000);
		if (i == m - 1)
		{
			printf("\n");
		}
		else
			printf(" ");
	}
}
int main(void)
{
	srand(time(NULL));
	// for (int i = 0; i < 100; ++i)
	// {
	// 	gen(1000, 1000);
	// }
	// for (int i = 0; i < 10; ++i)
	// {
	// 	gen(10000, 10000);
	// }

	// for (int i = 0; i < 8; ++i)
	// {
	// 	gen(100000, 100000);
	// }

	// gen(1,1);
	// gen(2,1);
	// gen(1,2);

	printf("100000 100000\n");
	for (int i = 0; i < 100000; ++i)
	{
		printf("1000000000");
		if (i == 100000 - 1)
		{
			printf("\n");
		}
		else
			printf(" ");
	}
	
	for (int i = 0; i < 100000; ++i)
	{
		printf("1000000000");
		if (i == 100000 - 1)
		{
			printf("\n");
		}
		else
			printf(" ");
	}
	return 0;
}