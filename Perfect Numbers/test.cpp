#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> divisor(int n) {
	vector<int> res;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (i != n / i)res.push_back(n / i);
		}
	}
	return res;
}
int main() {
	int tt, count = 1;
	int n;
	int sum = 0;
	vector<int> ans;
	cin >> tt;
	while (tt--) {
		cin >> n;
		ans = divisor(n);
		sort(ans.begin(), ans.end());
		sum = 0;
		for (int i = 0; i < ans.size()-1; i++) {
			sum += ans[i];
		}
		if (sum != n) {
			cout <<"Case "<<count++<<": "<< "Not perfect." << endl;
		}
		else {
			cout << "Case " << count++ << ": " << n << " = ";
			for (int i = 0; i < ans.size()-1; i++) {
				if (i != ans.size() - 2) {
					cout << ans[i] << " + ";
				}
				else {
					cout << ans[i];
				}
			}
			cout << endl;
		}
	}
	return 0;
}