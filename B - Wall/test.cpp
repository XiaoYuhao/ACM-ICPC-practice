#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;

using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MX = 1010;
const double PI = 3.1415926;

struct lp {
	double x, y;
	bool operator<(const lp&b) const {
		if (x == b.x) return y < b.y;
		return x < b.x;
	}
} cw[MX], R[MX], op[5], ok;
LL cross(lp a, lp b, lp c) {
	return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}
int convex(int n) {
	int tn = 0, k;
	sort(cw, cw + n);
	for (int i = 0; i < n; i++) {
		while (tn > 1 && cross(R[tn - 1], cw[i], R[tn - 2]) <= 0) tn--;
		R[tn++] = cw[i];
	}
	k = tn;
	for (int i = n - 2; i >= 0; i--) {
		while (tn > k && cross(R[tn - 1], cw[i], R[tn - 2]) <= 0) tn--;
		R[tn++] = cw[i];
	}
	if (n > 1) tn--;
	return tn;
}


int main() {
	int m, len;
	scanf("%d%d", &m, &len);
	for (int i = 0; i < m; i++) {
		scanf("%lf%lf", &cw[i].x, &cw[i].y);
	}
	int cnt = convex(m);
	double sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += sqrt((R[i].x - R[i + 1].x)*(R[i].x - R[i + 1].x) + (R[i].y - R[i + 1].y)*(R[i].y - R[i + 1].y));
	}
	sum += 2 * PI*len;
	int ans = sum;
	printf("%0.lf\n", sum);
	return 0;
}