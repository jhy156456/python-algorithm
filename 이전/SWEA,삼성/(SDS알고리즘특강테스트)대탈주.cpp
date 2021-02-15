#include <iostream>
int dN[1001] = { 0 };
int dM[51] = { 0 };

int main()
{
	using namespace std;
	int T, N, M = 0;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int ans = 0;
		bool findAns = false;
		int pN = 0;
		cin >> N >> M;
		for (int j = 1; j <= M; j++)
		{
			cin >> dM[j];
			pN += dM[j];
		}
		for (int k = 1; k <= N; k++)
		{
			cin >> dN[k];
		}
		for (int k = 1; k <= N; k++)
		{
			int cM[51] = { 0 };
			for (int j = k; j < k + pN; j++)
			{
				if (j > N) {
					findAns = false;
					break;
				}
				cM[dN[j]]++;
				if (cM[dN[j]]>dM[dN[j]] || dM[dN[j]] == 0)
				{
					findAns = false;
					break;
				}
				findAns = true;
			}
			if (findAns)
			{
				ans = k;
			}
		}
		cout << "#" << i << " " << ans << endl;
	}
	return 0;
}