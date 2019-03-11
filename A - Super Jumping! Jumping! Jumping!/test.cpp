#include<iostream>
using namespace std;
#include<algorithm>

const int MAX = 1005;
int a[MAX];
int maxlen[MAX];

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			maxlen[i] = a[i];
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (a[i] > a[j]) {
					maxlen[i] = max(maxlen[i], maxlen[j] + a[i]);
				}
			}
		}
		int max = 0;
		for (int i = 1; i <= n; i++) {
			if (maxlen[i] > max) {
				max = maxlen[i];
			}
		}
		cout << max << endl;
	}
}