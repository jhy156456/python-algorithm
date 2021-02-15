#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int MAX_DISCS = 12;

int get(int state, int index) {
	int a = (state >> (index * 2)) & 3;
	cout << "----------------get--------------" << endl;
	cout << "state : " << state << endl;
	cout << "index : " << index << endl;
	cout << "get return: " << a << endl;
	return (state >> (index * 2)) & 3;
}
int set(int state, int index, int value) {
	int a = (state & ~(3 << (index * 2))) | (value << (index * 2));
	cout << "----------------set--------------" << endl;
	cout << "state : " << state << endl;
	cout << "index : " << index << endl;
	cout << "value : " << value << endl;
	cout << "set return : " << a << endl;
	return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int c[1 << (MAX_DISCS * 2)];
// discs ���� ������ �ְ�, �� ������ ���� ��ġ�� ���� ��ġ��
// begin, end �� �־��� �� �ּ� �������� ���� ����Ѵ�.
int bfs(int discs, int begin, int end) {
	if (begin == end) return 0;
	queue<int> q;
	memset(c, -1, sizeof(c));

	q.push(begin);
	c[begin] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		// �� ��տ��� ���� ���� �ִ� ������ ��ȣ�� ����Ѵ�
		int top[4] = { -1, -1, -1, -1 };
		for (int i = discs - 1; i >= 0; --i)
			top[get(here, i)] = i;

		// i�� ����� �� ���� �ִ� ������ j�� ������� �ű��
		for (int i = 0; i < 4; ++i)
			// i�� ��տ� ������ ������ �� �ȴ�
			if (top[i] != -1)
				for (int j = 0; j < 4; j++)
					// j�� ����� ��� �ְų�, �� ���� ������ �� Ŀ�� �Ѵ�
					if (i != j && (top[j] == -1 || top[j] > top[i])) {
						int there = set(here, top[i], j);
						if (c[there] != -1) continue;
						c[there] = c[here] + 1;
						if (there == end) return c[there];
						q.push(there);
					}
	}
	return -1;
}

// x �� ��ȣ�� ��ȯ�Ѵ�
int sgn(int x) { if (x < 0) return -1; if (x > 0) return 1; return 0; }
// x �� ���밪�� 1 ������Ų��
int incr(int x) { if (x < 0) return x - 1; return x + 1; }

// discs ���� ������ �ְ�, �� ������ ���� ��ġ�� ���� ��ġ��
// begin, end �� �־��� �� �ּ� �������� ���� ����Ѵ�.
int bidir(int discs, int begin, int end) {
	if (begin == end) return 0;
	queue<int> q;
	// �ʱ�ȭ�� 0 ���� �ϴµ� ����
	memset(c, 0, sizeof(c));
	// ������ Ž���� �����, ������ Ž���� ������ ǥ���Ѵ�
	q.push(begin); c[begin] = 1;
	q.push(end); c[end] = -1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		int top[4] = { -1, -1, -1, -1 };
		for (int i = discs - 1; i >= 0; --i)
			top[get(here, i)] = i;

		for (int i = 0; i < 4; ++i)
			if (top[i] != -1)
				for (int j = 0; j < 4; j++)
					if (i != j && (top[j] == -1 || top[j] > top[i])) {
						int there = set(here, top[i], j);
						// ���� �湮���� ���� ������ ���
						if (c[there] == 0) {
							c[there] = incr(c[here]);
							q.push(there);
						}
						// ������� ���� ���
						else if (sgn(c[there]) != sgn(c[here]))
							return abs(c[there]) + abs(c[here]) - 1;
					}
	}
	return -1;
}
/*
int bidir(int begin, int end) {
if(begin == end) return 0;

queue<State> q;
map<State, int> c;
q.push(begin);
c[begin] = 1;
q.push(end);
c[end] = -1;
while(!q.empty()) {
State here = q.front();
q.pop();
int dist = c[here];
for(int i = 0; i < 4; ++i)
for(int j = 0; j < 4; j++)
if(i != j && canMove(here, i, j)) {
State there = move(here, i, j);
map<State,int>::iterator it = c.find(there);
if(it == c.end()) {
c[there] = incr(dist);
q.push(there);
}
else if(sgn(dist) != sgn(it->second))
return abs(dist) + abs(it->second) - 1;
}
}
return -1;
}
*/

int solve(int discs, int begin, int end, const string& algo) {
	if (algo == "BFS") return bfs(discs, begin, end);
	if (algo == "BIDIR") return bidir(discs, begin, end);
	cout << "algorithm " << algo << " is unknown" << endl;
	return -1;
}

int main(int argc, char* argv[]) {
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) {
		int begin = 0;
		int discs;
		cin >> discs;
		for (int i = 0; i < 4; i++) {
			int n;
			cin >> n;
			for (int j = 0; j < n; j++) {
				int d;
				cin >> d;
				begin = set(begin, d - 1, i);
			}
		}

		assert(discs <= MAX_DISCS);

		int end = 0;
		for (int i = 0; i < discs; i++) {
			end = set(end, i, 3);

		}

		int sol = solve(discs, begin, end, argc == 1 ? "BFS" : argv[1]);
		printf("%d\n", sol);
	}
}

