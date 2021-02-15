#include <iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
int c, k;
vector<string> problem;
int dp[15][1 << 15], overlap[15][15];
void calcOverLap() {
	for (int i = 0; i < problem.size(); i++) {
		for (int j = 0; j < problem.size(); j++) {
			if (i == j)continue;
			string a = problem[i];
			string b = problem[j];
			for (int l = 0; l < min(a.size(), b.size()); l++) {
				int m = l;
				int sameCount = 0;
				while (a[m] == b[m] && m<max(a.size(), b.size())) {
					sameCount++;
					m++;
				}
				if (m > sameCount&&b[m - sameCount - 1] == ' ' && overlap[i][j] < sameCount) {
					overlap[i][j] = sameCount;
				}
				b = " " + b;
			}
		}
	}
}
void removeIncluesion() {
	for (int i = 0; i < (int)problem.size(); i++) {
		for (int j = 0; j < (int)problem.size(); j++) {
			if (i == j)continue;
			if (i >= problem.size() || j >= problem.size())break;
			string a = problem[i];
			string b = problem[j];
			int lForSize = abs((int)a.size() - (int)b.size());
			for (int l = 0; l <lForSize; l++) {
				int m = l;
				int sameCount = 0;
				while (a[m] == b[m] && m<a.size() && m<b.size()) {
					sameCount++;
					m++;
				}
				//작은걸날려야함
				if (sameCount == min(a.size(), b.size()) - l) {
					if (problem[i].size() > problem[j].size()) {
						problem.erase(problem.begin() + j);
					}
					else {
						problem.erase(problem.begin() + i);
					}
					k--;
					break;
				}
				if (problem[i].size() > problem[j].size()) {
					b = " " + b;
				}
				else {
					a = " " + a;
				}

			}
		}
	}
}

int shortestPath(int here, int visited) {
	//기저사례
	if (visited == (1 << k) - 1) {
		return 0;
	}
	int &ret = dp[here][visited];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; next++) {
		if (visited & 1 << next)continue;
		int cand = overlap[here][next] + shortestPath(next, visited + (1 << next));
		ret = max(cand, ret);
	}
	return ret;
}
string reconstruct(int last, int used) {
	//기저 사례
	if (used == (1 << k) - 1)
		return problem[last];
	//다음에 올 문자열 조각을 찾는다
	for (int next = 0; next < k; next++) {
		//next가 이미 사용되었으면 제외
		if (used & (1 << next))
			continue;
		//next를 사용했을 경우의 답이 최적해와 같다면 next를 사용
		int ifUsed = shortestPath(next, used + (1 << next)) + overlap[last][next];
		if (shortestPath(last, used) == ifUsed)
			return (problem[last].substr(0, problem[last].size() - overlap[last][next]) + reconstruct(next, used + (1 << next))); //used+(1<<next)->next 사용했다고 표시
	}
	//에러 발생시
	return "error!";
}
//overlap 초기화

//int getOverlap(const string &s1, const string &s2)
//{
//	for (int length = min(s1.size(), s2.size()); length > 0; length--)
//		if (s1.substr(s1.size() - length) == s2.substr(0, length))
//			return length;
//
//	return 0;
//
//}


int main() {
	cin >> c;
	for (int a = 1; a <= c; a++) {
		memset(dp, -1, sizeof(dp));
		memset(overlap, 0, sizeof(overlap));
		cin >> k;
		for (int i = 0; i < k; i++) {
			string b;
			cin >> b;
			problem.push_back(b);
		}
		removeIncluesion();
		calcOverLap();
		//for (int j = 0; j < k; j++)
		//	for (int l = 0; l < k; l++) {
		//		if (j == l)continue;
		//		overlap[j][l] = getOverlap(problem[j], problem[l]);
		//	}
		int max = 0, maxIndex = 0;
		for (int i = 0; i < k; i++) {
			int temp = shortestPath(i, 1 << i);
			if (max < temp) {
				max = temp;
				maxIndex = i;
			}
		}

		cout << reconstruct(maxIndex, 1 << maxIndex) << endl;
		//cout << "hh" << endl;
		problem.clear();
	}
}