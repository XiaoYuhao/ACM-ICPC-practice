#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>

using namespace std;

struct Frame {
	int x, y;
};

bool operator ==(Frame a,Frame b) {
	return (a.x == b.x&&a.y == b.y);
}
bool operator >(Frame a, Frame b) {
	if (a.x == b.x)return a.y > b.y;
	else return a.x > b.x;
}
bool operator <(Frame a, Frame b) {
	if (a.x == b.x)return a.y < b.y;
	else return a.x < b.x;
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		int k;
		map<Frame, int> map1, map2;
		int max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &k);
			Frame fr;
			for (int j = 0; j < k; j++) {
				scanf("%d %d", &fr.x, &fr.y);
				if (i % 2 == 0) {
					int k = map2[fr];
					if (k == 0) {
						map1[fr] = 1;
					}
					else if (k > 0) {
						map1[fr] = k + 1;
						if (max < k + 1) {
							max = k + 1;
						}
					}
				}
				else {
					int k = map1[fr];
					if (k == 0) {
						map2[fr] = 1;
					}
					else if (k > 0) {
						map2[fr] = k + 1;
						if (max < k + 1) {
							max = k + 1;
						}
					}
				}
			}
			if (i % 2 == 0) {
				map2.clear();
			}
			else {
				map1.clear();
			}
		}
		if (max == 0)max = 1;
		printf("%d\n", max);
	}
	return 0;
}

/*
1
8
2 1 1 2 2
2 2 2 1 4
2 1 1 2 2
2 2 2 1 4
1 0 0
1 0 0
1 1 1
1 1 1
*/