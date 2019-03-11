#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int slen, tlen;
	slen = s.length();
	tlen = t.length();
	if (slen > tlen+1) {
		cout << "NO" << endl;
		return 0;
	}
	int flag = 0;
	for (int i = 0; i < slen; i++) {
		if (s[i] == '*') {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		if (slen != tlen) {
			cout << "NO" << endl;
			return 0;
		}
	}
	int lp = 0, rps, rpt;
	rps = slen - 1;
	rpt = tlen - 1;
	while (lp<slen) {
		if (s[lp] == '*')break;
		if (s[lp] != t[lp] ) {
			cout << "NO" << endl;
			return 0;
		}
		lp++;
	}
	while (rps>=0&&rpt>=0) {
		if (s[rps] == '*')break;
		if (s[rps--] != t[rpt--]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}