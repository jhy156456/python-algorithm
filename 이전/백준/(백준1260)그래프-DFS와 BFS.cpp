#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
// �׷����� ���� ����Ʈ ǥ��
vector<vector<int> > adj;
// �� ������ �湮�ߴ��� ���θ� ��Ÿ����
vector<bool> visited;
int n, m, firstNumber;
void dfs(int here) {
	visited[here] = true;
	cout << here << " ";
	/*
	�� �׷����� ��������Ʈ�̰� 0���ǰ� 0������ -1�� �ʱ�ȭ�Ǿ��ִ�
	���� ��������Ʈ�� ��������� ���� ���ϴ� ������� 1ũ�ԵǱ⶧����
	i< adj[here].size()�� �ؾ� �迭���� ��Ÿ�ӿ����� ���� �ʴ´�.
	ex) (1,2),(1,3),(1,4)�� ��ε��� �־����� i�� Ž�������� 1,2,3�� 3���� �Ǿ���ϰ�
	i�� �ε���0�� -1�̱⶧���� i=1���� 4������ 1,2,3�� Ž���ؾ��Ѵ�.
	*/
	int size = (int)adj[here].size();
	for (int i = 1; i < size; i++) { 
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}
// start ���� ������ �׷����� �ʺ� �켱 Ž���ϰ� �� ������ �湮 ������ ��ȯ�Ѵ�.
vector<int> bfs(int start) {
	// �� ������ �湮 ����
	vector<bool> discovered(adj.size()+1, false);
	// �湮�� ���� ����� �����ϴ� ť
	queue<int> q;
	// ������ �湮 ����
	vector<int> order;
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		// here�� �湮�Ѵ�.
		order.push_back(here);
		// ��� ������ ������ �˻��Ѵ�.
		int size = (int)adj[here].size();
		for (int i = 1; i < size; i++) {
			int there = adj[here][i];
			// ó�� ���� �����̸� �湮 ��Ͽ� ����ִ´�.
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
		adj[k].push_back(j);//�����׷���
		adj[j].push_back(k);
	}
	//������ȣ�� ũ������� �Է°��� �����°� �ƴѰͰ���
	//�������� ����ũ����
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	dfs(firstNumber);
	cout << endl;
	vector<int> orders = bfs(firstNumber);
	for (int i = 0; i < orders.size(); i++)cout << orders[i] << " ";
	cout << endl;
}