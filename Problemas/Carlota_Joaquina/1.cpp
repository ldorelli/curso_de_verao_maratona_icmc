#include <cstdio>

int main()
{
	int n;
	
	while (scanf("%d", &n) == 1)
	{
		if (n%2 == 0) printf("PAR\n");
		else printf("IMPAR\n");
	}
}

