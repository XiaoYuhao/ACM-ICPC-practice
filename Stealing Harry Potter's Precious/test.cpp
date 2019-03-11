#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
#include<vector>
#include<functional>
using namespace std;
const int MAX = 110;
const int INF = 0x3f3f3f3f;
char maps[MAX][MAX];
int n, m, k;
int mi[20][MAX][MAX];
int a[MAX][MAX];

struct Sta{
	int x, y;
	int step;
	int num;
	int mcord[4];
	int status;
};

bool operator >(const Sta &a, const Sta &b) {
	return a.step > b.step;
}
bool operator <(const Sta &a, const Sta &b) {
	return a.step < b.step;
}

int mv[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };


int bfs(int sx,int sy,int sta) {
	priority_queue<Sta, vector<Sta>, greater<Sta> > q;
//	queue<Sta> q;
	Sta start;
	start.x = sx;
	start.y = sy;
	start.step = 0;
	start.num = 0;
	start.status = sta;
/*	for (int i = 0; i < cord.size(); i++) {
		start.mcord[i] = 0;
		if (make_pair(sx, sy) == cord[i]) {
			start.num++;
			start.mcord[i] ++;
		}
	}*/
	q.push(start);

	int res = -1;

	while (!q.empty()) {
		Sta sa, snext;
		sa = q.top();
		q.pop();
		if (sa.num==k) {
			res = sa.step;
			break;
		}
		int x, y;

		for (int i = 0; i < 4; i++) {
			x = sa.x + mv[i][0];
			y = sa.y + mv[i][1];
			if (x<1 || x>m || y<1 || y>n)continue;
			if (maps[x][y] == '#')continue;
			snext.x = x;
			snext.y = y;
			snext.step = sa.step + 1;
			snext.num = sa.num;
			snext.status = sa.status;			
			if ((sa.status&a[x][y]) == 0) {
				snext.status = sa.status^a[x][y];
				if (a[x][y] != 0) {
					snext.num++;
				}
			}
			if (snext.step < mi[snext.status][x][y]) {
				q.push(snext);
				mi[snext.status][x][y] = snext.step;
			}
			
			
		}
	}
	return res;
}

int main() {
	while (1) {
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		memset(mi, 0, sizeof(mi));
		if (n == 0 || m == 0)break;
		for (int i = 1; i <= n; i++) {
			scanf("%s", &maps[i][1]);
		}
		scanf("%d", &k);
		int sx, sy;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (maps[i][j] == '@') {
					sx = i;
					sy = j;
				}
				if (maps[i][j] == '#') {
					a[i][j] = -1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int p = 0; p < (1 << k); p++) {
					mi[p][i][j] = INF;
				}
			}
		}
		int x, y, sta = 0;
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &x, &y);
			a[x][y] = (1 << i);
			if (x == sx&&y == sy) {
				sta = (1 << i);
				mi[sta][x][y] = 0;
			}
		}
		if (sta == 0) {
			mi[0][sx][sy] = 0;
		}
		int ans = bfs(sx, sy, sta);
		printf("%d\n", ans);
	}
	return 0;
}

//×´Ì¬Ñ¹Ëõ+bfsËÑË÷