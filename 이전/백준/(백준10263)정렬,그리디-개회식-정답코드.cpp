#include <cstdio>
#include <algorithm>

using namespace std;

int n, ans;
int d[100001] = { 0, };
bool cmp(int p1, int p2) {
	return p1 > p2;
}
int main()
{
	scanf("%d", &n);
	ans = n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
	}
	sort(d + 1, d + n + 1, cmp);
	for (int i = 0; i < ans; i++)
	{
		if (ans > i + d[i + 1])
		{
			ans = i + d[i + 1];
		}
	}
	printf("%d", ans);
}