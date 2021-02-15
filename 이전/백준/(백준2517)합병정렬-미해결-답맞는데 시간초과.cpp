#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;


class hi {
public:
	int order;
	int value;
	int score;

};
vector<hi> S(500001);
const bool cmp(const hi &a, const hi &b) {
	return a.order <b.order;
}
void merge(int, int, int);
void mergesort(int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, mid, high);
	}
}
void merge(int low, int mid, int high) {
	int i, j, k;
	vector<hi> U(500001);
	i = low, j = mid + 1; k = low;
	while (i <= mid&& j <= high) {
		if (S[i].value < S[j].value) {
			U[k].score = S[j].score - (j - k);
			U[k].value = S[j].value;
			U[k].order = S[j].order;
			j++;
		}
		else {
			U[k] = S[i];
			i++;
		}
		k++;
	}
	int asdf = k;
	if (i > mid) {
		for (int a = j; a <= high; a++) {
			U[asdf++] = S[a];
		}
	}
	else {
		for (int a = i; a <= mid; a++) {
			U[asdf++] = S[a];
		}
	}
	int asdfg = low;
	for (int a = low; a <= high; a++) { //비교한값들을 U에 넣어놓고 한번에 S배열(원래배열)에 대입
		S[a] = U[asdfg++];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S[i].value;
		S[i].score = i;
		S[i].order = i;
	}
	mergesort(1, N);
	sort(S.begin() + 1, S.begin() + N + 1, cmp);
	for (int i = 1; i <= N; i++) {
		cout << S[i].score << endl;
	}
}