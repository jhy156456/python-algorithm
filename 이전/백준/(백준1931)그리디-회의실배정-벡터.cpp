#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	//문제해결전략
	vector<pair<int, int>>order;
	int a, b;
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		cin >> b;
		order.push_back(make_pair(b,a));
	}
	//for (int i = 0; i < N; i++) cout << order[i].first << " " << order[i].second << endl;

	//이거 하니까 맞고 안하니까 틀렸다고나옴 왜지?? 
	//테스트케이스에는 회의 마감시간이 4,5,6,...14 순서대로되어있는데
	//안그럴 수도 있나?
	//문제에서 주어진 회의시간의 마감시간이 테스트케이스처럼 순서대로 되어있다고 얘기하지 않았으므로
	//소팅을 한번 해준다!!
	sort(order.begin(), order.end());


	//for (int i = 0; i < N; i++) cout << order[i].first << " " << order[i].second << endl;

	int earliest = 0, selected = 0;
	for (int i = 0; i < order.size(); i++) {
		int meetingBegin = order[i].second, meetingEnd = order[i].first;
		if (earliest <= meetingBegin) {
			earliest = meetingEnd;
			++selected;
		}
	}
	cout << selected;
	return 0;
}

/*내 코드 : 시간초과코드
int meeting[100000][2] = { 0 };
int N = 0;
int count = 1;
cin >> N;
for (int i = 0; i < N; i++) {
cin >> meeting[i][0];
cin >> meeting[i][1];

}
int i = 0;
int base = 0;
while(i<N){

for(int j=i+1; j<N; j++){
if (meeting[i][1] <= meeting[j][0]) {
count++;
i = j;
if (j == N - 1)base = -1;
break;
}

}
if (base == -1) break;
}

cout << count << endl;*/