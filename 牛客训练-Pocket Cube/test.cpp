#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int cube[10][10];
int temp[10][10];

int check() {
	for (int i = 1; i <= 6; i++) {
		int same = temp[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != temp[i][j])return 0;
		}
	}
	return 1;
}
int t1[5] = { 1,2,3,4,1 };
int t2[5] = { 1,6,3,5,1 };
int t3[5] = { 2,6,4,5,2 };

int turn1() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[1][1] = temp[5][1];
	d[1][2] = temp[5][2];
	d[6][1] = temp[1][1];
	d[6][2] = temp[1][2];
	d[3][4] = temp[6][1];
	d[3][3] = temp[6][2];
	d[5][1] = temp[3][4];
	d[5][2] = temp[3][3];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn2() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[1][3] = temp[5][3];
	d[1][4] = temp[5][4];
	d[6][3] = temp[1][3];
	d[6][4] = temp[1][4];
	d[3][2] = temp[6][3];
	d[3][1] = temp[6][4];
	d[5][3] = temp[3][2];
	d[5][4] = temp[3][1];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn3() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[2][1] = temp[5][2];
	d[2][2] = temp[5][4];
	d[6][3] = temp[2][1];
	d[6][1] = temp[2][2];
	d[4][4] = temp[6][3];
	d[4][3] = temp[6][1];
	d[5][2] = temp[4][4];
	d[5][4] = temp[3][3];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn4() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[2][3] = temp[5][1];
	d[2][4] = temp[5][3];
	d[6][4] = temp[2][3];
	d[6][2] = temp[2][4];
	d[4][2] = temp[6][4];
	d[4][1] = temp[6][2];
	d[5][1] = temp[4][2];
	d[5][3] = temp[4][1];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn5() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[1][2] = temp[4][2];
	d[1][4] = temp[4][4];
	d[2][2] = temp[1][2];
	d[2][4] = temp[1][4];
	d[3][2] = temp[2][2];
	d[3][4] = temp[2][4];
	d[4][2] = temp[3][2];
	d[4][4] = temp[3][4];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn6() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[1][1] = temp[4][1];
	d[1][3] = temp[4][3];
	d[2][1] = temp[1][1];
	d[2][3] = temp[1][3];
	d[3][1] = temp[2][1];
	d[3][3] = temp[2][3];
	d[4][1] = temp[3][1];
	d[4][3] = temp[3][3];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn7() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[5][1] = temp[1][1];
	d[5][2] = temp[1][2];
	d[1][1] = temp[6][1];
	d[1][2] = temp[6][2];
	d[6][1] = temp[3][4];
	d[6][2] = temp[3][3];
	d[3][4] = temp[5][1];
	d[3][3] = temp[5][2];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn8() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[5][3] = temp[1][3];
	d[5][4] = temp[1][4];
	d[1][3] = temp[6][3];
	d[1][4] = temp[6][4];
	d[6][3] = temp[3][2];
	d[6][4] = temp[3][1];
	d[3][2] = temp[5][3];
	d[3][1] = temp[5][4];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn9() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[5][2] = temp[2][1];
	d[5][4] = temp[2][2];
	d[2][1] = temp[6][3];
	d[2][2] = temp[6][1];
	d[6][3] = temp[4][4];
	d[6][1] = temp[4][3];
	d[4][4] = temp[5][2];
	d[4][3] = temp[5][4];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn10() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}

	d[5][1] = temp[2][3];
	d[5][3] = temp[2][4];
	d[2][3] = temp[6][4];
	d[2][4] = temp[6][2];
	d[6][4] = temp[4][2];
	d[6][2] = temp[4][1];
	d[4][2] = temp[5][1];
	d[4][1] = temp[5][3];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn11() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[4][2] = temp[1][2];
	d[4][4] = temp[1][4];
	d[1][2] = temp[2][2];
	d[1][4] = temp[2][4];
	d[2][2] = temp[3][2];
	d[2][4] = temp[3][4];
	d[3][2] = temp[4][2];
	d[3][4] = temp[4][4];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}

int turn12() {
	int d[10][10];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 4; j++) {
			d[i][j] = temp[i][j];
		}
	}
	d[4][1] = temp[1][1];
	d[4][3] = temp[1][3];
	d[1][1] = temp[2][1];
	d[1][3] = temp[2][3];
	d[2][1] = temp[3][1];
	d[2][3] = temp[3][3];
	d[3][1] = temp[4][1];
	d[3][3] = temp[4][3];

	for (int i = 1; i <= 6; i++) {
		int same = d[i][1];
		for (int j = 1; j <= 4; j++) {
			if (same != d[i][j])return 0;
		}
	}
	return 1;
}



int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 4; j++) {
				scanf("%d", &temp[i][j]);
			}
		}
		if (check()||turn1() || turn2() || turn3() || turn4() || turn5() || turn6() || turn7() || turn8() || turn9() || turn10() || turn11() || turn12()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}