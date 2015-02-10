// Filipe Nascimento, 2014

#include <cstdio>

int main(){
	int n, k, d;
	while(scanf("%d%d%d",&n,&k,&d) != EOF){
		int c = 0;
		for (int i = 0; i < n; ++i)
		{
			unsigned int m;
			scanf("%u", &m);
			if(c < d) 
				printf("%u\n",m);
			c = (c+1)%k;
		}
	}
	return 0;
}