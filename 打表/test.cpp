#include<iostream>
#include<algorithm>

using namespace std;
int mapp[1024][1024];

int sum = 0;
int n;
void dfs(int x,int y,int step) {
	if (step > n)return;
	mapp[x][y] = 1;
	int xx, yy;
	xx = x - 1;
	yy = y - 2;
//	if(mapp[xx][yy]==0)
	dfs(xx, yy, step + 1);
	xx = x - 2;
	yy = y - 1;
//	if (mapp[xx][yy] == 0)
	dfs(xx, yy, step + 1);
	xx = x - 2;
	yy = y + 1;
//	if (mapp[xx][yy] == 0)
	dfs(xx, yy, step + 1);
	xx = x - 1;
	yy = y + 2;
//	if (mapp[xx][yy] == 0)
	dfs(xx, yy, step + 1);
	xx = x + 1;
	yy = y + 2;
//	if (mapp[xx][yy] == 0)
	dfs(xx, yy, step + 1);
	xx = x + 2;
	yy = y + 1;
//	if (mapp[xx][yy] == 0)
	dfs(xx, yy, step + 1);
	xx = x + 2;
	yy = y - 1;
//	if (mapp[xx][yy] == 0)
	dfs(xx, yy, step + 1);
	xx = x + 1;
	yy = y - 2;
//	if (mapp[xx][yy] == 0)
	dfs(xx, yy, step + 1);

	return;
}

int summ() {
	int ret = 0;
	for (int i = 0; i < 1024; i++) {
		for (int j = 0; j < 1024; j++) {
			if (mapp[i][j] == 1) {
				ret++;
			}
		}
	}
	return ret;
}

int main() {
	for (int i = 1; i <= 100; i++) {
		sum = 0;
		n = i;
		memset(mapp, 0, sizeof(mapp));
		dfs(512, 512, 0);
		cout << i << "->" << summ() << endl;
	}
	return 0;
}