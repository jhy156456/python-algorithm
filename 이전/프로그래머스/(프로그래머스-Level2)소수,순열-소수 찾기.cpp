#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<bitset>
using namespace std;
/*
1. numbers 스트링을 조합하기위한 순열숫자를 구한다
2. 순열숫자를 - '0'해서 숫자로 바꾼다
3. 숫자를 루트n부터 -1씩해가면서 나누어 떨어지는 수가 있는지
판단한 후 없으면 소수이므로 true반환한다.

2도 소수입니다.. 처음에 >=3으로해서 왜틀렸는지 1시간고민함
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
		int temp = i; //출력값 만들기
		if (check[i] == false) {
			picked.push_back(temp); //함수 호출 시 입력한 깊이값에 출력값 넣어준다		//	depth = temp; (이거 쓰지 말 것, 실수 주의!!)
			check[i] = true; //방문완료
			// 재귀호출
			recursion(depth + 1); //깊이 하나 증가, n, r은 값 그대로
			check[i] = false; //초기화하기
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