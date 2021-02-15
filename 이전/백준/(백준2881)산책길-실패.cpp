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
		산책로의 출발 x좌표와 같은 x좌표에 있는 나무중에
		그 나무의 y좌표가 산책로의 출발y좌표, 도착y좌표 사이에
		있으면 제거해야할 나무이다
		그런데 나무가 4,4 도착y좌표가 4,4이면 2번계산이된다.. 엄청난문제.. 이거어떻게없애지..
		->문제점의 요약 : 앞에서 제거한나무인데 뒤에서 또 제거할 수 있다..
		->모서리는 2번조사하게된다
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