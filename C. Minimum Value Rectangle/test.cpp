#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

const int MAXN = 1000005;
const int MAX = 10005;
int edge[MAXN];
int num[MAXN];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int tt;
	scanf("%d", &tt);
	int n;
	while (tt--) {
		scanf("%d", &n);
		int len;
		//memset(num, 0, sizeof(num));
		for (int i = 0; i <= n; i++) {
			num[i] = 0;
		}
		int m = 0;
		int x, y;
		int flag = 0;
		map<int, int> mapint;
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &len);
			mapint[len]++;
		}
		map<int, int>::iterator iter;
		int cnt = 1;
		for (iter = mapint.begin(); iter != mapint.end(); iter++) {
			if (iter->second >= 4) {
				x = iter->first;
				y = x;
				printf("%d %d %d %d\n", x, x, y, y);
				flag = 1;
				break;
			}
			else if (iter->second >= 2) {
				num[cnt++] = iter->first;
			}
		}
		if (flag)continue;
		sort(num + 1, num + cnt + 1, cmp);
		double min = 99999999.0;
		double xdy, ydx;

		for (int i = 1; i <= cnt; i++) {
			xdy = num[i] / (num[i + 1] * 1.0);
			ydx = num[i + 1] / (num[i] * 1.0);
			if (xdy + ydx < min) {
				x = num[i];
				y = num[i + 1];
				min = xdy + ydx;
			}
		}
		printf("%d %d %d %d\n", x, x, y, y);
	//	mapint.clear();
	}
	return 0;
}