#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 30

bool used[N];

char nomes[N][21] = {
	"Shi", //1
	"Rafael", //2
	"Denis", //3
	"Paulo", //4
	"Miguel", //5
	"Joaquim", //6
	"Eduardo", //7
	"Valerio", //8
	"Manoel", //9
	"Joao", //10
	"Jose", //11
	"Mario", //12
	"Bruno", //13
	"Carlos", //14
	"Ricardo", //15
	"Romeu", //16
	"Romario", //17
	"Ronaldo", //18
	"Caio", //19
	"Carlito", //20
	"Anisio", //21
	"Alceu", //22
	"Americo", //23
	"Armando", //24
	"Diego", //25
	"Romulo", //26
	"Silvio", //27
	"Sena", //28
	"Bill", //29
	"Pikachu" //30
};

int main (void) {
	int t = 10, c, i;
	srand(time(NULL));
	int fat[11];
	fat[0] = 1;
	for (i = 1; i < 11; i++)	fat[i] = i*fat[i-1];
	for (c = 0; c < t; c++) {
		int n = 10;
		printf ("%d %d\n", n, rand()%fat[n]+1);
		memset(used, 0, sizeof used);
		for (i = 0; i < n; i++) {
			int curr = rand()%N;
			while (used[curr])	curr = rand()%N;
			used[curr] = true;
			printf ("%s ", nomes[curr]);
		}
		printf ("\n");
	}
}
