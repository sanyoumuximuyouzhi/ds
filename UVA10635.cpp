#include <bits/stdc++.h>

using namespace std;
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 250 * 250 + 10;
int a[qq], b[qq], ans[qq];
int id[qq];

int main(){
	int t;	scanf("%d", &t);
	int Case = 1;
	while(t--){
		mst(id, 0), mst(ans, 0);
		int n, p, q;	scanf("%d%d%d", &n, &p, &q);
		p++, q++;
		REP(i, 0, p){
			scanf("%d", a + i);
			id[a[i]] = i + 1;
		}
		REP(i, 0, q){
			scanf("%d", b + i);
			b[i] = id[b[i]];
		}
		int len = 0;
		int maxn = -1;
		REP(i, 0, q){
			if(b[i] == 0)	continue;
			if(len == 0){
				ans[len++] = b[i];
				maxn = max(maxn, len);
				continue;
			}
			if(ans[len - 1] > b[i]){
				ans[len++] = b[i];
			}else{
				int k = lower_bound(ans, ans + len, b[i]) - ans;
				ans[k] = b[i];
			}
			maxn = max(maxn, len);
		}
		printf("Case %d: %d\n", Case++, maxn);
	}
	return 0;
}