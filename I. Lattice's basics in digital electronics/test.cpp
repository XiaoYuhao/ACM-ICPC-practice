#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<cstring>
#include<map>
using namespace std;


string HexToBin(const string &strHex)
{
	string strBin;
	for (int i = 0; i < strHex.size(); i++) {
		if (strHex[i] == '0') {
			strBin += "0000";
		}
		else if (strHex[i] == '1') {
			strBin += "0001";
		}
		else if (strHex[i] == '2') {
			strBin += "0010";
		}
		else if (strHex[i] == '3') {
			strBin += "0011";
		}
		else if (strHex[i] == '4') {
			strBin += "0100";
		}
		else if (strHex[i] == '5') {
			strBin += "0101";
		}
		else if (strHex[i] == '6') {
			strBin += "0110";
		}
		else if (strHex[i] == '7') {
			strBin += "0111";
		}
		else if (strHex[i] == '8') {
			strBin += "1000";
		}
		else if (strHex[i] == '9') {
			strBin += "1001";
		}
		else if (strHex[i] == 'A'|| strHex[i] == 'a') {
			strBin += "1010";
		}
		else if (strHex[i] == 'B' || strHex[i] == 'b') {
			strBin += "1011";
		}
		else if (strHex[i] == 'C' || strHex[i] == 'c') {
			strBin += "1100";
		}
		else if (strHex[i] == 'D' || strHex[i] == 'd') {
			strBin += "1101";
		}
		else if (strHex[i] == 'E' || strHex[i] == 'e') {
			strBin += "1110";
		}
		else if (strHex[i] == 'F' || strHex[i] == 'f') {
			strBin += "1111";
		}
	}

	return strBin;
}
int check(string s) {
	int num = 0;
	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] == '1')num++;
	}
	if (s[s.size() - 1] == '1') {
		if (num % 2 == 0)return 1;
		else return 0;
	}
	else {
		if (num % 2 == 0)return 0;
		else return 1;
	}
}
int main() {
	int tt;
	scanf("%d", &tt);
	int m, n;
	while (tt--) {
//		char s[260][12];
		map<string, int> code;
//		int c[260];
		int c, minlen = 999999;
		string s;
		scanf("%d%d", &m, &n);
		for (int i = 0; i < n; i++) {
		//	scanf("%d %s", &c[i], s[i]);
			cin >> c >> s;
			code[s] = c;
			if (minlen > s.size()) {
				minlen = s.size();
			}
		}
		string temp, tempBin, tempc;
		cin >> temp;
		tempBin = HexToBin(temp);
		int begin = 0, end = 1, len = 0;
		while(begin<tempBin.size()) {
			if (tempBin.size() - begin >= 9) {
				len = 9;
			}
			else break;
			temp = tempBin.substr(begin, len);
			begin += 9;
			if (check(temp)) {
				tempc += temp.substr(0, 8);
			}
		}
		int ans[200000], q = 0;
		begin = 0;
		end = 0;
		len = minlen;
		while (q<m) {
			int k = code[tempc.substr(begin, len)];
			if (k) {
				ans[q++] = k;
				begin += len;
				len = minlen;
			}
			else {
				len++;
			}
			
		}
		for (int i = 0; i < q; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
	}
}

/*
2
15 9
32 0100
33 11
100 1011
101 0110
104 1010
108 00
111 100
114 0111
119 0101
A6Fd021171c562Fde1
8 3
49 0001
50 01001
51 011
14DB24722698
*/