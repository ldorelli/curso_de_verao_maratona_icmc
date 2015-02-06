#include <cstdio>

const int N = 100;

int vet[N];

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &vet[i]);
		int r = 0;
		for (int i = 0; i < n && !r; ++i)
		{
			for (int j = 0; j < n && !r; ++j)
			{
				if (j == i) continue;
				if (vet[i] == vet[j]) r = 1;
			}
		}
		if (r == 1) printf("S\n");
		else printf("N\n");
	}
}

