#include <bits/stdc++.h>

using namespace std;
#define mst(a, b)	memset(a, b, sizeof(a))
const int qq = 105;
char a[qq], b[qq];
int dp[qq][qq];
int pre[qq][qq];
int spx[] = {-1, 0, -1};
int spy[] = {-1, -1, 0};
int sa[qq], sb[qq];
char ans[5 * qq];

int main(){
	while(scanf("%s%s", a + 1, b + 1) != EOF){
		mst(pre, -1), mst(dp, 0);
		for(int i = 1; i <= (int)strlen(a + 1); ++i)
			for(int j = 1; j <= (int)strlen(b + 1); ++j)
				if(a[i] == b[j]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
					pre[i][j] = 0;
				}else{
					if(dp[i - 1][j] < dp[i][j - 1]){
						dp[i][j] = dp[i][j - 1];
						pre[i][j] = 1;
					}else{
						dp[i][j] = dp[i - 1][j];
						pre[i][j] = 2;
					}
				}
		int x, y;
		x = strlen(a + 1), y = strlen(b + 1);
		sa[0] = x + 1, sb[0] = y + 1;
		int cnt = 1;
		while(pre[x][y] != -1){
			if(a[x] == b[y]){
				sa[cnt] = x;
				sb[cnt] = y;
				cnt++;
			}
			int tmp = pre[x][y];
			x = x + spx[tmp];
			y = y + spy[tmp];
		}
		sa[cnt] = sb[cnt] = 0;
		int k = 0;
		for(int i = cnt - 1; i >= 0; --i){
			for(int j = sa[i + 1] + 1; j < sa[i]; ++j)
				ans[k++] = a[j];
			for(int j = sb[i + 1] + 1; j < sb[i]; ++j)
				ans[k++] = b[j];
			ans[k++] = a[sa[i]];
		}
		ans[k] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}