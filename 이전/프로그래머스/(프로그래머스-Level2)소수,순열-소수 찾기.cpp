#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<bitset>
using namespace std;
/*
1. numbers ��Ʈ���� �����ϱ����� �������ڸ� ���Ѵ�
2. �������ڸ� - '0'�ؼ� ���ڷ� �ٲ۴�
3. ���ڸ� ��Ʈn���� -1���ذ��鼭 ������ �������� ���� �ִ���
�Ǵ��� �� ������ �Ҽ��̹Ƿ� true��ȯ�Ѵ�.

2�� �Ҽ��Դϴ�.. ó���� >=3�����ؼ� ��Ʋ�ȴ��� 1�ð������
*/
typedef pair<int, int> ii;
typedef long long ll;
int n, p, r, answer;
using namespace std;
string problem;
vector<int>picked;
bool check[10];
map<int, int> checkNumberCheck;

int CheckByRoot(unsigned int n) {
	if (n <= 1) {
		return false;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0) {
			return false;
		}
	}

	return true;
}
void recursion(int depth) {
	if (depth == r) {
		int checkNumber = 0;
		for (int i = 0; i < r; i++) {
			checkNumber = checkNumber * 10 + problem[picked[i]] - '0';
		}
		if (checkNumber >= 2 && checkNumberCheck[checkNumber] == 0) {
			checkNumberCheck[checkNumber] = 1;
			if (CheckByRoot(checkNumber)) {
				answer++;
			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		int temp = i; //��°� �����
		if (check[i] == false) {
			picked.push_back(temp); //�Լ� ȣ�� �� �Է��� ���̰��� ��°� �־��ش�		//	depth = temp; (�̰� ���� �� ��, �Ǽ� ����!!)
			check[i] = true; //�湮�Ϸ�
			// ���ȣ��
			recursion(depth + 1); //���� �ϳ� ����, n, r�� �� �״��
			check[i] = false; //�ʱ�ȭ�ϱ�
			picked.pop_back();
		}
	}
}
int solution(string numbers) {
	n = numbers.size();
	problem = numbers;
	for (r = 1; r <= (int)numbers.size(); r++) {
		recursion(0);
	}
	return answer;
}

int main() {

	cout << solution("193") << endl;

}