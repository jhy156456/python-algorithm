#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
#include<math.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define MAX 30000
using namespace std;
//https://baactree.tistory.com/53
#define MAX 30000

int base[MAX], diff[MAX], sum[MAX], ss[MAX];
bool chk[MAX];
vector<int> mp[MAX];
pair<int, int> vec[MAX];
int get_idx(int x) {
	int it = lower_bound(ss, ss + MAX, x) - ss;
	if (it == MAX || ss[it] != x)return -1;
	return it;
}
void flip(int mat[4][4]) {
	for (int i = 0; i < 4; i++) {
		swap(mat[i][0], mat[i][3]);
		swap(mat[i][1], mat[i][2]);
	}
}
void rotate(int mat[4][4]) {
	int temp[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[j][3 - i] = mat[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = temp[i][j];
		}
	}
}
int makeBlock(int module[][4][4]) {
	for (int i = 0; i < MAX; i++)mp[i].clear();
	for (int i = 0; i < MAX; i++) {
		chk[i] = false;
		base[i] = 10;
		//4*4중에 긴 기둥을 찾는다
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				base[i] = min(base[i], module[i][j][k]);
			}
		}
		diff[i] = 0;
		sum[i] = 0;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int now = module[i][j][k] - base[i];
				sum[i] = sum[i] * 3 + now;
				diff[i] = max(diff[i], module[i][j][k] - base[i]);
			}
		}
		vec[i] = { base[i] + diff[i],i };
		ss[i] = sum[i];
	}
	sort(vec, vec + MAX);
	sort(ss, ss + MAX);
	for (int i = 0; i < MAX; i++) {
		int idx = vec[i].second;
		mp[get_idx(sum[idx])].push_back(idx);
	}
	int ret = 0;
	for (int i = MAX - 1; i >= 0; i--) {
		int idx = vec[i].second;
		if (chk[idx])continue;
		mp[get_idx(sum[idx])].pop_back();
		chk[idx] = true;
		int temp[4][4];
		for (int j = 0; j < 4; j++)for (int k = 0; k < 4; k++)temp[j][k] = module[idx][j][k];
		flip(temp);
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			if (j)rotate(temp);
			int tsum = 0;
			for (int x = 0; x < 4; x++)for (int y = 0; y < 4; y++) {
				int now = diff[idx] - (temp[x][y] - base[idx]);
				tsum = tsum * 3 + now;
			}
			tsum = get_idx(tsum);
			if (tsum == -1 || mp[tsum].empty())continue;
			int it = mp[tsum].back();
			chk[it] = true;
			ret += base[idx] + base[it] + diff[it];
			mp[tsum].pop_back();
			flag = true;
			break;
		}
	}
	return ret;
}
//void reverseClockRotation(int block[4][4]) {
//	int rotate[4][4];
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			rotate[j][i] = block[i][3-j];
//		}
//	}
//	
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			block[i][j] = rotate[i][j];
//		}
//	}
//}
//extern int makeBlock(int module[][4][4]) {
//	vii iStResults;
//	vi realResults;
//	vi useBlock(30000, 0);
//	for (int i = 0; i < MAX; i++) {
//
//		for (int j = 0; j < MAX; j++) {
//			if (i == j) continue;
//			if (useBlock[j] == 1)continue;
//			int reverse[4][4];
//			//j모듈을 뒤집는다.
//			for (int k = 0; k < 4; k++) {
//				for (int l = 3; l >= 0; l--) {
//					reverse[k][3 - l] = module[j][k][l];
//				}
//			}
//			//뒤집은 블록을 4번 회전해보면서 해당 i번째의 블록과 일치하는지 확인한다
//	
//
//			for (int m = 0; m < 4; m++) {
//				vi problems;
//				problems.clear();
//				reverseClockRotation(reverse);
//				//회전된 블록을 i번째 블록과 0행0열,1열,2열...순으로 더하면서 합이 일치하는지 확인한다
//				for (int n = 0; n < 4; n++) {
//					int flag = 0;
//					int sumFlag = 0;
//					for (int o = 0; o < 4; o++) {
//						int sum = module[i][n][o] + reverse[n][o];
//						for (int p = 0; p < (int)problems.size(); p++) {
//							if (sum != problems[p]) {
//								flag = 1;
//								sumFlag = 1;
//								break;
//							}
//						
//						}
//						if (sumFlag == 1) break;
//						problems.push_back(sum);
//					}
//					//각각 더한값이 다르다면 다음for문 실행
//					if (flag == 1) break;
//					else iStResults.push_back(ii(problems[0],j));
//
//				}
//			}
//		}
//		
//		if ((int)iStResults.size() == 0)continue;
//		int max = iStResults[0].first;
//		int useIndex = 0;
//		for (int q = 1; q < (int)iStResults.size(); q++) {
//			if (iStResults[q].first > max) { 
//				max = iStResults[q].first;
//				useIndex = iStResults[q].second;
//			}
//		}
//		useBlock[useIndex] = true;
//		realResults.push_back(max);
//		cout << "i : " <<i<< endl;
//	}
//
//	cout << "?" << endl;
//	int sum = 0;
//	for (int i = 0; i < (int)realResults.size(); i++) sum += realResults[i];
//	return sum;
//}
int main() {
	static int module[MAX][4][4];

	srand(3); // 3 will be changed

	for (int tc = 1; tc <= 10; tc++)
	{
		for (int c = 0; c < MAX; c++)
		{
			int base = 1 + (rand() % 6);
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					module[c][y][x] = base + (rand() % 3);
				}
			}
		}

		cout << "#" << tc << " " << makeBlock(module) << endl;
	}

	return 0;
}