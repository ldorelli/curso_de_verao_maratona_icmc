#include <bits/stdc++.h>

using namespace std;

string vdir[4] = {"Esquerda", "Direita", "Cima", "Baixo"};

void gera(int n)
{
	int k = rand()%n + 1;

	cout << n << " " << k << "\n";
	for (int i = 0; i < n; ++i)
	{
		int x = rand()%1000000000 + 1;
		int y = rand()%1000000000 + 1;
		int dir = rand()%4;
		int qnt = rand()%1000000000 + 1;
		cout << x << " " << y << " " << vdir[dir] << " " << qnt << "\n";
	}
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 50; ++i)
	{
		gera(rand()%9 + 1);
	}

	for (int i = 0; i < 100; ++i)
		gera(9);


	return 0;
}