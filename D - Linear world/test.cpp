#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAX = 40000;
struct Node {
	double pos;
	char name[256];
}inha[MAX];
struct Time {
	int dir;
	double tt;
}T[MAX];

bool cmp(Node a, Node b) {
	return a.pos < b.pos;
}
bool cmp2(Time a, Time b) {
	return a.tt < b.tt;
}
int main() {
	int n;
	double len, v;
	char ch[2];
	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		scanf("%lf%lf", &len, &v);
		int pn = 0, nn = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s %lf %s", ch, &inha[i].pos, inha[i].name);
			if (ch[0] == 'p' || ch[0] == 'P') {
				T[i].dir = 1;
				T[i].tt = (len - inha[i].pos) / v;
				pn++;
			}
			else {
				T[i].dir = 0;
				T[i].tt = (inha[i].pos) / v;
				nn++;
			}
		}
		sort(inha, inha + n, cmp);
		sort(T, T + n, cmp2);
		double anst = T[n - 1].tt;
		int lp = 0, rp = n - 1;
		for (int i = 0; i < n - 1; i++) {
			if (T[i].dir == 0)lp++;
			else rp--;
		}
		printf("%13.2lf %s\n", int(anst * 100) / 100.0, inha[rp].name);
	}
	return 0;
}