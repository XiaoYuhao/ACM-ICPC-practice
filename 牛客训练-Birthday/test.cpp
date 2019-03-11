#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;

const int MAX = 100;
const int INF = 0x3f3f3f3f;
//int dp[MAX];
//int num[MAX];
int a[MAX], b[MAX];
int n, m;


struct Sta {
	int num[55];
	int ms() {
		int res = 0;
		for (int i = 1; i <= m; i++) {
			res += num[i] * num[i];
		}
		return res;
	}
	int keys() const {
		int res = 0;
		for (int i = 1; i <= m; i++) {
			
			res += i*i*i * num[i] * num[i] + 50000 * i;
			//if (num[i])res += num[i] + 500 * i*i;
		}
		return res;
	}
}dp[10010];

map<Sta, int> mst;

bool operator <(const Sta &sa, const Sta &sb) {
	return sa.keys() < sb.keys();
}

bool operator >(const Sta &sa, const Sta &sb) {
	return sa.keys() > sb.keys();
}
int minss = INF;

int dfs(int i,Sta sa) {
	if (i > n) { 
		if (sa.ms() < minss) {
			minss = sa.ms();
		}
		return minss;
	}
	if (mst.find(sa) != mst.end()) {
		return mst[sa];
	}
	if (sa.ms() > minss) {
		return minss;
	}
	int min1 = 0, min2 = 0;
	sa.num[a[i]]++;
	min1 = dfs(i + 1, sa);
	sa.num[a[i]]--;
	sa.num[b[i]]++;
	min2 = dfs(i + 1, sa);
	sa.num[b[i]]--;
	mst[sa]= min(min1, min2);
	return min(min1, min2);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	Sta start;
	for (int i = 0; i < 55; i++) {
		start.num[i] = 0;
	}
	int ans = dfs(1, start);
	printf("%d\n", ans);
	return 0;
}

/*
50 50
1 2
2 3
3 4
5 6
6 7
7 8
8 9
9 10
11 12
13 14
15 16
17 18
19 20
21 22
23 24
25 26
1 2
2 3
3 4
5 6
6 7
7 8
8 9
9 10
11 12
13 14
15 16
17 18
19 20
21 22
23 24
25 26
1 2
2 3
3 4
5 6
6 7
7 8
8 9
9 10
11 12
13 14
15 16
17 18
19 20
21 22
23 24
25 26
1 2
2 3


5 50
1 3
5 19
6 26
1 3
1 3

9 5
1 3
1 3
1 3
2 4
2 4
2 4
1 5
1 5
1 5
*/