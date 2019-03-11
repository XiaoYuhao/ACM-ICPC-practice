#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 200005;
int a[MAX];
int nl[MAX];
int nr[MAX];
int flag[MAX];

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (nl[a[i]] == 0)nl[a[i]] = i;
		nr[a[i]] = i;
	}
	int pl, pr;
	int bflag = 0;
	if (nl[q] == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				a[i] = q;
				nl[q] = i;
				nr[q] = i;
				bflag = 1;
				break;
			}
		}
		if (bflag == 0) {
			printf("NO\n");
			return 0;
		}
	}
	for (int i = q; i > 0; i--) {
		pl = nl[i];
		pr = nr[i];
		if (pl == 0 || pr == 0)continue;
		for (int k = pl;!flag[k]&& k <= pr; k++) {
			if (a[k] == 0) {
				a[k] = i;
			}
			if (a[k] < i) {
				printf("NO\n");
				return 0;
			}
			flag[k] = 1;
		}
	}
	a[0]=1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			 a[i] = a[i - 1];
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}