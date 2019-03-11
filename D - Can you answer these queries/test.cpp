#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 100005;
const int INF = 99999999;

struct node {
	__int64 sum;
	int l, r;
	bool k;
}dat[MAX << 2];

void build(int L, int R, int rt) {
	dat[rt].l = L;
	dat[rt].r = R;
	dat[rt].k = 0;
	if (L == R) {
		scanf("%I64d", &dat[rt].sum);
		if (dat[rt].sum == 1)dat[rt].k = 1;
		return;
	}
	int mid = (dat[rt].l + dat[rt].r) >> 1;
	build(L, mid, rt << 1);
	build(mid + 1, R, rt << 1 | 1);
	dat[rt].sum = dat[rt << 1].sum + dat[rt << 1 | 1].sum;
	dat[rt].k = dat[rt << 1].k&&dat[rt << 1 | 1].k;
}

void update(int L, int R, int rt) {
	if (dat[rt].k)return;
	if (dat[rt].l == dat[rt].r) {
		dat[rt].sum = sqrt(dat[rt].sum*1.0);
		if (dat[rt].sum == 1)dat[rt].k = 1;
		return;
	}
	int mid = (dat[rt].l + dat[rt].r) >> 1;
	if (L <= mid)update(L, R, rt << 1);
	if (R > mid)update(L, R, rt << 1 | 1);
	dat[rt].sum = dat[rt << 1].sum + dat[rt << 1 | 1].sum;
	dat[rt].k = dat[rt<<1].k&&dat[rt << 1 | 1].k;
}

__int64 query(int L, int R, int rt) {
	if (L <= dat[rt].l&&R >= dat[rt].r) {
		return dat[rt].sum;
	}
	__int64 ret = 0;
	int mid = (dat[rt].l + dat[rt].r) >> 1;
	if (L <= mid)ret += query(L, R, rt << 1);
	if (R > mid)ret += query(L, R, rt << 1 | 1);
	return ret;
}

int main() {
	int n, m, count = 1;
	while (scanf("%d", &n) != EOF) {
		build(1, n, 1);
		scanf("%d", &m);
		printf("Case #%d:\n", count++);
		while (m--) {
			int c, x, y;
			scanf("%d%d%d", &c, &x, &y);
			if (x > y)swap(x, y);
			if (c)printf("%I64d\n", query(x, y, 1));
			else update(x, y, 1);
		}
		printf("\n");
	}
	return 0;
}