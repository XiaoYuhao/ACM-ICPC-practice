#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

//int num[100005];

int fun(int k) {
	int res = 0;
	for (int i = 1; i < k; i++) {
		res += i;
	}
	return res;
}
int main() {
	int n;
	while (cin >> n) {
		vector<int> vec;
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end());
		int minx = INT_MAX;
		int maxx = 0;
		int sub = 0, ans1 = 0, ans2 = 0;
		for (int i = 1; i < vec.size(); i++) {
			sub = abs(vec[i] - vec[i - 1]);
			if (sub < minx) {
				minx = sub;
				ans1 = 0;
			}
			if (sub == minx) {
				ans1++;
			}
		}
		int c = 1, maxc = 0;
		for (int i = 1; i < vec.size(); i++) {
			c = 1;
			while (i < vec.size() && vec[i] == vec[i - 1]) {
				i++;
				c++;
			}
			if (c > 1) {
				maxc += (c*(c - 1)) / 2;
			}
		}
		int a = 1, b = 1, temp1, temp2;
		temp1 = vec[0];
		temp2 = vec[n - 1];
		for (int i = 1; i < vec.size(); i++) {
			if (temp1 == vec[i])a++;
			else break;
		}
		for (int i = vec.size() - 2; i >= 1; i--) {
			if (temp2 == vec[i])b++;
			else break;
		}
		if (temp1 == temp2) {
			ans2 = (n*(n - 1)) / 2;
		}
		else {
			ans2 = a*b;
		}
		if (minx==0) {
			ans1 = maxc;
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}