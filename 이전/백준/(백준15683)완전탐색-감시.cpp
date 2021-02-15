#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n, m;
int problem[8][8];
vector<ii> cctv;
vector<vi> cctvRotation(8);
int cctvGamsiProblem[8][8];
vi results;
int cctvCount;
int minValue = 100000;
//0
void onSeven(int depth) {
	for (int j = 0; j < (int)cctvRotation[depth].size(); j++) {
		if (cctvRotation[depth][j] == 1) {
			for (int k = cctv[depth].second + 1; k < m; k++) {
				if (problem[cctv[depth].first][k] == 6) {
					break;
				}
				problem[cctv[depth].first][k]++;
			}
		}
		if (cctvRotation[depth][j] == 2) {
			for (int k = cctv[depth].first - 1; k >= 0; k--) {
				if (problem[k][cctv[depth].second] == 6) {
					break;
				}
				problem[k][cctv[depth].second] ++;
			}
		}
		if (cctvRotation[depth][j] == 3) {
			for (int k = cctv[depth].second - 1; k >= 0; k--) {
				if (problem[cctv[depth].first][k] == 6) {
					break;
				}
				problem[cctv[depth].first][k] ++;
			}
		}
		if (cctvRotation[depth][j] == 4) {
			for (int k = cctv[depth].first + 1; k <n; k++) {
				if (problem[k][cctv[depth].second] == 6) {
					break;
				}
				problem[k][cctv[depth].second]++;
			}
		}
	}
}
void offSeven(int depth) {
	for (int j = 0; j < (int)cctvRotation[depth].size(); j++) {
		if (cctvRotation[depth][j] == 1) {
			for (int k = cctv[depth].second + 1; k < m; k++) {
				if (problem[cctv[depth].first][k] == 6) {
					break;
				}
				problem[cctv[depth].first][k]--;
			}
		}
		if (cctvRotation[depth][j] == 2) {
			for (int k = cctv[depth].first - 1; k >= 0; k--) {
				if (problem[k][cctv[depth].second] == 6) {
					break;
				}
				problem[k][cctv[depth].second]--;
			}
		}
		if (cctvRotation[depth][j] == 3) {
			for (int k = cctv[depth].second - 1; k >= 0; k--) {
				if (problem[cctv[depth].first][k] == 6) {
					break;
				}
				problem[cctv[depth].first][k]--;
			}
		}
		if (cctvRotation[depth][j] == 4) {
			for (int k = cctv[depth].first + 1; k <n; k++) {
				if (problem[k][cctv[depth].second] == 6) {
					break;
				}
				problem[k][cctv[depth].second]--;
			}
		}
		cctvRotation[depth][j]++;
		if (cctvRotation[depth][j] == 5) cctvRotation[depth][j] = 1;
	}
}

void dfs(int depth) {
	if (depth == cctvCount) {
		int gamsiCount = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (problem[i][j] == 0) {
					gamsiCount++;
				}
			}
		}
		if (minValue > gamsiCount) { minValue = gamsiCount; }
		
		return;
	}
	//4방향으로 칠해봅시당
	for (int i = 0; i < 4; i++) {
		//현재 보고있는 방향으로 칠해봅시당
		//처음상태는 문제에서 주어진 방향
		onSeven(depth);
		depth++;
		dfs(depth);
		depth--;
		offSeven(depth);
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> problem[i][j];
			if (problem[i][j] != 6 && problem[i][j] != 0) {
				cctv.push_back(ii(i, j));
				if (problem[i][j] == 1) {
					cctvRotation[cctvCount].push_back(1);
				}
				else if (problem[i][j] == 2) {
					cctvRotation[cctvCount].push_back(1);
					cctvRotation[cctvCount].push_back(3);
				}
				else if (problem[i][j] == 3) {
					cctvRotation[cctvCount].push_back(1);
					cctvRotation[cctvCount].push_back(2);
				}
				else if (problem[i][j] == 4) {
					cctvRotation[cctvCount].push_back(1);
					cctvRotation[cctvCount].push_back(2);
					cctvRotation[cctvCount].push_back(3);
				}
				else {
					cctvRotation[cctvCount].push_back(1);
					cctvRotation[cctvCount].push_back(2);
					cctvRotation[cctvCount].push_back(3);
					cctvRotation[cctvCount].push_back(4);
				}
				cctvCount++;



			}
		}
	}

	dfs(0);
	cout << minValue << endl;
}