#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> vi;
int n, a[1000000];
vi dp;
int b_s(int length, int value) { 
//	if (arr == nullptr || length < 0) return -1;
	int left = 0; int right = length - 1; int mid; 
	bool isRight = 0; bool isLeft = 0;
	while (left <= right) { 
		mid = left + (right - left) / 2; 
		if (dp[mid] == value) { 
			return mid; 
		} else if (dp[mid] < value) { 
			left = mid + 1;
			isLeft = 1; isRight = 0;
		} else if (dp[mid] > value) { 
			right = mid - 1;
			isRight = 1; isLeft = 0;
		}
	} 
	if (isRight == true) return right + 1;
	else if (isLeft == true)return left;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	dp.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		//dp의 최댓값보다 작으면 들어갈 위치를 찾아보자
		if (dp[dp.size()-1] > a[i]) {
			int dpIndex = b_s(dp.size(), a[i]);
			dp[dpIndex] = a[i];
		}
		else if(dp[dp.size() - 1] < a[i]){
			dp.push_back(a[i]);
		}
	}

	//for (int i = 0; i < dp; i++)cout << dp[i] << " ";
	cout << dp.size()<<endl;
	
}