#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
#define LL long long
#define pb push_back
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 105;
char st1[qq], st2[qq];
int dp[qq][qq];
int vl[5][5] = {{5, -1, -2, -1, -3},
			{-1, 5, -3, -2, -4},
			{-2, -3, 5, -2, -2},
			{-1, -2, -2, 5, -1},
			{-3, -4, -2, -1, 0}};
int id[200];

int main(){
	id['A'] = 0, id['C'] = 1, id['G'] = 2, id['T'] = 3, id['-'] = 4;
	int t;	scanf("%d", &t);
	while(t--){
		int len1;	scanf("%d", &len1);
		scanf("%s", st1 + 1);
		int len2; 	scanf("%d", &len2);
		scanf("%s", st2 + 1);
		dp[0][0] = 0;
		for(int i = 1; i <= len1; ++i){
			dp[i][0] = dp[i - 1][0] + vl[id[st1[i]]][id['-']];
		}
		for(int j = 1; j <= len2; ++j){
			dp[0][j] = dp[0][j - 1] + vl[id['-']][id[st2[j]]];
		}
		for(int i = 1; i <= len1; ++i)
			for(int j = 1; j <= len2; ++j){
				dp[i][j] = dp[i - 1][j - 1] + vl[id[st1[i]]][id[st2[j]]];
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + vl[id[st1[i]]][id['-']]);
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + vl[id['-']][id[st2[j]]]);
			}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}