#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// �׷����� ���� ��� ǥ��. adj[i][j] = i �� j ������ ������ ��
vector<vector<int> > adj;
// graph[i][j] = i �� �����ؼ� j �� ������ �ܾ��� ���
vector<string> graph[26][26];
// indegree[i] = i �� �����ϴ� �ܾ��� ��
// outdegree[i] = i �� ������ �ܾ��� ��
vector<int> indegree, outdegree;

void getGraph(const vector<string>& words) {
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear();
	adj = vector<vector<int> >(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	for (int i = 0; i < words.size(); i++) {
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	}
}

// ���� �׷����� ���� ��� adj �� �־��� �� ���Ϸ� ��Ŷ�� 
// ����Ѵ�. 
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < adj.size(); ++there)
		while (adj[here][there] > 0) {
			adj[here][there]--; // ���� ������ ��� �����
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}

// ���� �׷����� ���Ϸ� Ʈ�����̳� ��Ŷ�� ��ȯ�Ѵ�
vector<int> getEulerTrailOrCircuit() {
	vector<int> circuit;
	// �켱 Ʈ������ ã�ƺ���: �������� �����ϴ� ���
	for (int i = 0; i < 26; i++)
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	// �ƴϸ� ��Ŷ�̴�, ������ ������ �ƹ� ���������� �����Ѵ�
	for (int i = 0; i < 26; i++)
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	// ��� ������ ��� �� �迭�� ��ȯ�Ѵ�
	return circuit;
}

string solve(const vector<string>& words) {
	getGraph(words);

	// ���Ϸ� ��Ŷ�̳� ��θ� ã�Ƴ���
	vector<int> circuit = getEulerTrailOrCircuit();

	// ��� ������ �湮���� �������� ����!
	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";

	// �ƴ� ��� �湮 ������ ������ �� �������� ��� ���ڿ��� ����� ��ȯ�Ѵ�.
	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 1; i < circuit.size(); i++) {
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++) cin >> words[i];
		cout << solve(words) << endl;
	}
}

