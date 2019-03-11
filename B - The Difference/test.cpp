#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int num[4];

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		for (int i = 0; i < 4; i++) {
			cin >> num[i];
		}
		sort(num, num + 4);
		int ans;
		ans = num[3] * num[2] - num[1] * num[0];
		cout << ans << endl;
	}
	return 0;
}
