#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n, w;
ii police1,police2;
queue<ii> problem;

int sameCost(int incident) {

}
int main(){
	cin >> n>>w;
	for (int i = 0; i < w; i++) {
		int a, b;
		cin >> a >> b;
		problem.push(ii(a, b));
	}
	police1 = ii(1, 1);
	police2 = ii(n, n);
	int minCost = 0;

	ii hereIncident = problem.front();

	int police1Go = abs(police1.first - hereIncident.first) + abs(police1.second - hereIncident.second);
	int police2Go = abs(police2.first - hereIncident.first) + abs(police2.second - hereIncident.second);

	if (police1Go < police2Go) {//1번 경찰차가 가는게 더 빠름
		minCost += police1Go;
		police1 = hereIncident;
		problem.pop();
	}
	else if (police1Go > police2Go) {//2번 경찰차가 가는게 더 빠름
		minCost += police2Go;
		police2 = hereIncident;
		problem.pop();
	}
	else {// 둘이 가는게 같음
		  /*
		  1을 선택할지 2를 선택할지 결정해야한다
		  2->1->2?
		  2->1->1?
		  2->2->1?
		  2->2->2?
		  */

	}

}
int whichPolice1() {

}
int whichPolice2() {

}