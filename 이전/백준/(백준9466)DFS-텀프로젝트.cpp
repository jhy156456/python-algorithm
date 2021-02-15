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
	cycle[here] = step; //���� ����Ŭ(�������)�� �־���� dfs
	depth[here] = level++;
	if (!visited[there]) {//������ ���� �湮�����ʾҴٸ�
		int hi= dfs(there, step, level);
		return hi;
	}
	else { //������ ���� �湮 ������ �ִٸ� ���� ����Ŭ�� �����ִ¾����� ���ؾ���
		if (cycle[there] == step) { 
			//(depth[there]==1)//���� ����Ŭ�� �ִ¾��̰� ó�����·� ���ƿ°��̶��
			return level - depth[there];
		}
		else { //ó�� ���°� �ƴ� ���ѷ����̰ų� �ٸ���尡 �� ���� �������� �Ѵٸ�
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
			cycle[i] = i; //��� ������ ���
			if (!visited[i]) {
				answer += dfs(i,i,level+1);
			}
		}
		cout << n-answer << endl;
	}

}