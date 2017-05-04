#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pb push_back
#define mst(a, b)	memset(a, b, sizeof(a))
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 1005;
int num[qq];
LL dp[qq];

int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		REP(i, 0, n){
			scanf("%d", num + i);
		}
		dp[0] = num[0];
		REP(i, 1, n){
			dp[i] = num[i];
			REP(j, 0, i + 1){
				if(num[i] > num[j]){
					dp[i] = max(dp[i], dp[j] + num[i]);
				}
			}
		}
		LL maxn = -1;
		REP(i, 0, n){
			maxn = max(maxn, dp[i]);
		}
		printf("%I64d\n", maxn);
	}
	return 0;
}