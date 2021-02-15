#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> ii;
int n, p;
vector<int> treesY[300000];
vector<ii> startTrail(100000);
vector<ii> endTrail(100000);
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		treesY[b].push_back(a);
	}
	cin >> p;
	for (int i = 0; i < p; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		startTrail[i].first = a; startTrail[i].second = b;
		endTrail[i].first = c; endTrail[i].second = d;
	}

	for (int i = 0; i < p; i++) {
		int result = 0;
		/*
		��å���� ��� x��ǥ�� ���� x��ǥ�� �ִ� �����߿�
		�� ������ y��ǥ�� ��å���� ���y��ǥ, ����y��ǥ ���̿�
		������ �����ؾ��� �����̴�
		�׷��� ������ 4,4 ����y��ǥ�� 4,4�̸� 2������̵ȴ�.. ��û������.. �̰ž�Ծ�����..
		->�������� ��� : �տ��� �����ѳ����ε� �ڿ��� �� ������ �� �ִ�..
		->�𼭸��� 2�������ϰԵȴ�
		*/

		for (int j = 0; j < (int)treesY[startTrail[i].second].size(); j++) {
			if (treesY[startTrail[i].second][j] >= startTrail[i].first
				&& treesY[startTrail[i].second][j] <= endTrail[i].first) {
				result++;
			}
		}
		for (int j = 0; j < (int)treesY[endTrail[i].second].size(); j++) {
			if (treesY[endTrail[i].second][j] >= startTrail[i].first
				&& treesY[endTrail[i].second][j] <= endTrail[i].first) {
				result++;
			}
		}
		for (int j = startTrail[i].second+1; j < endTrail[i].second; j++) {
			for (int k = 0; k < (int)treesY[j].size(); k++) {
				if (treesY[j][k] == startTrail[i].first
					|| treesY[j][k] == endTrail[i].first) {
					result++;
				}
				if (treesY[j][k] > endTrail[i].first) {
					break;
				}
			}
		}
		cout << result << endl;
	}
}