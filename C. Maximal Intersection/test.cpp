#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 300010;
struct seg{
	int id;
	int l, r;
}a[MAX], b[MAX];

bool cmp1(seg a, seg b) {
	return a.l > b.l;
}
bool cmp2(seg a, seg b) {
	return a.r < b.r;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].l, &a[i].r);
		a[i].id = i;
		b[i].l = a[i].l;
		b[i].r = a[i].r;
		b[i].id = i;
	}
	sort(a, a + n, cmp1);
	sort(b, b + n, cmp2);
	int ans = 0;
	int len1, len2, idl, idr, pl1, pl2, pl3, pr1, pr2, pr3;
	int idl2, idl3, idr2, idr3;
	pl1 = a[0].l;
	pl2 = a[1].l;
	pl3 = a[2].l;
	pr1 = b[0].r;
	pr2 = b[1].r;
	pr3 = b[2].r;
	idl = a[0].id;
	idr = b[0].id;
	idl2 = a[1].id;
	idl3 = a[2].id;
	idr2 = b[1].id;
	idr3 = b[2].id;
	if (idl == idr) {
		ans = pr2 - pl2;
	}
	else {
		len1 = pr1 - pl2;
		len2 = pr2 - pl1;
		ans = max(len1, len2);
	}
	if (ans < 0) {
		printf("0\n");
	}
	else printf("%d\n", ans);
	return 0;
}