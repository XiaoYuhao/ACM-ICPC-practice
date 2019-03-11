#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 305;
struct Block {
	int area;
	int h;
	int c;
	int r;
}b[MAX];
bool camp(Block a, Block b) {
	return a.area > b.area;
}
int dp[MAX];

int main() {
	int count = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		int x, y, z, j = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			b[j].area = x*y;
			b[j].c = x;
			b[j].r = y;
			b[j].h = z;
			j++;
			b[j].area = x*z;
			b[j].c = x;
			b[j].r = z;
			b[j].h = y;
			j++;
			b[j].area = y*z;
			b[j].c = y;
			b[j].r = z;
			b[j].h = x;
			j++;
		}
		sort(b, b + 3 * n, camp);
		for (int i = 0; i < 3 * n; i++) {
			dp[i] = b[i].h;
		}
		for (int i = 1; i < 3 * n; i++) {
			for (int j = 0; j < i; j++) {
				if ((b[i].c < b[j].c&&b[i].r < b[j].r)||(b[i].c<b[j].r&&b[i].r<b[j].c)) {
					dp[i] = max(dp[i], dp[j] + b[i].h);
				}
			}
		}
		int max = 0;
		for (int i = 0; i < 3 * n; i++) {
			if (dp[i] > max) {
				max = dp[i];
			}
		}
		cout <<"Case "<<count++<<": maximum height = "<< max << endl;
	}
	return 0;
}