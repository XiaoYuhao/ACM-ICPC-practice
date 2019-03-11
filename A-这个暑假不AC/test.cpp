#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 105;

struct TVShow {
	int ts;
	int te;
}t[MAX];

bool camp(TVShow a, TVShow b) {
	return a.te < b.te;
}
int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			cin >> t[i].ts >> t[i].te;
		}
		sort(t, t + n, camp);
		int i, j;
		i = 0;
		j = i + 1;
		int sum = 1;
		while (j < n) {
			if (t[i].te <= t[j].ts) {
				sum++;
				i = j;
			}
			j++;
		}
		cout << sum << endl;
	}
	return 0;
}