#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
int problem[14][21];
int temp[14][21];
bool isDrugFind;
int t, d, w, k, result, r, n;
vector<int> withR;
int next_combi() {
	//n C r
	//5C3 �����Ϸ��� 
	//i�� r-1 , n+1-> n �Ѱ��� a[i]== n �� ���´�.
	int i = r-1;
	while (i >= 0 && withR[i] ==(n + 1)-r+i) i--;
	if (i<0) return 0;
	withR[i]++;
	for (int j = i + 1; j< r; j++) withR[j] = withR[i] + j - i;
	return 1;
}
void zeroOrOne(int &hi, int depth, int r, int drugCase) {

}
bool isPass() {
	for (int j = 0; j < w; j++) {
		int prevZero = 0;
		int prevOne = 0;
		int zeroCount = 0;
		int oneCount = 0;
		int maxZeroCount = 0;
		int maxOneCount = 0;
		if (problem[0][j] == 0) {
			prevZero = 1; zeroCount++;
		}
		else {
			prevOne = 1; oneCount++;
		}
		for (int i = 1; i < d; i++) {
			//������ 0�̿���
			if (prevZero) {
				//���簡 0�̴�
				if (problem[i][j] == 0) {
					prevZero = 1; zeroCount++;
					if (maxZeroCount < zeroCount) {
						maxZeroCount = zeroCount;
					}
				}
				//������ 0�̿��ٰ� ���� 1�� ����
				else {
					prevOne = 1; oneCount++; prevZero = 0;
					if (maxZeroCount < zeroCount) {
						maxZeroCount = zeroCount;
						
					}
					zeroCount = 0;
				}
			}
			//������ 1�̿���
			else {
				//���簡 1�̴�
				if (problem[i][j] == 1) {
					prevOne = 1; oneCount++;
					if (maxOneCount < oneCount) {
						maxOneCount = oneCount;
					}
				}
				//������ 1�̿��ٰ� ���� 0�� ����
				else {
					prevZero = 1; zeroCount++; prevOne = 0;
					if (maxOneCount < oneCount) {
						maxOneCount = oneCount;
					}
					oneCount = 0;
				}
			}
		}
		if (maxZeroCount < k && maxOneCount < k) return 0;
	}
	return 1;
}
void selectDrug(int depth, int drug, int r) {
	if (depth+1 == r) {
		for (int i = 0; i < w; i++) {
			problem[withR[depth]][i] = drug;
		}
		//if (withR[0] == 2) {
		//	cout << "-----------------" << endl;
		//	for (int row = 0; row < d; row++) {
		//		for (int col = 0; col < w; col++) {
		//			cout << problem[row][col] << " ";
		//		}
		//		cout << endl;
		//	}
		//	cout << "-----------------" << endl;
		//}
		//����Ǽ��� ���� �հݱ����� ������ٸ� �ٽ� �˻����� �ʴ´�
		if (isDrugFind) {
			for (int i = 0; i < w; i++) {
				problem[withR[depth]][i] = temp[withR[depth]][i];
			}
			return;
		}
		//�׷����� ���ٸ� �˻��Ѵ�
		else {
			isDrugFind = isPass();
		}
		for (int i = 0; i < w; i++) {
			problem[withR[depth]][i] = temp[withR[depth]][i];
		}
		return;
	}
	for (int i = 0; i < w; i++) {
		problem[withR[depth]][i] = drug;
	}
	depth++;
	selectDrug(depth,0,r);
	selectDrug(depth,1,r);
	for (int i = 0; i < w; i++) {
		problem[withR[depth]][i] = temp[withR[depth]][i];
	}
}
int main() {
	cin >> t;
	for (int a = 1; a <= t; a++) {
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> problem[i][j];
			}
		}
		//1�̸� ��� 0�̸� �������
		isDrugFind = 0;
		int drugCaseNumber = 1;
		isDrugFind = isPass();
		result = drugCaseNumber-1; n = d;
		while (!isDrugFind) {
			r = drugCaseNumber; result = drugCaseNumber;
			if (withR.size() == 0) {
				for (int i = 0; i < r; i++) withR.push_back(i);
			}
			do {
				//depth,r������,��ǰA
				for (int j = 0; j < r; j++) {
					//cout << withR[j] << endl;
					for (int i = 0; i < w; i++) {
						temp[withR[j]][i] = problem[withR[j]][i];
					}
				}
				selectDrug(0, 0, r);
				if (isDrugFind) break;
				selectDrug(0, 1, r);
				for (int j = 0; j < r; j++) {
					//cout << withR[j] << endl;
					for (int i = 0; i < w; i++) {
						problem[withR[j]][i] = temp[withR[j]][i];
					}
				}
			} while (next_combi());
			drugCaseNumber++;
			withR.clear();
		}

		memset(problem, 0, sizeof(problem));
		memset(temp, 0, sizeof(temp));
		cout << "#" << a << " " << result << endl;
	}

}