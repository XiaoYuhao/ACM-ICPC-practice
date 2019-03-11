#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 20;
char a[MAX], b[MAX], temp[MAX];

bool camp(char a,char b) {
	return int(a) > int(b);
}
int main() {
	cin >> a >> b;
	int alen, blen;
	alen = strlen(a);
	blen = strlen(b);
	sort(a, a + alen);
	if (blen > alen) {
		sort(a, a + alen,camp);
		cout << a << endl;
		return 0;
	}
	else {
		for (int i = 0; i < alen; i++) {
			for (int j = alen-1; j >i; j--) {
				strcpy(temp, a);
				swap(a[i], a[j]);
				sort(a + i+1, a + alen);
				if (strcmp(a, b) > 0) {
					strcpy(a, temp);
				}
				else {
					break;
				}
			}
		}
		cout << a << endl;
	}
	return 0;
}