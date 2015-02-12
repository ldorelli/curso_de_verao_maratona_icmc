#include <iostream>
#include <algorithm>

using namespace std;

int to[1001];
int score[1001];
bool vis[1001];

double calcscore(int childn){
	if(vis[childn]){
		return score[childn];
	}else{
		vis[childn] = 1;
		return (double)(score[childn] + calcscore(to[childn]))/2;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> score[i] >> to[i];
		}

		double mx = 0;
		int mxchild = 0;
		for(int i = 0; i < n; i ++){
			memset(vis, 0, sizeof(int)*n);
			double ans = calcscore(i);
			if(ans > mx){
				mx = ans;
				mxchild = i;
			}
		}

		printf("%.3lf %d\n", mx, mxchild);
	}
	
    return 0;
}