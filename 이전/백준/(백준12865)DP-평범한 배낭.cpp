#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> ii;
int n, k,dp[1000001][101];
vector<ii> problem;
//capacity : ������� �賶�� ����ִ� �뷮 ��
//value : �賶�� �� ��ġ��
int pack(int capacity, int itemNumber) {
	if (itemNumber == n+1) return 0;
	int &ret = dp[capacity][itemNumber];
	if (ret != -1)return ret;
	//�ȳ־��
	ret = pack(capacity, itemNumber + 1);
	//�־��
	if (capacity >= problem[itemNumber].first) {
		ret = max(ret, pack(capacity - problem[itemNumber].first, itemNumber + 1) + problem[itemNumber].second);
	}
	return ret;

}
int main() {
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	problem.push_back(ii(0, 0));
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		problem.push_back(ii(a, b));
	}
	cout << pack(k,1) << endl;

}