#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pb push_back
#define mk make_pair
#define mst(a, b)	memset(a, b, sizeof(b))
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 1e5 + 10;
int n;
int num[qq];
int dp[qq];

int main(){
	int t;	scanf("%d", &t);
	int Case = 1;
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%d", num + i);
		}
		dp[1] = num[1];
		int l, r; l = r = 1;
		int maxn = dp[1];
		int t1, t2;
		t1 = t2 = 1;
		for(int i = 2; i <= n; ++i){
			if(dp[i - 1] + num[i] >= num[i]){
				dp[i] = dp[i - 1] + num[i];
				r = i;
			}else{
				dp[i] = num[i];
				l = r = i;
			}
			if(dp[i] >	maxn){
				maxn = dp[i];
				t1 = l, t2 = r;
			}
		}
		printf("Case %d:\n%d %d %d\n", Case++, maxn, t1, t2);
		if(t)	puts("");
	}
	return 0;
}