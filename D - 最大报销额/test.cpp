#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

const int MAX_N = 32;
const int MAX = 3000010;
int x[MAX_N];
int dp[MAX];

int main() {
	double qq = 0;
	int n = 0;
	while (1) {
		cin >> qq >> n;
		if (n == 0)break;
		int q;
		q = int (qq * 100);
		int m;
		char ch;
		double money,sum = 0;
		double a_money = 0, b_money = 0, c_money = 0;
		int k = 0;
		for (int i = 0; i <=q ; i++) {
				dp[i] = 0;
		}
		for (int i = 0; i < MAX_N; i++) {
			x[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> m;
			int flag = 0;
			sum = 0;
			a_money = 0;
			b_money = 0;
			c_money = 0;
			for (int j = 0; j < m; j++) {
				cin >> ch;
				if (ch == 'A') {
					cin >> ch;
					cin >> money;
					a_money += money;
				}
				else if (ch == 'B') {
					cin >> ch;
					cin >> money;
					b_money += money;
				}
				else if (ch == 'C') {
					cin >> ch;
					cin >> money;
					c_money += money;
				}
				else {
					cin >> ch;
					cin >> money;
					flag = 1;
				}
				sum += money;
				if (a_money > 600.00||b_money>600.00||c_money>600.00||sum>1000.00) {
					flag = 1;
				}
			}
			if (flag == 0) {
				x[k++] = int(sum * 100);
			}
		}
	/*	for (int j = x[k - 1]; j <= q; j++) {
			dp[k - 1][j] = x[k - 1];
		}*/
/*		for (int a = k-1; a >=0; a--) {
			for (int b = 0; b <= q; b++) {
				if ( b< x[a]) {
					dp[a][b] = dp[a+1][b];
				}
				else {
					dp[a][b] = max(dp[a+1][b], dp[a+1][b - x[a]] + x[a]);
				//	cout << dp[a][b] << endl;
				}
			}
		}*/
		for (int i = 0; i < n; i++) {
			for (int j = q; j >= x[i]; j--) {
				dp[j] = max(dp[j], dp[j - x[i]] + x[i]);
			}
		}
		cout << setiosflags(ios::fixed)<< setprecision(2)<< double(dp[q]/100.0) << endl;
	}
}
/*
200.00 3
2 A:23.50 B:100.00
1 C:650.00
3 A:59.99 A:120.00 X:10.00
1200.00 2
2 B:600.00 A:400.00
1 C:200.50
1200.50 3
2 B:600.00 A:400.00
1 C:200.50
1 A:100.00
800.00 3
3 A:100.00 B:400.00 C:400.00
2 A:400.00 D:200.00
2 A:500.00 B:650.00
*/