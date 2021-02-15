#include<iostream>
#include<vector>
using namespace std;

vector<int> problem(int N) {
	vector<int> ret;
	int check = 0;

	while (true) {

		if (N < 3 || N == 4 || N == 7) {
			return ret;
		}
		else if (N % 5 == 0) {
			N = N - 5;
			ret.push_back(N);
		}
		else{
			N = N - 3;
			ret.push_back(N);
		}
	}
}
int main() {
	int N;
	cin >> N;
	vector<int> ret;
	ret = problem(N);

	if (ret.size() == 0) cout << -1 << endl;
	else cout << ret.size() << endl;
}

//참고 : https://blog.naver.com/tbwbtl/221423847782
// 안되는경우가 3보다작을경우 or 4 or 7 이라고 대충 때려맞췄는데
// 이렇게 생각하면 안되고 정확하게 생각하고 문제 풀어야 함