#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		int p = s.length() - 1;
		//string::iterator sit;
		//sit = s.end()-1;
		char temp;
		for (int i = s.length(); i >= 0; i--) {
			//cout << s[i] << endl;
			if (s[i] >= 'A'&&s[i] <= 'Z') {
				temp = s[i];
				s.erase(i, 1);
				s.insert(p, 1, temp);
				p--;
			}
		}
		cout << s << endl;
	}
	return 0;
}