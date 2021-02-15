#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
#define INF 100000 //10��
int n, m;
vector<int> dist;
vector<int> touch;
vector<vector<ii>> adj;
vector<int> endAdj;
priority_queue<ii, vector<ii>, greater<ii>> pq;
//pair<��������-�ش����������� �Ÿ�, �����ǹ�ȣ>
void shortestPath(int s) {
	dist[s] = 0;

	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int d = front.first; //�� ���������� �Ÿ�
		int u = front.second;//�˻� �� ����
		if (d > dist[u]) continue;
		for (int i = 0; i < (int)adj[u].size(); i++) {
			ii v = adj[u][i];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				touch[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}
int main() {
	int n, m;
	int start, end;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> start >> end;
		dist.clear();
		touch.clear();
		adj = vector<vector<ii>>(n);
		dist = vector<int>(n, INF);
		touch = vector<int>(n, 1);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (b == end)endAdj.push_back(a);
			adj[a].push_back(make_pair(b, c));
		}
		shortestPath(start);
		int firstEnd = dist[end];
		if (dist[end] == INF) {
			cout << -1 << endl;
			continue;
		}
		int myStart;
		int myEnd;
		vector<int> shortest;
		while (true) {
			myStart = -1;
			myEnd = end;
			cout << end << endl;
			shortest.clear();
			shortest.push_back(myEnd);
			while (myStart != start) {
				myStart = touch[myEnd];
				cout << myStart << endl;
				shortest.push_back(myStart);
				myEnd = myStart;
			}
			//6,3,0 ������ ���Ϳ� ����
			//adj ��������Ʈ���� 0,3�� ������ ����ġ�� INF�� �ٲ���Ѵ�
			//2,1,0������ ���Ϳ� ����
			for (int i = (shortest.size() - 1); i >= 1; i--) {
				int findVertex = -1;
				for (int j = 0; j < (int)adj[shortest[i]].size(); j++) {
					if (adj[shortest[i]][j].first == shortest[i - 1]) {
						adj[shortest[i]][j].second = INF;
						break;
					}
				}
			}
			for (int i = 0; i < (int)endAdj.size(); i++) {
				//endAdj[i]�� �����°���, endAdj[i]���� �����°��� ���� INFó���ؾ���
				//���� �ڵ�� endAdj[i]���� ������ ������ INFó�����ϰ��ִ�.
				for (int j = 0; j < (int)adj[endAdj[i]].size(); j++) {
					if (dist[endAdj[i]] + adj[endAdj[i]][j].second == dist[end]) {
						adj[endAdj[i]][j].second = INF;
					}
				}
			}	
			for (int i = 0; i < (int)adj.size(); i++) {
				for (int j = 0; j < (int)adj[i].size(); j++) {

				}
			}
			dist = vector<int>(n, INF);
			touch = vector<int>(n, 1);
			shortestPath(start);
			//firstEnd : ó�� �ִܰŸ�
			//dist[end]ó�� �ִܰŸ��� ����� �� ���� �ִܰŸ��� �ٸ��ٸ� ���䵵��
			if (firstEnd != dist[end]) break;
			firstEnd = dist[end];
		}
		
		
		adj.clear();
		endAdj.clear();
		if (dist[end] == INF) cout << -1 << endl;
		else cout << dist[end] << endl;
	}

}