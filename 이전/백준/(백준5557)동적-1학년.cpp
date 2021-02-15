#include<iostream>
#include<string.h>
using namespace std;

long long C[101][21];
int N[101];
int n;
long long sunResult(int hang, int yul) {//초기값  N[hang(11)] = 8
	if (hang == 1) {
		if (N[hang] == yul) {
			C[hang][yul] = 1;
		}
		else {
			C[hang][yul] = 0;
		}
		return C[hang][yul];
	}
	long long &ret = C[hang][yul];
	if (ret != -1) return ret;
	if (yul + N[hang] > 20) {
		return C[hang][yul] = sunResult(hang - 1, yul - N[hang]);
	}
	else if ((yul - N[hang]) < 0) {
		return C[hang][yul] = sunResult(hang - 1, yul + N[hang]);
	}
	else if (N[hang] == 0) {
		return C[hang][yul] = 2 * sunResult(hang - 1, yul + N[hang]);
	}
	else {
		return C[hang][yul] = sunResult(hang - 1, yul + N[hang]) + sunResult(hang - 1, yul - N[hang]);
	}
}
int main() {
	memset(C, -1, sizeof(C));
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> N[i];
	}
	cout << sunResult(n -1, N[n]) << "\n";//이 행,열부터 구하자
}