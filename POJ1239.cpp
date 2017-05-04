#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define LL long long
#define pb push_back
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i < n; ++i)
const int qq = 105;
char sa[qq];
int dp[qq];

bool Judge(int i, int j, int a, int b){
	while(sa[i] == '0' && i <= j)	i++;
	while(sa[a] == '0' && a <= b)	a++;
	if(i > j)	return false;
	if(a > b)	return false;
	if(j - i > b - a)	return true;
	else if(j - i < b - a)	return false;
	else{
		int t1, t2;
		for(t1 = i, t2 = a; t1 <= j && t2 <= b; ++t1, ++t2){
			if(sa[t1] > sa[t2])	return true;
			if(sa[t2] > sa[t1])	return false;
		}
	}
	return false;
}

int main(){
	while(scanf("%s", sa + 1) != EOF){
		int n = strlen(sa + 1);
		if(n == 1 && sa[1] == '0')	break;
		dp[1] = 1;
		for(int i = 2; i <= n; ++i){
			dp[i] = i;
			for(int j = i - 1; j >= 1; --j){
				if(Judge(j + 1, i, j - dp[j] + 1, j)){
					dp[i] = i - j;
					break;
				}
			}
		}
		int len = n - dp[n] + 1;
		dp[len] = dp[n];
		for(int i = len - 1; i >= 1; --i){
			if(sa[i] == '0'){
				dp[i] = dp[i + 1] + 1;
				continue;
			}
			for(int j = len; j > i; --j){
				if(Judge(j, j + dp[j] - 1, i, j - 1)){
					dp[i] = j - i;
					break;
				}
			}
		}
		for(int i = 1; i <= dp[1]; ++i)
			putchar(sa[i]);
		int k = 1 + dp[1];
		while(k <= n){
			putchar(',');
			for(int i = k; i < k + dp[k]; ++i)
				putchar(sa[i]);
			k = k + dp[k];
		}
		puts("");
	}
	return 0;
}