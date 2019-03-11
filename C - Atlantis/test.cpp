#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

const int MAX = 100010;
const int INF = 99999999;

struct hp {
	int x1, x2, flag;
	double y;
}dat[MAX<<1];
int dat_num;

struct lsh {
	double x;
	int id;
}X[MAX<<1];
int x_num;

bool cmp1(lsh a, lsh b) {
	return a.x < b.x;
}

bool cmp2(hp a, hp b) {
	return a.y < b.y;
}

double dis[MAX << 1];

struct node {
	int l, r, lc, rc, cnt;
	double sm;
}tr[MAX<<1];
int len;

int build(int l, int r) {
	int x = ++len;
	tr[x].l = l;
	tr[x].r = r;
	tr[x].sm = 0;
	tr[x].cnt = 0;
	if (l < r - 1) {
		int mid = (tr[x].l + tr[x].r) >> 1;
		tr[x].lc = build(l, mid);
		tr[x].rc = build(mid, r);
	}
	else tr[x].lc = tr[x].rc = 0;
	return x;
}

void upd(int x) {
	int l = tr[x].l;
	int r = tr[x].r;
	if (tr[x].cnt != 0)tr[x].sm = dis[r] - dis[l];
	else tr[x].sm = tr[tr[x].lc].sm + tr[tr[x].rc].sm;
}

void update(int x, int l, int r, int c) {
	if (tr[x].l == l&&tr[x].r == r) {
		tr[x].cnt += c;
		upd(x);
		return;
	}
	int mid = (tr[x].l + tr[x].r) >> 1;
	if (r <= mid) update(tr[x].lc, l, r, c);
	else if (l >= mid)update(tr[x].rc, l, r, c);
	else {
		update(tr[x].lc, l, mid, c);
		update(tr[x].rc, mid, r, c);
	}
	upd(x);
}

int main() {
	int n, count = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		dat_num = 0;
		x_num = 0;
		for (int i = 1; i <= n; i++) {
			double x1, y1, x2, y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			dat[++dat_num].flag = 1;
			dat[dat_num].y = y1;
			dat[++dat_num].flag = -1;
			dat[dat_num].y = y2;
			X[++x_num].x = x1;
			X[x_num].id = dat_num;
			X[++x_num].x = x2;
			X[x_num].id = dat_num + 2 * n;
		}
		sort(X + 1, X + 1 + x_num, cmp1);
		int p = 0;
		for (int i = 1; i <= x_num; i++) {
			if (X[i].x != X[i - 1].x || p == 0) {
				p++;
				dis[p] = dis[p - 1] + X[i].x - X[i - 1].x;
			}
			if (X[i].id <= 2 * n) {
				dat[X[i].id].x1 = dat[X[i].id - 1].x1 = p;
			}
			else {
				dat[X[i].id - 2 * n].x2 = dat[X[i].id - 1 - 2 * n].x2 = p;
			}
		}
		sort(dat + 1, dat + 1 + dat_num, cmp2);
		len = 0;
		tr[0].sm = 0;
		build(1, p);
		double ans = 0;
		for (int i = 1; i < dat_num; i++) {
			update(1, dat[i].x1, dat[i].x2, dat[i].flag);
			ans += tr[1].sm*(dat[i + 1].y - dat[i].y);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n", count++, ans);
	}
	return 0;
}