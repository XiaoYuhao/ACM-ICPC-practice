#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main() {
	int n, a, tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> a;
		if (n > 2||n==0) {
			cout << -1 << " " << -1 << endl;
		}
		else if (n == 1) {
			cout << 1 << " " << a + 1 << endl;
		}
		else {
			if (a % 2) {
				int k = (a - 1) / 2;
				cout << 2 * k*k + 2 * k << " " << 2 * k*k + 2 * k + 1 << endl;
			}
			else {
				int k = a / 2;
				cout << k*k - 1 << " " << k*k + 1 << endl;
			}
		}
	}
	return 0;
}