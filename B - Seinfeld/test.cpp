#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 2005;
char ch[MAX];

int main() {
	int count = 1;
	while (1) {
		cin >> ch;
		if (ch[0] == '-')break;
		int len;
		len = strlen(ch);
		int t = 0, a = 0;
		for (int i = 0; i < len; i++) {
			if (ch[i] == '{') {
				t++;
			}
			else {
				if (t) {
					t--;
				}
				else {
					t++;
					a++;
				}
			}
		}
		int ans = 0;
		ans = a + t / 2;
		cout << count++ << ". " << ans << endl;
	}
	return 0;
}
