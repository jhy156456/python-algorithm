#include<iostream>
#include<algorithm>
using namespace std;
int n;
int sum[501][502];
int triangle[501][501];
int result = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> triangle[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			sum[i][j] = triangle[i][j] + max(sum[i - 1][j - 1], sum[i - 1][j]);
	}


	for (int i = 1; i <= n; i++)
		result = max(sum[n][i], result);
	cout << result << endl;
	return 0;
}
