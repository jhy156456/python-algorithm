#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include<sstream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> si;
typedef vector<vi> vvi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
using namespace std;

void printVector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
int checkTowByTwo(int m, int n,vector<string>& board) {
    printVector(board);
    set<ii> willDelete;
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n-1; j++) {

            if (board[i][j] != ' ' && 
                (board[i][j] == board[i][j + 1]) &&
                (board[i][j] == board[i + 1][j + 1]) &&
                (board[i + 1][j] == board[i][j])) {
                willDelete.insert(ii(i, j));
                willDelete.insert(ii(i, j+1));
                willDelete.insert(ii(i+1, j));
                willDelete.insert(ii(i+1, j+1));
            }
        }
    }
    for (auto it = willDelete.begin(); it != willDelete.end(); it++) {
        ii hi = *it;
        board[hi.first][hi.second] = ' ';
    }

    return willDelete.size();
}
int solution(int m, int n, vector<string> board) {
    //높이 m, 폭 n
    int answer = 0;
    while (true) {
        int check = checkTowByTwo(m,n,board);
        if (check == 0) {
            break;
        }
        answer += check;
        for (int j = 0; j < board.size(); j++) {
            //0열 맨 아래 행 부터 시작한다
            int voidHeight = 0;
            int accHeight = 0;
            for (int i = m-1; i >=0 ; i--) {
                if (board[i][j] == ' ') {
                    //현재 빈공간이면
                    voidHeight++;
                    continue;
                }
                if (voidHeight == 0) {
                    continue;
                }
                //빈공간 아니면 아래로 내린다
                accHeight += voidHeight;
                board[i + accHeight][j] = board[i][j];
                board[i][j] = ' ';
                if (i > 0 && board[i - 1][j] == ' ') {
                    //내 위가 빈공간이면 높이를 0부터 다시센다
                    voidHeight = 0;
                }
                else {
                    //내 위가 빈공간이 아니면 같은 높이만큼 내려줘야 하므로 누적 높이를 초기화한다
                    accHeight = 0;
                }
            }
        }
    }
    return answer;
}
int main() {
    cout << solution(4, 5, { "AAAAA","AUUUA","AUUAA","AAAAA" }) << endl;
}