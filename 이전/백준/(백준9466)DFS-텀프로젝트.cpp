#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int T;
vector<int> problems;
vector<int> cycle;
vector<int> visited;
vector<int>depth;
int dfs(int here, int step, int level) {
	visited[here] = true;
	int there = problems[here];
	cycle[here] = step; //같은 사이클(출발정점)에 넣어놓고 dfs
	depth[here] = level++;
	if (!visited[there]) {//가야할 곳에 방문하지않았다면
		int hi= dfs(there, step, level);
		return hi;
	}
	else { //가야할 곳이 방문 한적이 있다면 같은 사이클에 속해있는애인지 비교해야함
		if (cycle[there] == step) { 
			//(depth[there]==1)//같은 사이클에 있는애이고 처음상태로 돌아온것이라면
			return level - depth[there];
		}
		else { //처음 상태가 아닌 무한루프이거나 다른노드가 그 팀에 끼어드려고 한다면
			return 0;
		}
	}
	return 0;
}
int main() {
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		problems = vector<int>(n+1);
		cycle = vector<int>(n+1);
		visited = vector<int>(n+1);
		depth = vector<int>(n+1);
		for (int i = 1; i <= n; i++)cin >> problems[i];

		int answer = 0;

		for (int i = 1; i <= n; i++) {
			int level = 0;
			cycle[i] = i; //노드 시작점 기록
			if (!visited[i]) {
				answer += dfs(i,i,level+1);
			}
		}
		cout << n-answer << endl;
	}

}