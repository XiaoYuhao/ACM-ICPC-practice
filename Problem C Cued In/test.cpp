#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<vector>
#include<functional>

using namespace std;


int main() {
	int n;
	cin >> n;
	string s;
	int red_num = 0;
	int sum = 0, maxx = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "red") {
			red_num += 1;
			sum += 1;
			maxx = max(maxx, 1);
		}
		else if (s == "yellow") {
			sum += 2;
			maxx = max(maxx, 2);
		}
		else if (s == "green") {
			sum += 3;
			maxx = max(maxx, 3);
		}
		else if (s == "brown") {
			sum += 4;
			maxx = max(maxx, 4);
		}
		else if (s == "blue") {
			sum += 5;
			maxx = max(maxx, 5);
		}
		else if (s == "pink") {
			sum += 6;
			maxx = max(maxx, 6);
		}
		else if (s == "black") {
			sum += 7;
			maxx = max(maxx, 7);
		}
	}
	int ans = 0;
	if (maxx == 1) {
		ans = 1;
	}
	else {
		ans = red_num*maxx + sum;
	}
	cout << ans << endl;
	return 0;
}