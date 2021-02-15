#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int c,n,m;
int h, w;
const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1} },
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1} }
};
void getCase() {

}
int main() {
	cin >> c;
	
	vvi problems = vvi(c, vi(c, 0));
	int y = 0, x = 0, number = 1;
	vector<pair<int, int>> rotation;
	rotation.push_back(ii(0, 1)); rotation.push_back(ii(1, 0)); rotation.push_back(ii(0, -1)); rotation.push_back(ii(-1, 0));
	int count = 0;

	while(number!=c*c+1){
		if(y < c && x < c && y >= 0 && x >= 0) {
			if (problems[y][x] == 0) {
				problems[y][x] = number++;
				y += rotation[count].first;
				x += rotation[count].second;
				continue;
			}
		}
		if (count == 0) x--; else if (count == 1)y--; else if (count == 2)x++; else if (count == 3)y++;
		count++;
		if (count == 4) count = 0;
		y += rotation[count].first;
		x += rotation[count].second;
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			cout << problems[i][j] << "  ";
		}
		cout << endl;
	}


	//while (c--) {
	//	cin >> h >> w;
	//	vvc problems = vvc(h, vc(w, '#'));
	//	for (int i = 0; i < h; i++) {
	//		for (int j = 0; j < w; j++) {
	//			char p;
	//			cin >> p;
	//			problems[i][j] = p;
	//		}
	//	}
	//	getCase();





	//}
}