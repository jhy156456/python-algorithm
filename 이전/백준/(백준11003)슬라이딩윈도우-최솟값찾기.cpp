#include<iostream>
#include<deque>
#include<vector>
#include<queue>
using namespace std;
int n;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

priority_queue<int> results;
void SlidingWindow(vi &A, int n, int K) {
	deque<ii> window;
	for (int i = 0; i < n; i++) {
		while (!window.empty() && window.back().first >= A[i]) {
			window.pop_back();
		}
		window.push_back(ii(A[i], i));
		while (window.front().second <= i - K) {
			window.pop_front();
		}
		cout << window.front().first << " ";

	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi A(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	SlidingWindow(A, n, k);
	cout << endl;
}