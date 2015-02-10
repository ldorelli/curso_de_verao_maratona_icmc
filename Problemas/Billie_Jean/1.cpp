#include <cstdio>

const int N = 101;

char in[N];

int main()
{
	while (scanf("%s", in) == 1)
	{
		int a = 0, b = 0;
		for (int i = 0; in[i]; ++i)
		{
			if (in[i] >= 'a' && in[i] <= 'z') ++a;
			else ++b;
		}
		if (a >= b) printf("But The Kid Is Not My Son\n");
		else printf("She Says I Am The One\n");
	}
}

