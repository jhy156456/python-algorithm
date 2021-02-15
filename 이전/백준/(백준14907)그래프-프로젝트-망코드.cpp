#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;
typedef vector<int> vi;
#define INF 1000000000
vvii AdjList;
vi orders;
vi visited;
void dfs(int here) {
	visited[here] = true;
	if (here == (int)AdjList.size()) {
		orders.push_back(here);
		return;
	}
	for (int i = 0; i < (int)AdjList[here].size(); i++) {
		ii there = AdjList[here][i];
		if (!visited[there.first]) dfs(there.first);
	}
	orders.push_back(here);
}
int ATime = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char input[101];
	char* results;
	vector<char *> tokens;
	vector<int> cost(26);
	while (fgets(input, 101, stdin)) {
		if (input[0] == '\n') break;
		if (input[0] == 'A') {
			ATime = (int)input[2] - '0';
			continue;
		}

		AdjList.resize((input[0] - 'A') + 1);
		results = strtok(input, " ");
		while (results != NULL) {
			tokens.push_back(results);
			results = strtok(NULL, " ");
		}
		if (tokens[2] == '\0' || tokens[2] =="") {

			cost[(char)tokens[0][0] - 'A'] = (int)tokens[1][0] - '0';
			continue;
		}
		//tokens[2][0] : 간선 출발 노드
		if (tokens[2][1] != '\n') { //간선 출발노드가 2개이상이라면
			int i = 0;
			//cout << tokens[2][i++] << endl;
			while (tokens[2][i] != '\0' && tokens[2][i] != '\n') {
				cost[(char)tokens[0][0] - 'A'] = (int)tokens[1][0] - '0';
				AdjList[(char)tokens[2][i++] - 'A'].push_back(ii((char)tokens[0][0] - 'A', (int)tokens[1][0] - '0'));
			}
		}
		else {
			cost[(char)tokens[0][0] - 'A'] = (int)tokens[1][0] - '0';
			AdjList[(char)tokens[2][0] - 'A'].push_back(ii((char)tokens[0][0] - 'A', (int)tokens[1][0] - '0'));
		}
	}
	AdjList.resize((int)AdjList.size() + 1);

	visited = vi((int)AdjList.size()+1, false);
	for (int j = 0; j < (int)AdjList.size(); j++) {
		if (!visited[j]) dfs(j);
	}
	reverse(orders.begin(), orders.end());
	int answer = 0;
	vector<int> dist(26);
	for (int u : orders) {
		answer = max(answer, cost[u] + dist[u]);
		for (ii v : AdjList[u])
			dist[v.first] = max(dist[v.first], cost[u] + dist[u]);
	}

	//for (int i = 0; i < orders.size(); i++) cout << orders[i] << endl;
	cout << answer+ATime << endl;

}