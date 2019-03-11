#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 100010;
struct Node {
	int x, y;
}A[maxn], B[maxn];
bool cmp(Node a, Node b) {
	if (a.x == b.x)return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	int t, i, j, k, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i<n; ++i) {
			scanf("%d%d", &A[i].x, &A[i].y);
		}
		for (i = 0; i<n; ++i) {
			scanf("%d%d", &B[i].x, &B[i].y);
		}
		int ans = 0;
		sort(A, A + n, cmp);
		sort(B, B + n, cmp);
		multiset<int>M;
		for (int a = 0, b = 0; a<n; ++a) {
			for (; b<n&&B[b].x <= A[a].x; ++b)
				M.insert(B[b].y);
			if (!M.empty()) {
				multiset<int>::iterator it;
				it = M.upper_bound(A[a].y);
				if (it != M.begin()) {
					it--;
					ans++;
					M.erase(it);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}