#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int n;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int problem[21][21];
bool visited[21][21];
bool compare(pair<int, pair<int, int>>&a, pair<int, pair<int, int>>&b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	if (a.second.first != b.second.first) {
		return a.second.first < b.second.first;
	}
	return a.second.second < b.second.second;
}
vector<iii> eatFishLocation;
void bfs(int y, int x, int sharkSize, int length) {
	visited[y][x] = 1;
	queue<pair<ii, int>> q;
	q.push(pair<ii, int>(ii(y, x), length));
	while (!q.empty()) {
		ii front = q.front().first;
		int length = q.front().second;
		if (problem[front.first][front.second]< sharkSize
			&& problem[front.first][front.second] != 0) {
			//작은거리부터 순차적으로 벡터에 쌓일것
			eatFishLocation.push_back(iii(length, ii(front.first, front.second)));
		}
		q.pop(); length++;
		for (int i = 0; i < 4; i++) {
			int thereY = front.first + dy[i];
			int thereX = front.second + dx[i];
			if (!visited[thereY][thereX]
				&& problem[thereY][thereX] <= sharkSize
				&& thereY <n && thereY >= 0
				&& thereX <n && thereX >= 0) {
				visited[thereY][thereX] = 1;
				q.push(pair<ii, int>(ii(thereY, thereX), length));
			}
		}
	}
}
int main() {
	cin >> n;
	ii firstSharkLocation;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> problem[i][j];
			if (problem[i][j] == 9) {
				firstSharkLocation = { i,j };
			}
		}
	}
	bfs(firstSharkLocation.first,
		firstSharkLocation.second, 2, 0);
	problem[firstSharkLocation.first][firstSharkLocation.second] = 0;
	int sharkSize = 2;
	int eatFishCount = 0;
	int results = 0;
	while (eatFishLocation.size() != 0) {
		//y가 작은거찾장
		//y가 같을 수도 있으니까 그러면 x가 작은것도찾장
		//하지만 x가 같은게 먼저 나온다면?
		//y가 작은거에서 걸러질것
		sort(eatFishLocation.begin(),
			eatFishLocation.end()
			, compare);
		eatFishCount++;
		if (sharkSize == eatFishCount) {
			sharkSize++;
			eatFishCount = 0;
		}
		int y = eatFishLocation[0].second.first;
		int x = eatFishLocation[0].second.second;
		int minLength = eatFishLocation[0].first;
		results += minLength;
		memset(visited, 0, sizeof(visited));
		eatFishLocation.clear();
		problem[y][x] = 0;
		bfs(y, x, sharkSize, 0);
	}
	cout << results << endl;
}