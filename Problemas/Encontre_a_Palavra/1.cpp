#include <cstdio>

const int N = 1001;

char vet[N];

int main()
{
	while (scanf("%s", vet) == 1)
	{
		int r = 0;
		for (int i = 0; vet[i]; ++i)
		{
			r += vet[i]-'0';
		}
		printf("%d\n", r%3);
	}	
}
