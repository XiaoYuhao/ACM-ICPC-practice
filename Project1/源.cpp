#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct point {
	int x, y;
}P[105];
int main()
{
	
	int n, r, R;
	int t;
	vector<int> k;
	k.reserve(105);
	scanf("%d", &t);
	while (t--) {
		k.clear();
		scanf("%d %d %d", &n, &R, &r);
		int num;
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d", &P[i].x, &P[i].y);
			if (P[i].x*P[i].x + P[i].y*P[i].y <= (R -2* r)*(R -2* r)) {
				k.push_back(i);
			}
		}
		if (k.empty()) {
			int min = 1000000000;
			for (int i = 1; i <= n; ++i) {
				if (P[i].x*P[i].x + P[i].y*P[i].y < min) {
					k.clear();
					k.push_back(i);
					min = P[i].x*P[i].x + P[i].y*P[i].y;
				}
				else if (P[i].x*P[i].x + P[i].y*P[i].y == min) {
					k.push_back(i);
				}
			}
		}
		printf("%d\n", k.size());
		for (int i = 0; i < k.size(); ++i) {
			if (i != 0) {
				printf(" ");
			}
			printf("%d", k[i]);
		}
		printf("\n");
	}
	return 0;
}