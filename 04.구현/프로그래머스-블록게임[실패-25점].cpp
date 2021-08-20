#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> si;
typedef vector<vi> vvi;
typedef vector<vector<int>> vvi;
vvi graph;
int n;
bool isPossibleTwoByThree(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= n || y+2 > n || x+3 > n) {
        return false;
    }
    int notMinusOneNumber = 0;
    int notMinusOneNumberCount = 0;
    for (int i = y; i < y + 2; i++) {
        for (int j = x; j < x + 3; j++) {
            if (graph[i][j] != -1 && graph[i][j] != 0) {
                notMinusOneNumber = graph[i][j];
                break;
            }
            else if (graph[i][j] == 0) {
                return false;
            }
        }
    }
    for (int i = y; i < y + 2; i++) {
        for (int j = x; j < x + 3; j++) {
            if (!(graph[i][j] == -1 || graph[i][j] == notMinusOneNumber)) {
                return false;
            }
            if (graph[i][j] == notMinusOneNumber) {
                notMinusOneNumberCount++;
            }
        }
    }
    if (notMinusOneNumberCount != 4) {
        return false;
    }



    for (int i = y; i < y+2; i++) {
        for (int j = x; j < x+3; j++) {
            graph[i][j] = 0;
        }
    }
    return true;
}
/*
* ������ �������� 6�� �˻��غ��� 1���� Ʈ�� ��� �ν� �� �����Ƿ�
* �ν� �Ŀ� (0���� ����) true ��ȯ
* ī��Ʈ�� ������Ų��.
*/
bool isPossibleThreeByTwo(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= n || y + 3 > n || x + 2 > n) {
        return false;
    }
    int notMinusOneNumber = 0;
    int notMinusOneNumberCount = 0;
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 2; j++) {
            if (graph[i][j] != -1 && graph[i][j] != 0) {
                notMinusOneNumber = graph[i][j];
                break;
            }
            else if (graph[i][j] == 0) {
                return false;
            }
        }
    }
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 2; j++) {
            if (!(graph[i][j] == -1 || graph[i][j] == notMinusOneNumber)) {
                return false;
            }
            if (graph[i][j] == notMinusOneNumber) {
                notMinusOneNumberCount++;
            }
        }
    }
    if (notMinusOneNumberCount != 4) {
        return false;
    }

    for (int i = y; i < y+3; i++) {
        for (int j = x; j < x+2; j++) {
            graph[i][j] = 0;
        }
    }
    return true;
}
void printVector(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << setw(3)<< v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int boardSize = board.size();
    n = boardSize;
    graph = board;
    int col = 0;
    bool whileCheck = true;
    while (whileCheck) {
        for (int row = 0; row < boardSize - 1; row++) {
            if (row == 0 && graph[row][col] == -1) {
                break;
            }
            if ( ( graph[row+1][col] != 0 &&  graph[row][col] == 0 ) ||
                ( (row+1 == boardSize-1)   && (graph[row+1][col] == 0) ) ) {
                if (((row + 1 == boardSize - 1) && (graph[row + 1][col] == 0))) {
                    //�ٴڱ��� �°��
                    row++;
                }
                //�Ʒ� ���� ������
                //���⿡ ������ ��ġ�ϰ� �˻��Ѵ�.
                graph[row][col] = -1;
                for (int i = row; i > row - 2; i--) {
                    for (int j = col; j > col - 3; j--) {
                        if (isPossibleTwoByThree(i, j)) {
                            answer++;
							//printVector(graph);
                            break;
                        }
                    }
                }

                for (int i = row; i > row - 3; i--) {
                    for (int j = col; j > col - 2; j--) {
                        if (isPossibleThreeByTwo(i, j)) {
                            answer++;
                            //printVector(graph);
                            break;
                        }
                    }
                }
                break;
            }

        }
        
        col++;
        col %= boardSize;
        
        whileCheck = false;
        for (int i = 0; i < boardSize; i++) {
            if (graph[0][i] == 0) {
                //0�ΰ� �ϳ��� �ִٸ� ������ �� �׾ƺ���.
                whileCheck = true;
                break;
            }
        }
    }
    return answer;

}
int main()
{

    //cout << solution({{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,4,4,0,0,0},{0,0,0,0,3,0,4,0,0,0},{0,0,0,2,3,0,0,0,5,5},{1,2,2,2,3,3,0,0,0,5},{1,1,1,0,0,0,0,0,0,5}}) << endl;
    //cout << solution({ {0, 2, 0, 0},{1, 2, 0, 4},{1, 2, 2, 4},{1, 1, 4, 4} }) << endl;
    cout << solution({{2,2,0,0},{1,2,0,4},{1,2,0,4},{1,1,4,4}}) << endl;
    printVector(graph);
}