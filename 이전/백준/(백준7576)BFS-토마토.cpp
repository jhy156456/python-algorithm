#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int n,m;
int answerCount = 0;
vector<vector<int>>problems;
vector<vector<int>>visited; //거리를위함
vector<pair<int, int>> order;
int dy[4] = {-1,1,0,0};//상,하,좌,우
int dx[4] = {0,0,-1,1};
void bfs() {
	
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++) { //초기 1인거 전부 큐에 넣어둔다
		for (int j = 0; j < m; j++) {
			if (problems[i][j] == 1) { 
				q.push(make_pair(i, j)); 
				visited[i][j] = 1;//일수를 1일로 초기화한다.
			}
		}
	}
	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();
		//order.push_back(make_pair(hereY, hereX));
		for (int i = 0; i < 4; i++) {//모든 인접한 정점을 검사한다
			int goY = hereY + dy[i];
			int goX = hereX + dx[i];
			if (goY < 0 || goX < 0 || goY >= n || goX >= m 
				|| problems[goY][goX]!=0
				|| visited[goY][goX]!=0) //방문한적이 있거나 해당 좌표가 0이 아니거나 경계값을 벗어난다면 다른좌표 검색
				continue;
			q.push(make_pair(goY, goX));
			visited[goY][goX] = visited[hereY][hereX]+1;
		}
	}
}
int main() {
	cin >> m >> n; //n이 세로 m이 가로(행)
	problems = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> problems[i][j];
			if (problems[i][j] == -1) visited[i][j] = -1;//-1에 둘러쌓여있는 토마토를 찾기 위함
		}
	}
	bfs();
	int max = 0;
	int minusCheck = 0;
	for (int i = 0; i < n; i++) { //초기 1인거 전부 큐에 넣어둔다
		for (int j = 0; j < m; j++) {
			if (visited[i][j] > max) { 
				max = visited[i][j]; 
			}
			if (visited[i][j] == 0) minusCheck = 1; //-1값이였던것 제외하고 한번도 못간곳이있다면
		}
	}
	if (minusCheck == 1) cout << -1 << endl;
	else cout << max-1 << endl;
}