// Filipe Nascimento, 2014

#include<cstdio>

int main(){
	int n, I, min, m;
	while(scanf("%d%d",&n,&I) != EOF){
		scanf("%d",&min);
		for(int i = 1; i < n; i++){
			scanf("%d",&m);
			if(m < min) 
				min = m;
		}
		if(min < I) puts("N");
		else puts("S");
	}
	return 0;
}