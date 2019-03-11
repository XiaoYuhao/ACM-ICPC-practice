#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;

const int MAX = 20;
const double eps = 1e-6;


struct Point {
	int x, y;
}p[MAX];

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		char ss[10];
		for (int i = 0; i < n; i++) {
			scanf("%s%d%d", ss, &p[i].x, &p[i].y);
		}
		int x1 = 0, x2 = 0, x3 = 0, x4 = 0, y1 = 0, y2 = 0, y3 = 0, y4 = 0;
		int ans1=0, ans2=0, ans3=0;
		double s=0, s1=0, s2=0, s3=0, s4=0, max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					x1 = p[i].x;
					y1 = p[i].y;
					x2 = p[j].x;
					y2 = p[j].y;
					x3 = p[k].x;
					y3 = p[k].y;
					s = fabs(((y3 - y1)*(x2 - x1) - (y2 - y1)*(x3 - x1))*(1 / 2.0));
					int flag = 0;
					for (int f = 0; f < n; f++) {
						if (f == i || f == j || f == k)continue;
						x4 = p[f].x;
						y4 = p[f].y;
						s1 = fabs(((y4 - y1)*(x2 - x1) - (y2 - y1)*(x4 - x1))*(1 / 2.0));
						s2 = fabs(((y3 - y4)*(x2 - x4) - (y2 - y4)*(x3 - x4))*(1 / 2.0));
						s3 = fabs(((y3 - y1)*(x4 - x1) - (y4 - y1)*(x3 - x1))*(1 / 2.0));
						s4 = s1 + s2 + s3;
						if (fabs(s4-s)<=eps) {
							flag = 1;
							break;
						}
					}
					if (flag) {
						continue;
					}
					else {
						if (max < s) {
							max = s;
							ans1 = i;
							ans2 = j;
							ans3 = k;
						}
					}
				}
			}
		}
		char label = 'A';
		printf("%c%c%c\n", char(label + ans1), char(label + ans2), char(label + ans3));
	}
}