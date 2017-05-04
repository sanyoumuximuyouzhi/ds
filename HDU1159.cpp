#include <bits/stdc++.h>

using namespace std;
const int qq = 1005;
char a[qq], b[qq];
int dp[qq][qq];

int main(){

	while(scanf("%s%s", a + 1, b + 1) != EOF){
		memset(dp, 0, sizeof dp);
		int maxn = 0;
		for(int i = 1; i <= (int)strlen(a + 1); ++i)
			for(int j = 1; j <= (int)strlen(b + 1); ++j){
				if(a[i] == b[j]){
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}else{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				maxn = max(maxn, dp[i][j]);
			}
		printf("%d\n", maxn);
	}
	return 0;
}