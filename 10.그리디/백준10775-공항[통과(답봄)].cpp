#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int g, p;
vi problems;
vi parent(100001);
/*
높이가 낮은 애의 부모를 높이 높은애로 설정한다

*/

int findParent(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = findParent(parent[a]);
}
void merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	parent[a] = b;
}

int main() {
	cin >> g >> p;
	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		problems.push_back(a);

	}
	for (int i = 0; i < parent.size(); i++) {
		parent[i] = i;
	}
	int count = 0;
	for (int i = 0; i < problems.size(); i++) {
		int result = findParent(problems[i]);
		if (result == 0) {
			break;
		}
		merge(result, result - 1);
		count++;
		
	}
	cout << count << endl;

}


