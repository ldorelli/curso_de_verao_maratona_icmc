#include <bits/stdc++.h>

using namespace std;

void gera(int n, int m, int maior)
{
	printf("%d %d\n",n,m);

	for (int i = 0; i < n; ++i)
	{
		printf("%d", rand()%maior + 1);
		if (i < n - 1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}

	for (int i = 0; i < m; ++i)
	{
		printf("%d\n", rand()%maior + 1);
	}
	printf("\n");
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 50; ++i)
		gera(10, 100, (1 << 29));

	for (int i = 0; i < 50; ++i)
		gera(10, 100, 1000000);

	printf("60 100000\n");
	for (int i = 1; i <= 60; ++i)
	{
		printf("%d",i);
		if (i == 60)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}

	for (int i = 1; i <= 100000; ++i)
	{
		printf("%d\n",i);
	}

	printf("60 100000\n");
	printf("1 ");
	for (int i = 101; i <= 159; ++i)
	{
		printf("%d",i);
		if (i == 159)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}

	for (int i = 1; i <= 100000; ++i)
	{
		printf("%d\n",i);
	}



	printf("60 100000\n");
	printf("1 ");
	for (int i = 1001; i <= 1059; ++i)
	{
		printf("%d",i);
		if (i == 1059)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}

	for (int i = 1; i <= 100000; ++i)
	{
		printf("%d\n",i);
	}


	printf("60 100000\n");
	printf("1 ");
	for (int i = 10001; i <= 10059; ++i)
	{
		printf("%d",i);
		if (i == 10059)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}

	for (int i = 1; i <= 100000; ++i)
	{
		printf("%d\n",i);
	}

	
	return 0;
}