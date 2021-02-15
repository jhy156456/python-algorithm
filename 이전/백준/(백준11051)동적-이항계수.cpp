/*
자연수 N과 정수 K가 주어졌을 때 이항 계수 를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.
10007로 나눈 나머지를 구하는 문제이다.(힌트) 동적계획법으로 문제를 풀어나가도 더해서 1000행까지 가게되면 
숫자가 무지막지하게 커져버려서 int -> long long -> unsigned long long 으로 자료형을 바꿔봐도 답이 틀리게 되었다.
따라서 행렬에 값을 할당할때 처음부터 10007로 나눈 나머지값을 할당하면 자료형의 숫자 범위를 벗어나지 않게된다.
그리고 나머지값은 우선순위가 높다 b[][] + b[][] 에 괄호를 쳐주지 않아서 한번 틀렸었음.
*/

#include <iostream>
#include<algorithm>
using namespace std;

int b[1001][1001] = { 0 };

int bin(int n, int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i) b[i][j] = 1;
			else b[i][j] = (b[i - 1][j - 1] + b[i - 1][j])%10007;
		}

	}
	return b[n][k];
}
int main() {
	int first = 0;
	int second = 0;
	cin >> first;
	cin >> second;
	cout << bin(first, second)  << endl;
}