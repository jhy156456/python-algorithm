#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
using namespace std;
int c,n;
vii eatTimeAndMicroWave;
vi microWave;
vi eatTime;
int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		eatTimeAndMicroWave.clear();
		microWave.assign(n, 0);
		eatTime.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> microWave[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> eatTime[i];
		}
		for (int i = 0; i < n; i++) {
			eatTimeAndMicroWave.push_back(ii(eatTime[i], microWave[i]));
		}
		//�Դ½ð� �������� ������������
		sort(eatTimeAndMicroWave.begin(), 
			eatTimeAndMicroWave.end(),greater<ii>());
		
		int wholeEatTime = 0;

		while ((int)eatTimeAndMicroWave.size() != 2 && (int)eatTimeAndMicroWave.size()>1) {
			//����½ð��� ���ؿ�
			wholeEatTime = eatTimeAndMicroWave[0].second;
			eatTimeAndMicroWave.erase(eatTimeAndMicroWave.begin());
		}

		//2���������� �Դ½ð��� �����ɸ��� ���ö��� ����½ð���
		//���� �Ŀ� �װ� �Դ½ð��� �������ö��� �����+�Դ½ð���
		//���ؼ� �� ū���� �����ش�
		
		if ((int)eatTimeAndMicroWave.size() == 2) {
			wholeEatTime += eatTimeAndMicroWave[0].second;
			if (eatTimeAndMicroWave[0].first
		> eatTimeAndMicroWave[1].first
				+ eatTimeAndMicroWave[1].second) {
				wholeEatTime += eatTimeAndMicroWave[0].first;
			}
			else {
				wholeEatTime += eatTimeAndMicroWave[1].first
					+ eatTimeAndMicroWave[1].second;
			}
		}
		else { //���ö� 1���ϋ�
			wholeEatTime += eatTimeAndMicroWave[0].first+ eatTimeAndMicroWave[0].second;
		}
		cout << wholeEatTime << endl;

	}
}