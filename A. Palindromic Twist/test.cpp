#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 105;
char s[MAX];

int main() {
	int tt;
	scanf("%d", &tt);
	int n;
	while (tt--) {
		scanf("%d", &n);
		scanf("%s", s);
		int j = 0;
		int flag = 0;
		for (int i = 0; i <= n / 2 - 1; i++) {
			j = n - i - 1;
			if (s[i] > 'a'&&s[i] < 'z') {
				if (s[i]+1 == s[j]+1)continue;
				else if (s[i] -1 == s[j]-1)continue;
//				else if (s[i] - 1 == s[j])continue;
				else if (s[i] + 1 == s[j] - 1)continue;
				else if (s[i] - 1 == s[j] + 1)continue;
			}
			else if (s[i] == 'a') {
//				if (s[i] == s[j])continue;
//				else if (s[i] + 1 == s[j])continue;
				if (s[i] + 1 == s[j] - 1)continue;
				else if (s[i] + 1 == s[j] + 1)continue;
			}
			else if (s[i] == 'z') {
//				if (s[i] == s[j])continue;
//				else if (s[i] - 1 == s[j])continue;
				if (s[i] - 1 == s[j] + 1)continue;
				else if (s[i] - 1 == s[j] - 1)continue;
			}
			flag = 1;
			break;
		}
		if (flag) {
			printf("NO\n");
			continue;
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}