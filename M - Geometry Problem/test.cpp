#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<random>
#include<map>
#include<ctime>
using namespace std;
const int MAX = 100010;
const double eps = 1e-6;
int vis[MAX];

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) { }
	inline void read()
	{
		scanf("%lf%lf", &x, &y);
	}
}p[MAX];

struct Cir {
	Point p1;
	double len;
	bool operator <(Cir c)const {
		if (p1.x == c.p1.x) {
			if (p1.y == c.p1.y) {
				return len < c.len;
			}
			else return p1.y < c.p1.y;
		}
		else return p1.x < c.p1.x;
	}
};

Point CircumscribedCircle(Point p1, Point p2, Point p3)
{
	double Bx = p2.x - p1.x, By = p2.y - p1.y;
	double Cx = p3.x - p1.x, Cy = p3.y - p1.y;
	double D = 2 * (Bx*Cy - By*Cx);
	double cx = (Cy*(Bx*Bx + By*By) - By*(Cx*Cx + Cy*Cy)) / D + p1.x;
	double cy = (Bx*(Cx*Cx + Cy*Cy) - Cx*(Bx*Bx + By*By)) / D + p1.y;
	Point p = Point(cx, cy);
	return p;
}

bool gongxian(Point a, Point b, Point c) {
	if (fabs((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y)) < eps) {
		return true;
	}
	return false;
}

double length(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			p[i].read();
		}
		
		double len = 0;
		Point pp;
		if (n == 1) {
			pp.x = 0;
			pp.y = 0;
			len = length(p[0], pp);
			printf("%lf %lf %lf\n", pp.x, pp.y, len);
			continue;
		}
		else if (n <=4) {
			pp.x = (p[0].x + p[1].x) / 2;
			pp.y = (p[0].y + p[1].y) / 2;
			len =  length(p[0], pp);
			printf("%lf %lf %lf\n", pp.x, pp.y, len);
			continue;
		}
		for (;;) {
			int a, b, c;
			a = rand() % n;
			b = rand() % n;
			c = rand() % n;
			if (a == b || a == c || b == c) {
				continue;
			}		
			if (gongxian(p[a], p[b], p[c])) {
				continue;
			}
			pp = CircumscribedCircle(p[a], p[b], p[c]);
			len = length(p[a], pp);
			if (pp.x > 1e9 || pp.y > 1e9 || len > 1e9||pp.x<(-1e9)||pp.y<(-1e9)) {
				continue;
			}
			
			int cnt = 0;
			int flag = 0;
			int sum = 0;
			if (n % 2) {
				sum = n / 2 + 1;
			}
			else {
				sum = n / 2;
			}
			for (int j = 0; j < n; j++) {
				if (fabs(len - length(p[j], pp)) < eps) {
					cnt++;
				}
				if (cnt >= sum) {
					flag = 1;
					break;
				}
				if ((n - j-1+cnt) < sum) {
					flag = 0;
					break; 
				}
			}
			if (flag) {
				break;
			}
		}
		printf("%lf %lf %lf\n", pp.x, pp.y, len);
	}
	return 0;
}

/*
13
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
7
1 1
1 0
1 -1
0 1
-1 1
0 -1
-1 0
*/