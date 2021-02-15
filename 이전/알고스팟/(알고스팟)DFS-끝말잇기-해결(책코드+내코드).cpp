#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<vector<int>> adj;
int C;
// graph[i][j] = i 로 시작해서 j 로 끝나는 단어의 목록
vector<string> graph[26][26];

vector<int> indegree, outdegree;
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < adj.size(); there++) {
		while (adj[here][there] > 0) {
			adj[here][there]--;
			//adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
vector<int> getEulerTrailOrCircuit() {
	vector<int> circuit;
	for (int i = 0; i < 26; i++) {
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}

	}
	return circuit;
}
bool checkEuler() {
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1)plus1++;
		if (delta == -1) minus1++;

	}
	return(plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}
int main() {
	cin >> C;
	vector<int> circuit;
	while (C--) {
		int n;
		cin >> n;
		vector<string> problems(n);
		adj = vector<vector<int>>(26, vector<int>(26, 0));
		indegree = outdegree = vector<int>(26, 0);
		for (int i = 0; i < n; i++) {
			cin >> problems[i];
		}
		int count = n;
		int i = 0;
		while (count--) {
			//cout << problems[i] << endl;
			int start = problems[i].at(0) - 'a';
			//cout << "start : " << start<<endl;
			int end = problems[i].at(problems[i].size() - 1) - 'a';
			//cout << "end : " << end << endl;
			adj[start][end]++;
			graph[start][end].push_back(problems[i]);
			outdegree[start]++;
			indegree[end]++;
			i++;
		}
		if (!checkEuler()) cout << "IMPOSSIBLE" << endl;
		else {
			circuit = getEulerTrailOrCircuit();
			if (circuit.size() != n + 1) {
				cout << "IMPOSSIBLE" << endl;
				break;
			}
			/*for (int i = 0; i < circuit.size(); i++)cout << circuit[i] << " ";
			cout << endl;*/
			reverse(circuit.begin(), circuit.end());
			string ret;
			for (int i = 1; i < circuit.size(); i++) {
				int a = circuit[i - 1], b = circuit[i];
				if (ret.size()) ret += " ";
				ret += graph[a][b].back();
				graph[a][b].pop_back();
			}
			cout << ret << endl;
		}

		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				graph[i][j].clear();
		problems.clear();
	}


}