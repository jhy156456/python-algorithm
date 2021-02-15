#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include<cstring>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
vector<ii> zeroLocation;
vector<ii> firstVirus;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int problem[9][9];
int temp[9][9];
int visited[9][9];
int n, m;
void virusGo() {
	queue<ii> q;
	for (int i = 0; i < (int)firstVirus.size(); i++) {
		q.push(ii(firstVirus[i].first, firstVirus[i].second));
		visited[firstVirus[i].first][firstVirus[i].second] = 1;
	}
	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int thereY = hereY + dy[i];
			int thereX = hereX + dx[i];
			if (thereY >= 0 && thereY < n && thereX >= 0 && thereX < m
				&& visited[thereY][thereX] !=1 
				&& problem[thereY][thereX] !=1) {
				visited[thereY][thereX] = 1;
				problem[thereY][thereX] = 2;
				q.push(ii(thereY, thereX));
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> problem[i][j];
			temp[i][j] = problem[i][j];
			if (problem[i][j] == 0) {
				zeroLocation.push_back(ii(i, j));

			}
			else if (problem[i][j] == 2) {
				firstVirus.push_back(ii(i, j));
			}
		}
	}
	int result = 0;
	for (int i = 0; i < (int)zeroLocation.size(); i++) {
		for (int j = i+1; j < (int)zeroLocation.size(); j++) {
			for (int k = j+1; k <(int) zeroLocation.size(); k++) {
				problem[zeroLocation[i].first][zeroLocation[i].second]=1;
				problem[zeroLocation[j].first][zeroLocation[j].second] = 1;
				problem[zeroLocation[k].first][zeroLocation[k].second] = 1;
				virusGo();
				int zeroCount = 0;
				for (int l = 0; l < n; l++) {
					for (int h = 0; h < m; h++) {
						if (problem[l][h] == 0) {
							zeroCount++;
						}
						problem[l][h] = temp[l][h];
					}
				}
				memset(visited, 0, sizeof(visited));
				if (result < zeroCount) result = zeroCount;
			}
		}
	}
	cout << result << endl;
}