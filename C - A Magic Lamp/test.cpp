#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 1005;
char num[MAX];
char ans[MAX];




int main() {
	int m;
	while (cin >> num) {
		cin >> m;
		int len = strlen(num);
		int index = 0;
		int r = m;
		m = len - m;
		int l = 0;
		int k = 0;
		if (m == 0) {
			cout << "0" << endl;
			continue;
		}
		while (m--) {
			index = l;
			for (int i = l; i <= r; i++) {
				if (num[i] < num[index]) {
					index = i;
				}
			}
			ans[k++] = num[index];
			l = index + 1;
			r++;
		}

		int flag = 0;
		for (int i = 0; i < k; i++) {
			if (ans[i] == '0'&&flag == 0 && i != k - 1) continue;
			else {
				cout << ans[i];
				flag = 1;
			}

		}
		cout << endl;
	}
	return 0;
}