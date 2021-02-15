#include <cstdio>
#include <iostream>
#include <cstring>    
#include <algorithm>  
using namespace std;

int main() {
	int test_case, T;
	int N, M, B;
	int H[20001];
	int temp1, temp2;
	int BarrierMax;
	int Answer;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		BarrierMax = 0;
		cin >> N;
		cin >> M;
		cin >> B;
		memset(H, 0, sizeof H);
		for (int i = 0; i < M; ++i) {
			cin >> temp1;
			cin >> temp2;
			H[temp1] = temp2;
			BarrierMax = max(BarrierMax, temp1);
		}
		Answer = 0;
		BarrierMax = max(BarrierMax, 2 * B);
		int shield;
		for (shield = B; shield <= BarrierMax; ++shield) {
			if (N > H[shield]) {
				Answer += shield * H[shield];
				N -= H[shield];
				H[shield] = 0;
			}
			else {
				Answer += shield * N;
				goto DONE;
			}
			if (shield > 2 * B) continue;
			int barrier1, barrier2;
			for (barrier1 = shield - B + 1, barrier2 = B - 1; barrier1 <= barrier2; ++barrier1, --barrier2) {
				int z = min(H[barrier1], H[barrier2]);
				if (z == 0) continue;
				if (barrier1 == barrier2) {
					if (N > z / 2) {
						Answer += shield * (z / 2);
						N -= (z / 2);
						H[barrier1] = z % 2;
					}
					else {
						Answer += shield * N;
						goto DONE;
					}
				}
				else {
					if (N > z) {
						Answer += shield * z;
						N -= z;
						H[barrier1] -= z;
						H[barrier2] -= z;
					}
					else {
						Answer += shield * N;
						goto DONE;
					}
				}
			}
		}
		Answer = -1;
	DONE:
		cout << "#" << test_case << " " << Answer << endl;
	}

	return 0;
}