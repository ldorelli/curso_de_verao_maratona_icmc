// Filipe Nascimento, 2014

#include<stdio.h>

int main(){
	
	char str[10010];
	while(scanf(" %s ", str) != EOF){
		int c = 0;
		for(int i = 0; str[i]; i++){
			if(str[i] == '(')
				c++;
			else
				c--;
			if(c < 0) break;
		}
		if(!c) puts("S");
		else puts("N");
	}

	return 0;
}