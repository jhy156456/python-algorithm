#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>

using namespace std;
int n;
/*
인터넷참조, 
최대는 9876543210이다 왜냐하면 숫자 감소 && 십진수 이기때문에 10,9,8순서로 숫자가 생성될 수 없다.
그렇기때문에 자릿수가 10이상이면 더이상 숫자를 생성시킬 필요가 없음.
*/
vector<long long> problems;
void r(long long a, int cipher) {
	if (cipher >10) {
		return ;
	}
	problems.push_back(a);
	int next = a % 10;
	for (int i = 0; i < next; i++) {
		r(a * 10 + i, cipher+1);
	}
}
int main(){
	cin >> n;

	for (int i = 0; i <= 9; i++) {
		r(i, 1);
	}
	if (problems.size() < n) {
		cout << -1 << endl;
		return 0;
	}
	sort(problems.begin(), problems.end());
	cout << problems[n-1] << endl;
}
