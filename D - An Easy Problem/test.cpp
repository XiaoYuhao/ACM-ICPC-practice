#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point
{
	double x, y;
	point(double x = 0, double y = 0) :x(x), y(y) { }
	inline void read()
	{
		scanf("%lf%lf", &x, &y);
	}
}P[4];
typedef point Vector;
double xmult(point p1, point p2, point p0) {
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
double xmult(double x1, double y1, double x2, double y2, double x0, double y0) {
	return (x1 - x0)*(y2 - y0) - (x2 - x0)*(y1 - y0);
}
int dots_inline(double x1, double y1, double x2, double y2, double x3, double y3) {
	return zero(xmult(x1, y1, x2, y2, x3, y3));
}
int dots_inline(point p1, point p2, point p3) {
	return zero(xmult(p1, p2, p3));
}
int dot_online_in(point p, point l1, point l2) {
	return zero(xmult(p, l1, l2)) && (l1.x - p.x)*(l2.x - p.x) < eps && (l1.y - p.y)*(l2.y - p.y) < eps;
}
int dot_online_in(double x, double y, double x1, double y1, double x2, double y2) {
	return zero(xmult(x, y, x1, y1, x2, y2)) && (x1 - x)*(x2 - x) < eps && (y1 - y)*(y2 - y) < eps;
}
int same_side(point p1, point p2, point l1, point l2) {
	return xmult(l1, p1, l2)*xmult(l1, p2, l2) > eps;
}
//判两线段相交,包括端点和部分重合
int intersect_in(point u1, point u2, point v1, point v2) {
	if (!dots_inline(u1, u2, v1) || !dots_inline(u1, u2, v2))
		return !same_side(u1, u2, v1, v2) && !same_side(v1, v2, u1, u2);
	return dot_online_in(u1, v1, v2) || dot_online_in(u2, v1, v2) || dot_online_in(v1, u1, u2) || dot_online_in(v2, u1, u2);
}
//计算两直线交点,注意事先判断直线是否平行!
//线段交点请另外判线段相交(同时还是要判断是否平行!)
point intersection(point u1, point u2, point v1, point v2) {
	point ret = u1;
	double t = ((u1.x - v1.x)*(v1.y - v2.y) - (u1.y - v1.y)*(v1.x - v2.x))
		/ ((u1.x - u2.x)*(v1.y - v2.y) - (u1.y - u2.y)*(v1.x - v2.x));
	ret.x += (u2.x - u1.x)*t;
	ret.y += (u2.y - u1.y)*t;
	return ret;
}
//判两直线平行
int parallel(point u1, point u2, point v1, point v2) {
	return zero((u1.x - u2.x)*(v1.y - v2.y) - (v1.x - v2.x)*(u1.y - u2.y));
}

int main() {
	int tt;
	double x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d", &tt);
	double len, h, ans, x, y, a, b, c, d, xk;
	while (tt--) {
		P[0].read();
		P[1].read();
		P[2].read();
		P[3].read();
		if (!parallel(P[0], P[1], P[2], P[3]) && intersect_in(P[0], P[1], P[2], P[3])) {
			point pp;
			pp = intersection(P[0], P[1], P[2], P[3]);
			x = pp.x;
			y = pp.y;
			if (P[0].y > y) {
				a = P[0].x;
				b = P[0].y;
			}
			else {
				a = P[1].x;
				b = P[1].y;
			}
			if (P[2].y > y) {
				c = P[2].x;
				d = P[2].y;
			}
			else {
				c = P[3].x;
				d = P[3].y;
			}
			if (b > d) {
				swap(d, b);
				swap(a, c);
			}
			if (d <= y) {
				printf("0.00\n");
				continue;
			}
			if (b <= y) {
				printf("0.00\n");
				continue;
			}
			if (a >= x&&a <= c && (fabs((b - y) / (a - x)) < fabs((d - y) / (c - x)))) {
				printf("0.00\n");
				continue;
			}
			if (a >= c&&a <= x && (fabs((b - y) / (a - x)) < fabs((d - y) / (c - x)))) {
				printf("0.00\n");
				continue;
			}
			xk = (c - x) / (d - y)*(b - y) + x;
			len = fabs(xk - a);
			h = fabs(b - y);
			ans = len*h / 2.0;
			printf("%.2f\n", ans);
		}
		else {
			printf("0.00\n");
		}
	}
	return 0;
}