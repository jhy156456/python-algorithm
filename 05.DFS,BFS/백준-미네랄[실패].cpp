#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
int n;
vvi graph;
vvi visited;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<ii> q;
vector<ii> bfs(int y, int x) {
	vii results;
	visited[y][x] = true;
	q.push({ y,x });

	while (!q.empty()) {
		int hereY = q.front().first, hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int thereY = hereY + dy[i], thereX = hereX + dx[i];
			if (thereY >= 0 && thereY < r && thereX >= 0 && thereX < c) {
				if (visited[thereY][thereX] && graph[hereY][hereX] == graph[thereY][thereX]) {
					q.push({ thereY,thereX });
					visited[thereY][thereX] = true;
					results.push_back({ thereY,thereX });
				}
			}
		}
	}
	
}
int r, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	graph = vvi(r, vi(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			char a;
			cin >> a;
			if (a == '.') {
				//��
				graph[i][j] = 0;
			}
			else {
				//�̳׶�
				graph[i][j] = 1;
			}
			
		}
	}
	cin >> n;
	vi problems;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		problems.push_back(a);
	}


	for (int i = 0; i < n; i++) {
		int row = r-problems[i];
		if (i % 2 == 0) {
			//���ʿ��� ������
			for (int j = 0; j < c; j++) {
				if (graph[row][j] == 1) {
					//�̳׶��� ������
					graph[row][j] = 0;
					//�̳׶��� �ı��ϰ�
					vvii location;
					//�湮 ����� �ʱ�ȭ�ϰ�
					visited.clear();

					//�ش� �̳׶��� Ŭ�����͸� ���Ѵ�.
					location.push_back(bfs(row, j));

					//�߷¿� ���� �Ʒ��� ������ �� �ֱ� ������ �ش� ���� �������� �Ʒ��κ��� 
					
					
				}
			}
		}
		else {
			//�����ʿ��� ����
			for (int j = c-1; j >= 0; j++) {
				if (graph[row][j] == 1) {
					//�̳׶��� ������

				}
			}
		}

	}

	
}


/*



0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 1 0 1 1 0
0 0 0 1 1 1 0 0
0 0 1 1 1 0 0 0
0 0 1 0 1 1 1 0
0 0 1 0 0 0 1 0
0 1 1 1 0 0 1 0


6

0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 x 0 x 1 0
0 0 0 x 1 1 0 0
0 0 1 x 1 1 0 0
0 0 1 1 1 1 1 0
0 0 1 1 0 0 1 0
0 1 1 1 0 0 1 0











*/