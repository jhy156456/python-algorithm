#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
int n;
vvi graph;
vvi visited;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<ii> q;
vector<ii> bfs(int y, int x) {
	vii results;
	visited[y][x] = true;
	q.push({ y,x });

	while (!q.empty()) {
		int hereY = q.front().first, hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int thereY = hereY + dy[i], thereX = hereX + dx[i];
			if (thereY >= 0 && thereY < r && thereX >= 0 && thereX < c) {
				if (visited[thereY][thereX] && graph[hereY][hereX] == graph[thereY][thereX]) {
					q.push({ thereY,thereX });
					visited[thereY][thereX] = true;
					results.push_back({ thereY,thereX });
				}
			}
		}
	}
	
}
int r, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	graph = vvi(r, vi(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			char a;
			cin >> a;
			if (a == '.') {
				//땅
				graph[i][j] = 0;
			}
			else {
				//미네랄
				graph[i][j] = 1;
			}
			
		}
	}
	cin >> n;
	vi problems;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		problems.push_back(a);
	}


	for (int i = 0; i < n; i++) {
		int row = r-problems[i];
		if (i % 2 == 0) {
			//왼쪽에서 오른쪽
			for (int j = 0; j < c; j++) {
				if (graph[row][j] == 1) {
					//미네랄을 만났다
					graph[row][j] = 0;
					//미네랄을 파괴하고
					vvii location;
					//방문 기록을 초기화하고
					visited.clear();

					//해당 미네랄의 클러스터를 구한다.
					location.push_back(bfs(row, j));

					//중력에 의해 아래로 내려갈 수 있기 떄문에 해당 공격 지점부터 아래부분의 
					
					
				}
			}
		}
		else {
			//오른쪽에서 왼쪽
			for (int j = c-1; j >= 0; j++) {
				if (graph[row][j] == 1) {
					//미네랄을 만났다

				}
			}
		}

	}

	
}


/*



0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 1 0 1 1 0
0 0 0 1 1 1 0 0
0 0 1 1 1 0 0 0
0 0 1 0 1 1 1 0
0 0 1 0 0 0 1 0
0 1 1 1 0 0 1 0


6

0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 x 0 x 1 0
0 0 0 x 1 1 0 0
0 0 1 x 1 1 0 0
0 0 1 1 1 1 1 0
0 0 1 1 0 0 1 0
0 1 1 1 0 0 1 0











*/