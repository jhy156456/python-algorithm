#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int robotProblem[11][11];
int ground[11][11];
int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = { -1,0,1,-1,1,-1,0,1 };
vi tree[11][11];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> robotProblem[i][j];
			ground[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);

	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() != 0) {
				sort(tree[i][j].begin(), tree[i][j].end());
			}
		}
	}
	while (k--) {
		//��
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (tree[i][j].size() != 0) {
					//����ġ�� ������ ��иԴ´�
					int firstTree = 0;
					for (int l = 0; l < (int)tree[i][j].size(); l++) {
						//�ڽ��� ���̸�ŭ ����� ���� �� �ִٸ�
						if (tree[i][j][l] <= ground[i][j] && firstTree ==0) {
							ground[i][j] -= tree[i][j][l];
							tree[i][j][l]++;
						}
						//����� �ڽ��� ���̺��� ���ٸ�
						else {
							firstTree = 1;
							ground[i][j] += (int)(tree[i][j][l] / 2);
							tree[i][j][l] = 0;
						}
					}
				}
			}
		}
		//����
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (tree[i][j].size() != 0) {
					for (int l = (int)tree[i][j].size() - 1; l >= 0; l--) {
						//���̰� 0�̸� ���������̴ϱ� ������� �ٲ�
						if (tree[i][j][l] == 0) {
							tree[i][j].pop_back();
						}
					}

				}
			}
		}
		//����
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (tree[i][j].size() != 0) {
					//���� ���̰� 5�ǹ����� ����!
					for (int l = 0; l < (int)tree[i][j].size(); l++) {
						if (tree[i][j][l] % 5 == 0) {
							for (int direction = 0; direction < 8; direction++) {
								int nextY = i + dy[direction];
								int nextX = j + dx[direction];
								if (nextY >= 1 && nextY <= n
									&& nextX >= 1 && nextX <= n) {
									tree[nextY][nextX].push_back(1);
								}
							}
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (tree[i][j].size() != 0) {
					sort(tree[i][j].begin(), tree[i][j].end());
				}
			}
		}
		//�ܿ�
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ground[i][j] += robotProblem[i][j];
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((int)tree[i][j].size() != 0) {
				answer += (int)tree[i][j].size();
			}
		}
	}
	cout << answer << endl;
}