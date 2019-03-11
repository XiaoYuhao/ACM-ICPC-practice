#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<vector>
#include<set>
using namespace std;

int main() {
	map<int, int> mapint;
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		mapint[x]++;
	}
/*	int len = mapint.size();
	cout << len << endl << endl;
	for (int i = 1; i <= len; i++) {
		cout << mapint[i] << endl;
	}*/
	map<int, int>::iterator iter;
	for (iter = mapint.begin(); iter != mapint.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
	return 0;
}