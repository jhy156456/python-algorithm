#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vii;
typedef vector<int> vi;

using namespace std;
int c,n;
vi russia;
vi korea;
int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		russia.assign(n, 0);
		korea.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> russia[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> korea[i];
		}
		sort(russia.begin(), russia.end());
		sort(korea.begin(), korea.end());
		int winCount = 0;
		for (int i = russia.size()-1; i >=0; i--) {
			//���þƼ��� ó������ ���غ���
			//ũ�ų� �����ֵ��� ���� �����ָ� �����´�
			//ũ�ų� �����ֵ��� ���ٸ� �ѱ��ֵ��� ���� �������� �����´�
			//����� �����س��� �ϴ°� ������
			int bigOrSame = 0;
			int j = 0;
			for (j = 0; j < (int)korea.size(); j++) {
				if (russia[i] <= korea[j]) {
					bigOrSame = korea[j];
					break;
				}
			}
			if (bigOrSame != 0) {
				winCount++;
				korea.erase(korea.begin() + j);
			}

		}
		cout << winCount << endl;
	}
}