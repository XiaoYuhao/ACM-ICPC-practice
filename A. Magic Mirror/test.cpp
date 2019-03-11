#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'A'&&s[i] <= 'Z') {
				s[i] = s[i] + ('a' - 'A');
			}
		}
		if (s == "jessie") {
			cout << "Good guy!" << endl;
		}
		else {
			cout << "Dare you say that again?" << endl;
		}
	}
}
/*
4
jessie
Justin
jEssIe
jsdg514


Good guy!
Dare you say that again?
*/