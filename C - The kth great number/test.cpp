#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
#include<queue>
#include<cstdio>
const int MAX = 10000000;

int a[MAX];
int main() {
	int n, k;
	char c;
	int num, len;
	len = 0;
	while (scanf("%d %d",&n,&k)!=EOF) {
		while (n--) {
			scanf("%c", &c);
			if (c == 'I') {
				scanf("%d", &num);
				a[len++] = num;
				nth_element(a, a + k, a + len);
			}
			else if (c == 'Q') {
			//	cout << a[len - k] << endl;
				printf("%d\n", a[len - k]);
			}
		}
	}
	return 0;
}