#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<string>
#include<cstring>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define INF 1000000000
vb visited(26, false);
int N = 0;
using namespace std;
void construct(int &N, vector<vector<int>> &adj_list, vector<int> &cost) {
	string line;
	int hash[26];
	memset(hash, -1, sizeof hash);
	while (getline(cin, line) && !line.empty()) {
		istringstream sin(line);
		char node;
		sin >> node;
		if (hash[node - 'A'] == -1) {
			hash[node - 'A'] = N++;
			adj_list.push_back(vector<int>());
			cost.push_back(0);
		}
		sin >> cost[hash[node - 'A']];
		string prev;
		sin >> prev;
		for (char p : prev) {
			if (hash[p - 'A'] == -1) {
				hash[p - 'A'] = N++;
				adj_list.push_back(vector<int>());
				cost.push_back(0);
			}
			adj_list[hash[p - 'A']].push_back(hash[node - 'A']);
		}
	}
}
void toposort(int u, const vector<vector<int>> &adj_list, vector<int> &topo_order) {
	visited[u] = true;
	for (int v : adj_list[u])
		if (!visited[v])
			toposort(v, adj_list, topo_order);
	topo_order.push_back(u);
}
int main() {
	int T;
	vector<vector<int>> adj_list;
	vector<int> cost;
	construct(N, adj_list, cost);
	vector<int> topo_order;
	for (int i = 0; i < N; i++)
		if (!visited[i]) toposort(i, adj_list, topo_order);
	reverse(topo_order.begin(), topo_order.end());
	int answer = 0;
	vector<int> dist(N);
	for (int u : topo_order) {
		answer = max(answer, cost[u] + dist[u]);
		for (int v : adj_list[u])
			dist[v] = max(dist[v], cost[u] + dist[u]);
	}
	cout << answer << "\n";
	return 0;
}