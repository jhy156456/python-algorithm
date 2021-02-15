#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
#define INF 100000 //10억
int n, m;
int start, goEnd;
vector<int> dist;
vector<int> touch;
vector<vector<ii>> adj;
vector<vector<ii>> reverseAdj;
vector<int> goEndAdj;
vector<vector<bool>> check;
//pair<시작정점-해당정점까지의 거리, 정점의번호>
void shortestPath(int s) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int d = front.first; //그 정점까지의 거리
		int u = front.second;//검사 할 정점
		if (d > dist[u]) continue;
		for (int i = 0; i < (int)adj[u].size(); i++) {
			ii v = adj[u][i];
			if (dist[u] + v.second < dist[v.first] && !check[u][v.first]) {
				dist[v.first] = dist[u] + v.second;
				touch[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}
void bfs() {
	queue<int> q;
	q.push(goEnd);

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == start) continue;
		for (int i = 0; i < (int)reverseAdj[here].size(); i++) {
			int there = reverseAdj[here][i].first;
			int thereCost = reverseAdj[here][i].second;
			if (dist[here] == dist[there] + thereCost) { 
				check[there][here] = true; 
				q.push(there); 
			}

		
		}
	}
}
int main() {
	int n, m;
	
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> start >> goEnd;
		adj = vector<vector<ii>>(n, vector<ii>());
		reverseAdj = vector<vector<ii>>(n, vector<ii>());
		goEndAdj = vector<int>();
		dist = vector<int>(n, INF);
		touch = vector<int>(n, 1);
		check = vector<vector<bool>>(n, vector<bool>(n, false));

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (b == goEnd)goEndAdj.push_back(a);
			reverseAdj[b].push_back(make_pair(a, c));
			adj[a].push_back(make_pair(b, c));
		}
		shortestPath(start);

		//int firstgoEnd = dist[goEnd];
		if (dist[goEnd] == INF) {
			cout << -1 << endl;
			continue;
		}
		bfs();
		fill(dist.begin(), dist.end(), INF);
		shortestPath(start);
		if (dist[goEnd] == INF)cout << -1 << endl;
		else cout << dist[goEnd] << endl;

	}
	return 0;
}