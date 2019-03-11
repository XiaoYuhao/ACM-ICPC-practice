#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main()
{

	int n, k, i, q, j;
	char s[2];
	while (scanf("%d%d", &n, &k) != EOF)
	{
		priority_queue<int, vector<int>, greater<int>> qi;
		for (i = 1; i <= n; i++)
		{
			scanf("%s", &s);
			if (s[0] == 'I')
			{
				scanf("%d", &q);
				qi.push(q);
				if (qi.size() > k)
				{
					qi.pop();
				}
			}
			if (s[0] == 'Q')
			{
				printf("%d\n", qi.top());
			}

		}

	}
	return 0;
}