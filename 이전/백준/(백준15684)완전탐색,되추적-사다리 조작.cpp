#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> ii;
int problem[31][11];
int n, m, h,findAnswer;
int result = 4;
/*
getResults()�Լ����� 1~n���� �������,���������� ���Ϳ��ְ�
���� ���� �� �Ŀ� ���͸� �����ŭ���鼭
(���������, ��������)�� �ٸ� ��ǥ�� �����ߴµ� �ð��ʰ�����
�׷��ʿ� ���� ���μ�1�ٸ��� ���������� ���ϸ鼭 ���������� �ٸ��ٸ�
false�� ��ȯ�ϰ��Ͽ� �ð��ȿ� AC����
*/
bool getResults() {
	bool same = true;
	for (int i = 1; i <= n; i++) {
		int hereY = 0, hereX = i;
		while (hereY != h + 1) {
			hereY++;
			//��ǥ�ڽ��� 1�̶�� ���������� ����
			if (problem[hereY][hereX] == 1) {
				hereX++;
			}
			//������ 1�̶�� �������� ����
			else if (problem[hereY][hereX - 1] == 1) {
				hereX--;
			}
		}
		if (i != hereX) {
			same = false;
			break;
		}
	}
	return same;
}
bool putLadder(int y, int x) {
	//��ٸ��� ���� �� �ִ� ������
	//�ڽ��� 0�� �ƴϸ鼭 �ڽ��� ������ 1�̾ƴϰ� �����ʵ� 1�� �ƴҶ�
	if (problem[y][x] == 0 && problem[y][x - 1] != 1
		&&problem[y][x+1]!=1) {
		return true;
	}
	return false;
}
/*
ó�� �ڵ� ®������ ������
��ٸ��� ���´�-> �����̾ƴϴ� -> depth����
��ٸ��� ���´�-> �����̴� -> ���
*/
void dfs(int y, int x,int depth) {
	//���� �� �ִ� ��ٸ� ��ǥ���� ���� ���Ѵ�.
	for (int i = y; i <= h; i++) {//����
		for (int j = 1; j <n; j++) {//����
			if (putLadder(i, j)) {
				problem[i][j] = 1;
				if (getResults()) {
					if (result > depth) { 
						result = depth; 
					}
				}
				else if (depth < 3) {
					depth++;
					dfs(i, j, depth);
					depth--;
				}
				problem[i][j] = 0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int y, x;
		cin >> y >> x;
		problem[y][x] = 1;
	}
	if (getResults()) {
		cout << 0 << endl;
	}
	else {
		dfs(1,1,1);
		if (result >= 4) {
			cout << -1 << endl;
		}
		else {
			cout << result << endl;
		}
	}
}