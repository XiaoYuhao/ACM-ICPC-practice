#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include <math.h>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct lp { 
	double x, y; 
	bool operator<(const lp&b) const {
		if (x == b.x) return y < b.y;
		return x < b.x;
	}
};
struct line { lp a, b; };

const int MAX = 100005;

double xmult(lp p1, lp p2, lp p0) {
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
lp cw[MAX], R[MAX];
int convex(int n) {
	int tn = 0, k;
	sort(cw, cw + n);
	for (int i = 0; i < n; i++) {
		while (tn > 1 && xmult(cw[i], R[tn - 2], R[tn - 1]) <= 0) tn--;
		R[tn++] = cw[i];
	}
	k = tn;
	for (int i = n - 2; i >= 0; i--) {
		while (tn > k && xmult(cw[i], R[tn - 2], R[tn - 1]) <= 0) tn--;
		R[tn++] = cw[i];
	}
	if (n > 1) tn--;
	return tn;
}

double dist(lp p1, lp p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double rotating_calipers(lp p[], int top)
{
	double ans = 0;
	p[top + 1] = p[1];
	int now = 2;
	for (int i = 1; i <= top; i++)
	{
		while (xmult(p[i + 1], p[now], p[i])<xmult(p[i + 1], p[now + 1], p[i]))
		{
			now++;
			if (now == top + 1) now = 1;
		}
//		ans = max(ans, distance(p[now], p[i]));
		if (dist(p[now], p[i]) > ans) {
			ans = dist(p[now], p[i]);
		}
	}
	return ans*ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &cw[i].x, &cw[i].y);
	}
	int cnt = convex(n);
	long long ans = rotating_calipers(R, cnt);
	printf("%lld\n", ans);
	return 0;
}