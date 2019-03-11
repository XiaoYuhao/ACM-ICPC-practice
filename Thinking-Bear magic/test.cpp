#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const double pi = 3.1415926;

int main() {
	double s;
	double bili;
	int n, a, L;
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> a >> L;
//		s = tan(pi / 2 - pi / n);
		s = (1 / 4.0)*n*a*a*tan(pi / 2 - pi / n);
		bili = sin(pi / 2 - pi / n)*sin(pi / 2 - pi / n);
		int ans = 0;
		while (s > L) {
			s *= bili;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}