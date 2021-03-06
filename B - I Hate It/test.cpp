#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 200010;
const int INF = 99999999;

int N, dat[4 * MAX - 1];
int ss[MAX];

void build(int l,int r,int k){
	if (r - 1 == l) {
		dat[k] = ss[l];
	}
	else {
		build(l, (l + r) / 2, k * 2 + 1);
		build((l + r) / 2, r, k * 2 + 2);
		dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}

void init(int n_) {
	N = 1;
	while (n_ > N) {
		N *= 2;
	}
	for (int i = 0; i < 2 * N - 1; i++) {
		dat[i] = 0;
	}
}
void update(int k, int a) {
	k += N - 1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}

int query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l)return 0;
	if (a <= l&&r <= b)return dat[k];
	else {
		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int x;
		init(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ss[i]);
		}
		build(0, N, 0);
		char s[2];
		int a, b, ans;
		for (int i = 0; i < m; i++) {
			scanf("%s%d%d", &s, &a, &b);
			if (s[0] == 'Q') {
				ans = query(a-1, b, 0, 0, N);
				printf("%d\n", ans);
			}
			else {
				update(a - 1, b);
			}
		}
	}
	return 0;
}