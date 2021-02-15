#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
// 그래프의 인접 리스트 표현
vector<vector<int> > adj;
// 각 정점을 방문했는지 여부를 나타낸다
vector<bool> visited;
int n, m, firstNumber;
void dfs(int here) {
	visited[here] = true;
	cout << here << " ";
	/*
	내 그래프는 인접리스트이고 0행의과 0열들은 -1로 초기화되어있다
	따라서 인접리스트의 사이즈들은 내가 원하는 사이즈보다 1크게되기때문에
	i< adj[here].size()로 해야 배열접근 런타임에러가 나지 않는다.
	ex) (1,2),(1,3),(1,4)의 경로들이 주어질때 i의 탐색범위는 1,2,3총 3번이 되어야하고
	i의 인덱스0은 -1이기때문에 i=1부터 4전까지 1,2,3을 탐색해야한다.
	*/
	int size = (int)adj[here].size();
	for (int i = 1; i < size; i++) { 
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}
// start 에서 시작해 그래프를 너비 우선 탐색하고 각 정점의 방문 순서를 반환한다.
vector<int> bfs(int start) {
	// 각 정점의 방문 여부
	vector<bool> discovered(adj.size()+1, false);
	// 방문할 정점 목록을 유지하는 큐
	queue<int> q;
	// 정점의 방문 순서
	vector<int> order;
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		// here를 방문한다.
		order.push_back(here);
		// 모든 인접한 정점을 검사한다.
		int size = (int)adj[here].size();
		for (int i = 1; i < size; i++) {
			int there = adj[here][i];
			// 처음 보는 정점이면 방문 목록에 집어넣는다.
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	return order;
}
int main() {
	
	cin >>n>>m>>firstNumber;
	adj.resize(n+1);
	visited.resize(n+1);

	for (int i = 1; i <= n;i++) adj[i].push_back(-1);
	while(m--){
		int j=0,k=0;
		cin >> j >> k;
		adj[k].push_back(j);//양방향그래프
		adj[j].push_back(k);
	}
	//정점번호의 크기순서로 입력값이 들어오는게 아닌것같다
	//문제에서 작은크그이
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	dfs(firstNumber);
	cout << endl;
	vector<int> orders = bfs(firstNumber);
	for (int i = 0; i < orders.size(); i++)cout << orders[i] << " ";
	cout << endl;
}