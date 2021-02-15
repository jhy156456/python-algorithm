#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int, int>ii;
typedef vector<int> vi;
int t, n, m, k, result;
#define grid 500
int problem[grid][grid];
/*
first : ��Ȱ����
second : Ȱ�����¿��� ��
first�� 0�Ǹ� Ȱ������
first==0 second==0 �̸� ��������
*/
ii lifeOrDie[grid][grid];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int main() {
	cin >> t;
	
	for (int a = 1; a <= t; a++) {
		result = 0;
		cin >> n >> m>>k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a;
				cin >> a;
				problem[i + 250][j + 250] = a;
				lifeOrDie[i + 250][j + 250].first = a;
				lifeOrDie[i + 250][j + 250].second = a;
			}
		}
		//���Ϲ�ó������ : 1�ð���
		//�ι������� : 2�ð���
		//����°���� : 3�ð���
		//k�� 3�ϋ� 3�������ϰ� 3�ð����λ��¿��� �˻�
		while (k--) {
			//cout << "------------------" << endl;
			//for (int i = 240; i < 260; i++) {
			//	for (int j = 240; j < 260; j++) {
			//		cout << "(" << lifeOrDie[i][j].first << "," << lifeOrDie[i][j].second << ") ";
			//	}
			//	cout << endl;
			//}
			//cout << "------------------" << endl;
			for (int i = 0; i < grid; i++) {
				for (int j = 0; j < grid; j++) {
					//Ȱ�����°���
					if (lifeOrDie[i][j].first == 0
						&& lifeOrDie[i][j].second>0) {
						lifeOrDie[i][j].second--;

						if (lifeOrDie[i][j].second == 0) {
							//�������¸� ���Ĵ��ϸ�ȵǱ⶧����
							//-1�� �ɷ��ش�
							//�̷����ϸ� (0,0)�϶� ����� 1�λ����� ���������ع�����..
							lifeOrDie[i][j].second = -1;
						}
					}

					//��Ȱ�����°���
					if (lifeOrDie[i][j].first != 0) {
						lifeOrDie[i][j].first--;
					}
					
				
				}
			}
			for (int i = 0; i < grid; i++) {
				for (int j = 0; j < grid; j++) {
					//�������� : Ȱ�������̰�  ù 1�ð��̶�� �����Ѵ�
					if (lifeOrDie[i][j].first == 0
						&&( lifeOrDie[i][j].second == problem[i][j]-1
							|| lifeOrDie[i][j].second == problem[i][j] - 2
							)) {
						for (int k = 0; k < 4; k++) {
							int thereY = i + dy[k];
							int thereX = j + dx[k];

							if (thereY < grid && thereY >= 0
								&& thereX < grid && thereX >= 0
								&& lifeOrDie[thereY][thereX].first 
								== lifeOrDie[thereY][thereX].second
								&& problem[thereY][thereX]<problem[i][j]) {

								lifeOrDie[thereY][thereX].first = problem[i][j];
								lifeOrDie[thereY][thereX].second = problem[i][j];
								problem[thereY][thereX] = problem[i][j];
							}

						}
					}
				}
			}

		}

		for (int i = 0; i < grid; i++) {
			for (int j = 0; j < grid; j++) {
				if (lifeOrDie[i][j].first >0
					|| lifeOrDie[i][j].second > 0) {
					result++;
				}
			}
		}
		memset(problem, 0, sizeof(problem));
		memset(lifeOrDie, 0, sizeof(lifeOrDie));
		cout << "#" << a << " " << result << endl;
	}

}

