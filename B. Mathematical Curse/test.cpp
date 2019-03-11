#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
const int MAX = 1010;
const int INF = 0x3f3f3f3f;
typedef long long ll;
struct Num {
	int id;
	int val;
}num[MAX], num2[MAX];
int a[MAX];
ll dp[MAX][MAX];
char ch[MAX];
char f[MAX];

bool cmp(Num a, Num b) {
	return a.val > b.val;
}
bool cmp2(Num a, Num b) {
	return a.id < b.id;
}

ll solve(ll le, char c, ll ri) {
	if (c == '+') return le + ri;
	if (c == '-') return le - ri;
	if (c == '*') return le*ri;
	if (c == '/') return le / ri;
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &num[i].val);
			num[i].id = i;
		}

		sort(num + 1, num + n + 1, cmp);
		int cnt = 1;
		for (int i = 1; i <= m*50; i++) {
			num2[cnt].id = num[i].id;
			num2[cnt++].val = num[i].val;
			num2[cnt].id = num[n - i + 1].id;
			num2[cnt++].val = num[n - i + 1].val;
		}
		sort(num2 + 1, num2 + cnt, cmp2);
		
		int last = 0;
		int cntn = 1;
		for (int i = 1; i < cnt; i++) {
			if (num2[i].id != last) {
				a[cntn++] = num2[i].val;
				last = num2[i].id;
			}
		}

		scanf("%s", ch);
		for (int i = 1; i <= m; i++) {
			f[i] = ch[i - 1];
		}
		for (int i = 0; i <= cntn; i++) {
			for (int j = 0; j <= m; j++) {
				dp[i][j] = -INF;
			}
		}
		dp[0][0] = k;
		for (int i = 1; i < cntn; i++) {
			for (int ii = 0; ii < i; ii++) {
				for (int j = 0; j <= m; j++) {
					if (ii < j)continue;
					if (dp[ii][j] != -INF) {
						dp[i][j + 1] = max(dp[i][j + 1], solve(dp[ii][j], f[j + 1], a[i]));
					}
				}
			}
		}

		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, dp[i][m]);
		}
		printf("%lld\n", ans);
	}
}

/*
20 4 5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20


80 4 5
1 2 3 14 5 6 17 8 9 10 6 12 13 4 15 6 17 18 9 20 1 2 3 14 5 6 17 8 9 10 6 12 13 4 15 6 17 18 9 20 1 2 3 14 5 6 17 8 9 10 6 12 13 4 15 6 17 18 9 20 1 2 3 14 5 6 17 8 9 10 6 12 13 4 15 6 17 18 9 20 1 2 3 14 5 6 17 8 9 10 6 12 13 4 15 6 17 18 9 20 1 2 3 14 5 6 17 8 9 10 6 12 13 4 15 6 17 18 9 20 1 2 3 14 5 6 17 8 9 10 6 12 13 4 15 6 17 18 9 20 1 2 3 14 5 6 17 8 9 10 6 12 13 4 15 6 17 18 9 20
**--
*/