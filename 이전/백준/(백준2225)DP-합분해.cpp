#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
vvll memo;
//D[n][k] : n�Ǽ��� ���� k���� ���ؼ� ���� �� �ִ� ����Ǽ�
ll sumNCase(int n, int k) {
	if (k == 1) return 1;
	ll &ret = memo[n][k];
	if (ret != -1) return ret;
	ll sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += (sumNCase(i, k - 1));
		sum %= 1000000000;
	}
	return ret = sum;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	memo = vvll(n + 1, vll(k + 1, -1));
	cout << sumNCase(n, k) << endl;
}