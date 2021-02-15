#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int n,m;
int answerCount = 0;
vector<vector<int>>problems;
vector<vector<int>>visited; //�Ÿ�������
vector<pair<int, int>> order;
int dy[4] = {-1,1,0,0};//��,��,��,��
int dx[4] = {0,0,-1,1};
void bfs() {
	
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++) { //�ʱ� 1�ΰ� ���� ť�� �־�д�
		for (int j = 0; j < m; j++) {
			if (problems[i][j] == 1) { 
				q.push(make_pair(i, j)); 
				visited[i][j] = 1;//�ϼ��� 1�Ϸ� �ʱ�ȭ�Ѵ�.
			}
		}
	}
	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();
		//order.push_back(make_pair(hereY, hereX));
		for (int i = 0; i < 4; i++) {//��� ������ ������ �˻��Ѵ�
			int goY = hereY + dy[i];
			int goX = hereX + dx[i];
			if (goY < 0 || goX < 0 || goY >= n || goX >= m 
				|| problems[goY][goX]!=0
				|| visited[goY][goX]!=0) //�湮������ �ְų� �ش� ��ǥ�� 0�� �ƴϰų� ��谪�� ����ٸ� �ٸ���ǥ �˻�
				continue;
			q.push(make_pair(goY, goX));
			visited[goY][goX] = visited[hereY][hereX]+1;
		}
	}
}
int main() {
	cin >> m >> n; //n�� ���� m�� ����(��)
	problems = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> problems[i][j];
			if (problems[i][j] == -1) visited[i][j] = -1;//-1�� �ѷ��׿��ִ� �丶�並 ã�� ����
		}
	}
	bfs();
	int max = 0;
	int minusCheck = 0;
	for (int i = 0; i < n; i++) { //�ʱ� 1�ΰ� ���� ť�� �־�д�
		for (int j = 0; j < m; j++) {
			if (visited[i][j] > max) { 
				max = visited[i][j]; 
			}
			if (visited[i][j] == 0) minusCheck = 1; //-1���̿����� �����ϰ� �ѹ��� ���������ִٸ�
		}
	}
	if (minusCheck == 1) cout << -1 << endl;
	else cout << max-1 << endl;
}