#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vii> vvii;
int v, e, n, m;
vvii adj; vi fire; vi fired;  vi dist;
void shortestPath(int start) {
	dist[start] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push(ii(0, start));
	while (!pq.empty()) {
		ii pqU = pq.top(); pq.pop();
		if (pqU.first > dist[pqU.second]) continue;
		//pqU�� �������������������� ���������� ���Ѵ�
		//�������� -> pqU -> ������V�� �������?
		//�������� -> pqU����ġ���ʰ� ->pqU�� ������V�ΰ��°� �������?
		for (int i = 0; i < (int)adj[pqU.second].size(); i++) {
			
			//��������Ʈ���� first : ���� second : �Ÿ�
			//pq���� first : �Ÿ� second : ����
			ii adjV = adj[pqU.second][i];
			if (dist[pqU.second]+ adjV.second < dist[adjV.first]) {
				dist[adjV.first] = dist[pqU.second] + adjV.second;
				pq.push(ii(dist[adjV.first], adjV.first));
			}
		}
	}

}
int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> v >> e >> n >> m;
		fire.clear();
		fired.clear();
		dist.clear();
		adj.clear();
		adj.resize(v + 2); //v+1���� ������ ���������� �������ε������� �����ǹ�ȣ
		dist.assign(v + 2, 10000);

		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(ii(b, c));
			adj[b].push_back(ii(a, c));
		}
		for (int i = 0; i < n; i++) {
			int a; cin >> a; fired.push_back(a);
		}
		for (int i = 0; i < m; i++) {
			int a; cin >> a; fire.push_back(a);
		}
		//�ҹ漭�� ������ ������ �����Ѵ�
		for (int i = 0; i < (int)fire.size(); i++) {
			adj[v + 1].push_back(ii(fire[i], 0));
		}
		//������ �������������� ���ͽ�Ʈ��˰��� ����
		shortestPath(v + 1);
		int sum = 0;
		for (int i = 0; i < (int)fired.size(); i++) {
			sum += dist[fired[i]];
		}
		cout << sum << endl;
	}
}