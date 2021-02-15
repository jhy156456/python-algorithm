#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

#define MAX_N 1000

void print_array(const char *s, int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i) printf(", ");
		else printf("%s: [", s);
		printf("%d", a[i]);
	}
	printf("]\n");
}

void reconstruct_print(int end, int a[], int p[]) {
	int x = end;
	stack<int> s;
	for (; p[x] >= 0; x = p[x]) s.push(a[x]);
	printf("%d", a[x]);
	for (; !s.empty(); s.pop()) printf(" %d", s.top());
	cout << endl;
}
int n, A[1000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> A[i];
	
	int L[MAX_N], L_id[MAX_N], P[MAX_N];

	int lis = 0, lis_end = 0;
	for (int i = 0; i < n; ++i) {
		int pos = lower_bound(L, L + lis, A[i]) - L;
		L[pos] = A[i];
		L_id[pos] = i;
		P[i] = pos ? L_id[pos - 1] : -1;
		if (pos + 1 > lis) {
			lis = pos + 1;
			lis_end = i;
		}
	}

	cout << lis << endl;
	reconstruct_print(lis_end, A, P);
	return 0;
}