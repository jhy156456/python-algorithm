#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
#define f(i,l,r) for(int i=l;i<r;i++)
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
int r, c;
vector<vc> graph;
vi parent(2250001);
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<ii> q;
//u�� ���� Ʈ���� ��Ʈ�� ��ȣ�� ��ȯ�Ѵ�.
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int y, int x) {
	//��,��,��,���� �ִ� ���� merge�۾��� �����Ѵ�.
	int hereParent = find(y*c+x);
	q.push({ y,x });

	for (int i = 0; i < 4; i++) {
		int thereY = y + dy[i], thereX = x + dx[i];
		if (thereY >= 0 && thereY < r && thereX >= 0 && thereX < c) {
			//4���� Ȯ���ϸ鼭 ���̸� ���� �θ� ���� �θ�(���ڽ�)�� �����

			if (graph[thereY][thereX] == '.') {
				int thereParent = find(thereY * c + thereX);
				parent[thereParent] = hereParent;
			}
		}
	}
}
/*
�� �ֺ��� �ִ� �ֵ��� ���δ�.
���̰� ��ģ��.
*/
void bfs() {
	int qSize = q.size();
	for(int i=0; i<qSize;i++){
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int thereY = hereY + dy[i], thereX = hereX + dx[i];
			if (thereY >= 0 && thereY < r && thereX >= 0 && thereX < c) {
				//4���� Ȯ���ϸ鼭 �����̸� ���̰� ���� �׷����� �����.
				if (graph[thereY][thereX] == 'X') {
					graph[thereY][thereX] = '.';
					merge(thereY, thereX);
				}
			}
		}
	}
}

void printVector(vector<vector<char>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
vii fly;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	int multiply = r * c;
	for (int i = 0; i < multiply; ++i)
		parent[i] = i;
	graph = vector<vc>(r, vc(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char a;
			cin >> a;
			graph[i][j] = a;
			if (a == '.') {
				merge(i, j);
			}
			else if (a == 'L') {
				fly.push_back({ i,j });
				graph[i][j] = '.';
				merge(i, j);
			}
		}
	}
	int result = 0;
	while (!q.empty()) {
		if (find(fly[0].first * c + fly[0].second) == find(fly[1].first * c + fly[1].second))break;
		bfs();
		result++;
	}

	cout << result << endl;
}