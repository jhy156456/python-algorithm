#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include<cstring>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
vector<ii> people, stair;
int problem[12][12];
vector<pair<ii, int>> selectCase;
int t, n;
int result = 1000000;
ii stairGo[80][50];
void r(int depth) {
	int kasa = 0;
	if (depth == (int)people.size()) {
		int stairA = 0;
		int stairB = 0;
		int second = 0;
		memset(stairGo, 0, sizeof(stairGo));
		int push = 0;
		while (true) {
			second++;

			for (int i = 0; i < (int)selectCase.size(); i++) {
				int distance = abs(selectCase[i].first.first - stair[selectCase[i].second - 1].first) +
					abs(selectCase[i].first.second - stair[selectCase[i].second - 1].second);
				//그 초에 계단에 도착했다
				if (distance == second) {
					push++;
					//1번계단이였고 계단 내려가고있는애가 3명이하라면
					if (selectCase[i].second == 1 && stairA < 3) {
						stairA++;
						stairGo[second][i] = ii(problem[stair[selectCase[i].second - 1].first][stair[selectCase[i].second - 1].second] + 1, 1);
					}
					//1번계단, 계단내려가고있는애 3명이상
					else if (selectCase[i].second == 1 && stairA >= 3) {
						stairGo[second][i] = ii(10001, 1);
					}
					//2번계단이였고 계단 내려가고있는애가 3명이하라면
					else if (selectCase[i].second == 2 && stairB < 3) {
						stairB++;
						stairGo[second][i] = ii(problem[stair[selectCase[i].second - 1].first][stair[selectCase[i].second - 1].second] + 1, 2);
					}
					//2번계단, 계단내려가고있는애 3명이상
					else if (selectCase[i].second == 2 && stairB >= 3) {
						stairGo[second][i] = ii(10002, 2);
					}
				}
			}
			//사전작업완료
			int zeroCount = 0;
			for (int i = 0; i < (int)selectCase.size(); i++) {

				if (stairGo[second - 1][i].first != 10001 && stairGo[second - 1][i].first != 10002 && stairGo[second - 1][i].first != 0) {
					stairGo[second][i].first = stairGo[second - 1][i].first - 1;
					stairGo[second][i].second = stairGo[second - 1][i].second;

				}
				else if (stairGo[second - 1][i].first == 10001 && stairA < 3) {
					stairA++;
					stairGo[second][i].first = problem[stair[0].first][stair[0].second];
					stairGo[second][i].second = 1;
				}
				else if (stairGo[second - 1][i].first == 10001 && stairA >= 3) {
					stairGo[second][i].first = stairGo[second - 1][i].first;
					stairGo[second][i].second = stairGo[second - 1][i].second;
				}

				else if (stairGo[second - 1][i].first == 10002 && stairB < 3) {
					stairB++;
					stairGo[second][i].first = problem[stair[1].first][stair[1].second];
					stairGo[second][i].second = 2;
				}
				else if (stairGo[second - 1][i].first == 10002 && stairB >= 3) {
					stairGo[second][i].first = stairGo[second - 1][i].first;
					stairGo[second][i].second = stairGo[second - 1][i].second;
				}
				else if (stairGo[second][i].first == 0) {
					zeroCount++;
				}
			}
			for (int i = 0; i < (int)selectCase.size(); i++) {
				if (stairGo[second][i].first == 1) {
					if (stairGo[second][i].second == 1) stairA--;
					if (stairGo[second][i].second == 2) stairB--;
				}
			}
			if (zeroCount == (int)selectCase.size() && second > 3 && (int)selectCase.size() == push) {
				if (second < result) {
					result = second;

					/*		for (int a = 0; a < second; a++) {
					for (int b = 0; b < (int)selectCase.size(); b++) {
					cout << stairGo[a][b].first << " ";
					}
					cout << endl;
					}
					cout << endl;*/
				}
				break;
			}
		}
		return;
	}
	selectCase.push_back(pair<ii, int>(people[depth], 1)); depth++; r(depth); depth--;
	selectCase.pop_back();
	selectCase.push_back(pair<ii, int>(people[depth], 2)); depth++; r(depth); depth--;
	selectCase.pop_back();
}
int main() {
	cin >> t;
	int hi = 1;
	while (t--) {
		cin >> n;
		memset(problem, 0, sizeof(problem));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> problem[i][j];
				if (problem[i][j] == 1) {
					people.push_back(ii(i, j));
				}
				else if (problem[i][j] != 0 && problem[i][j] != 1) {
					stair.push_back(ii(i, j));
				}
			}
		}
		selectCase.push_back(pair<ii, int>(people[0], 1)); r(1);
		selectCase.pop_back();
		selectCase.push_back(pair<ii, int>(people[0], 2)); r(1);
		cout << "#" << hi << " " << result - 1 << endl;
		hi++;
		selectCase.clear(); people.clear(); stair.clear(); result = 10000;

	}
}