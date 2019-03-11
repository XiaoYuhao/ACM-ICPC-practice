#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<iomanip>
using namespace std;

int check(string s) {
	int begin = 0;
	while (1) {
		if (s[begin++] == '[') {
			break;
		}
	}
	if (s[begin] == 'B') {
		return 1;
	}
	else if (s[begin] == 'K') {
		return 2;
	}
	else if (s[begin] == 'M') {
		return 3;
	}
	else if (s[begin] == 'G') {
		return 4;
	}
	else if (s[begin] == 'T') {
		return 5;
	}
	else if (s[begin] == 'P') {
		return 6;
	}
	else if (s[begin] == 'E') {
		return 7;
	}
	else if (s[begin] == 'Z') {
		return 8;
	}
	else if (s[begin] == 'Y') {
		return 9;
	}

}

int main() {
	double ans_kb = 1000 / 1024.0;
	double ans_mb = ans_kb*ans_kb;
	double ans_gb = ans_kb*ans_kb*ans_kb;
	double ans_tb = ans_kb*ans_kb*ans_kb*ans_kb;
	double ans_pb = ans_kb*ans_kb*ans_kb*ans_kb*ans_kb;
	double ans_eb = ans_kb*ans_kb*ans_kb*ans_kb*ans_kb*ans_kb;
	double ans_zb = ans_kb*ans_kb*ans_kb*ans_kb*ans_kb*ans_kb*ans_kb;
	double ans_yb = ans_kb*ans_kb*ans_kb*ans_kb*ans_kb*ans_kb*ans_kb*ans_kb;
	double b = 0;
	double kb = 1 - ans_kb;
	double mb = 1 - ans_mb;
	double gb = 1 - ans_gb;
	double tb = 1 - ans_tb;
	double pb = 1 - ans_pb;
	double eb = 1 - ans_eb;
	double zb = 1 - ans_zb;
	double yb = 1 - ans_yb;

	int tt, count = 1;
	cin >> tt;
	string s;
	while (tt--) {
		cin >> s;
		int flag = check(s);
		if (flag == 1) {
			cout << "Case #" << count++ << ": 0.00%" << endl;
		}
		else if (flag == 2) {
			cout << "Case #" << count++ << ": " <<setiosflags(ios::fixed)<< setprecision(2) <<kb*100.0 << "%" << endl;
		}
		else if (flag == 3) {
			cout << "Case #" << count++ << ": " << setiosflags(ios::fixed) << setprecision(2) << mb*100.0 << "%" << endl;
		}
		else if (flag == 4) {
			cout << "Case #" << count++ << ": " << setiosflags(ios::fixed) << setprecision(2) << gb*100.0 << "%" << endl;
		}
		else if (flag == 5) {
			cout << "Case #" << count++ << ": " << setiosflags(ios::fixed) << setprecision(2) << tb*100.0 << "%" << endl;
		}
		else if (flag == 6) {
			cout << "Case #" << count++ << ": " << setiosflags(ios::fixed) << setprecision(2) << pb*100.0 << "%" << endl;
		}
		else if (flag == 7) {
			cout << "Case #" << count++ << ": " << setiosflags(ios::fixed) << setprecision(2) << eb*100.0 << "%" << endl;
		}
		else if (flag == 8) {
			cout << "Case #" << count++ << ": " << setiosflags(ios::fixed) << setprecision(2) << zb*100.0 << "%" << endl;
		}
		else if (flag == 9) {
			cout << "Case #" << count++ << ": " << setiosflags(ios::fixed) << setprecision(2) << yb*100.0 << "%" << endl;
		}
	}
	return 0;
}