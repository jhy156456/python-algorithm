#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
int dy[4] = {-1,1,0,0}; //상,하,좌,우
int dx[4] = {0,0,-1,1};
int visited[100][100];
int problems[100][100];
vector<ii> alliance[1250];
int n, l, r;
void dfs(int y, int x, int yunhap) {
	visited[y][x] = 1;
	alliance[yunhap].push_back(ii(y, x));
	for (int i = 0; i < 4; i++) {
		int thereY = y + dy[i];
		int thereX = x + dx[i];
		if (thereY >= n || thereY < 0 || thereX >= n || thereX < 0) continue;
		if (!visited[thereY][thereX]
			&& l <= abs(problems[y][x] - problems[thereY][thereX])
			&& abs(problems[y][x] - problems[thereY][thereX])<=r) {
			dfs(thereY, thereX,yunhap);
		}
	}
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> problems[i][j];
		}
	}
	int count = 0;
	while (true) {
		int yunhap = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int ifin = 0;
				for (int k = 0; k < 4; k++) {
					int thereY = i + dy[k];
					int thereX = j + dx[k];
					if (thereY >= n || thereY < 0 || thereX >= n || thereX < 0)continue;
					if (!visited[thereY][thereX]
						&& l <= abs(problems[i][j] - problems[thereY][thereX])
						&& abs(problems[i][j] - problems[thereY][thereX]) <= r) {
						if (!visited[i][j]) {
							visited[i][j] = 1;
							alliance[yunhap].push_back(ii(i, j));
						}			
						dfs(thereY, thereX, yunhap);
						ifin = 1;
					}
				}
				if (ifin == 1) {
					yunhap++;
					ifin = 0;
				}
			}
		}
		if (yunhap == 0)break;
		//연합측정
		for (int i = 0; i < (int)yunhap; i++) {
			int sum = 0;
			for (int j = 0; j < (int)alliance[i].size(); j++) {
				sum += problems[alliance[i][j].first][alliance[i][j].second];
			}
			int newPeople = (int)(sum / (int)alliance[i].size());
			for (int j = 0; j < (int)alliance[i].size(); j++) {
				problems[alliance[i][j].first][alliance[i][j].second] = newPeople;
			}
		}
		count++;
		for (int i = 0; i < yunhap; i++) {
			alliance[i].clear();
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << count << endl;
	return 0;
}