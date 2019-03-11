#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 20000 + 5;
int f[maxn], r[maxn], num[20], vis[20];
int n, flag, tot;
char s[maxn];
void init()
{
	for (int i = 0; i<maxn; i++)
	{
		f[i] = i;
		r[i] = 0;
	}
	flag = 0;
}
int find(int a)
{
	if (f[a] != a)
	{
		int fa = f[a];
		f[a] = find(fa);
		r[a] ^= r[fa];//由于r[a]本来就是a^fa，而路劲压缩使得r[fa]=fa^root，所以此时r[a]=a^root; 
	}
	return f[a];
}
int link(int a, int b, int c)
{
	int fa = find(a), fb = find(b);
	if (fa == fb)
	{
		if ((r[a] ^ r[b]) != c)//冲突，同根的a,b的r[a]^r[b]就是a^b 
			return 0;
		return 1;
	}
	if (fa == n)
		swap(fa, fb);
	f[fa] = fb;
	r[fa] = r[a] ^ r[b] ^ c;
	return 1;
}
int query()
{
	int i, j, ans = 0;
	memset(vis, 0, sizeof(vis));
	for (i = 1; i <= tot; i++)
	{
		if (vis[i] == 1)
			continue;
		int root = find(num[i]);
		int sum = 0;
		for (j = 1; j <= tot; j++)
			if (!vis[j] && root == find(num[j]))
			{
				ans ^= r[num[j]];
				sum++;
				vis[j] = 1;
			}
		if (root != n&&sum % 2 == 1)//基数个同根节点异或误解 
			return -1;
	}
	return ans;
}
int main()
{
	int m, kase = 0;
	while (~scanf("%d%d", &n, &m), m + n)
	{
		int i, p, q, v, cnt = 0;
		printf("Case %d:\n", ++kase);
		init();
		while (m--)
		{
			scanf("%s", s);
			if (flag)
			{
				gets_s(s);
				continue;
			}
			if (s[0] == 'I')
			{
				cnt++;
				gets_s(s);
				if (sscanf(s, "%d%d%d", &p, &q, &v) == 2)
				{
					v = q;
					q = n;
				}
				if (!link(p, q, v))
				{
					printf("The first %d facts are conflicting.\n", cnt);
					flag = 1;
				}
			}
			else
			{
				scanf("%d", &tot);
				for (i = 1; i <= tot; i++)
					scanf("%d", &num[i]);
				int ans = query();
				if (ans == -1)
					printf("I don't know.\n");
				else
					printf("%d\n", ans);
			}
		}
		printf("\n");
	}
}