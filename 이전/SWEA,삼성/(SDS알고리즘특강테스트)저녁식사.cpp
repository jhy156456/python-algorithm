#include<iostream>
using namespace std;

int T;
int ans[200000];
int D[200000][3];  // [0] ��ȣ(1������) , [1] �ƹ��������� �Ÿ� , [2] �������� �Ÿ�
int compare1(const void *i1, const void *i2);
int compare2(const void *i1, const void *i2);

 
int main()
{
	int testCase, count,i,j,k,answer,x,y,index;
	cin >> T;
	for (testCase = 1; testCase <= T; testCase++) {
		cin >> count;
		for (i = 0; i<count; i++) {
			cin >> D[i][1];
			cin >> D[i][2];
			D[i][0] = i + 1;
		}
		qsort(D, count, sizeof(int) * 3, compare2);
		qsort(D, count, sizeof(int) * 3, compare1);
		x = 0;
		y = 1000000001;
		index = 0;
		answer = 0;
		for (i = 0; i<count; i++) {
			if (D[i][1] > x) { // x ���� ���ϸ�
				if (index != 0) ans[answer++] = index;
				x = D[i][1];
				index = 0;
			}
			if (D[i][2] < y) {
				index = D[i][0];
				y = D[i][2];
			}
		}
		if (index != 0) ans[answer++] = index;
		cout << "#" << testCase;
		for (i = 0; i < answer; i++)cout << " " << ans[i];
		cout << " " << endl;
	}

	return 0; 
}
int compare1(const void *i1, const void *i2) {
	const int *a = (const int *)i1;
	const int *b = (const int *)i2;
	if (a[1] < b[1]) return -1;
	else if (a[1] == b[1]) return 0;
	return 1;
}

int compare2(const void *i1, const void *i2) {
	const int *a = (const int *)i1, *b = (const int *)i2;
	if (a[2] < b[2]) return -1;
	else if (a[2] == b[2]) return 0;
	return 1;
}