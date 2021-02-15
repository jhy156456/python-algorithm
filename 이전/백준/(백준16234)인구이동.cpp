#include<iostream>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int people[50][50];
int peoppleCheck[50][50];
int hash[50]; //�θ𰪼���
int n, l, r;
int dy[] = { -1,0 };//��,��
int dx[] = { 0,1 };//��,��
typedef pair<int, int> ii;
vector<vector<ii>> hap;
map<pair<int, int>,int> hi;
int main() {
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> people[i][j];
		}
	}
	int count = 0;
	int yunhap = 0;

	hap.resize(50);
	while (true) {
		//���հ˻��Ѵ�
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				int rightY = y;
				int rightX = x + 1;
				int downY = y + 1;
				int downX = x;

				//�α����̰˻�
				if (l <= abs(people[y][x] - people[rightY][rightX])
					&& abs(people[y][x] - people[rightY][rightX]) <= r
					&& rightX < n) {
					//����üũ ���� 1���� 0����Ȯ��
					//0�̶�� y,x�� hash�� Ȯ���� down,right �ŵ��־���
					if (peoppleCheck[y][x] == 0) {
						hi[make_pair(y, x)] = yunhap++;
						int index = hi[ii(y, x)];
						hap[index].push_back(ii(y, x));
						peoppleCheck[y][x] = 1;
						if (peoppleCheck[rightY][rightX] == 0) {
							int index = hi[ii(y, x)];
							hap[index].push_back(ii(rightY, rightX));
							peoppleCheck[rightY][rightX] = 1;
						}

					}
					//�α����̰˻�
					if (l <= abs(people[y][x] - people[downY][downX])
						&& abs(people[y][x] - people[downY][downX]) <= r
						&& downY < n) {
						if (peoppleCheck[y][x] == 0) {
							int index = hi[ii(y, x)];
							hap[index].push_back(ii(y, x));
							peoppleCheck[y][x] = 1;
						}
						if (peoppleCheck[downY][downX] == 0) {
							int index = hi[ii(y, x)];
							hap[index].push_back(ii(downY, downX));
							peoppleCheck[downY][downX] = 1;
						}

					}

				}
			}
		}

		if ((int)hap[0].size() == 0) break;
		//��������
		for (int i = 0; i < (int)yunhap; i++) {
			int sum = 0;
			for (int j = 0; j < (int)hap[i].size(); j++) {
				sum += people[hap[i][j].first][hap[i][j].second];
			}
			int newPeople = (int)(sum / (int)hap.size());
			for (int j = 0; j < (int)hap[i].size(); j++) {
				people[hap[i][j].first][hap[i][j].second] = newPeople;
			}

		}
		hap.clear();
		hap.resize(50);
		memset(peoppleCheck, 0, sizeof(peoppleCheck));
		yunhap = 0;
		count++;
	}
	cout << count << endl;

}