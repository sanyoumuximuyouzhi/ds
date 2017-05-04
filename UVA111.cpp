#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 35;
int id[qq], t[qq];
int num[qq];
int dp[qq];

int main(){
	int n;	scanf("%d", &n);
	REP(i, 0, n){
		int x;	scanf("%d", &x);
		id[x] = i + 1;
	}
	for(int i = 1; i <= n; ++i)
		t[id[i]] = i;
	int x;
	while(scanf("%d", &x) != EOF){
		num[x] = 1;
		REP(i, 1, n){
			scanf("%d", &x);
			num[x] = i + 1;
		}
		for(int i = 1; i <= n; ++i){
			num[i] = t[num[i]];
		}
		int len = 0;
		int maxn = 1;
		for(int i = 1; i <= n; ++i){
			if(len == 0){
				dp[len++] = num[i];
				continue;
			}
			if(dp[len - 1] < num[i]){
				dp[len++] = num[i];
			}else{
				int k = lower_bound(dp, dp + len, num[i]) - dp;
				dp[k] = num[i];
			}
			maxn = max(maxn, len);
		}
		printf("%d\n", maxn);
	}
	return 0;
}