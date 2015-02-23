#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int len;
char s[100001];
vector<int> pos[26];
int pd[100001];

int solve(int curr) {
	if (curr == len)	return 0;
	int &ans = pd[curr];
	if (ans == -1) {
		ans = solve(curr+1); // nao usa
		int x = s[curr]-'a';
		int npos = upper_bound(pos[x].begin(), pos[x].end(), curr)-pos[x].begin();
		if (npos != pos[x].size())	ans = max(ans, solve(pos[x][npos]+1)+1); // usa
	}
	return ans;
}

int main (void) {
	int i;
	while (scanf ("%d%s", &len, s) != EOF) {
		memset(pd, -1, sizeof pd);
		for (i = 0; i < 26; i++)	pos[i].clear();
		for (i = 0; i < len; i++) {
			pos[s[i]-'a'].push_back(i);
		}
		printf ("%d\n", solve(0));
	}
}