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
vvi graph;
int n;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    // 왼손엄지 = 10
    // 오른손엄지 = 20
    vector<ii> m(10);
    int number = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[number] = ii(i, j);
            number++;
        }
    }
    m[0] = ii(3, 1);
    ii left, right;
    left = ii(3, 0);
    right = ii(3, 2);
    for (int i = 0; i < numbers.size(); i++) {
        int clickNumber = numbers[i];

        if (clickNumber == 1 || clickNumber == 4 || clickNumber == 7) {
            answer += "L";
            left = m[clickNumber];
        }
        else if (clickNumber == 3 || clickNumber == 6 || clickNumber == 9) {
            answer += "R";
            right = m[clickNumber];
        }
        else {
            //2,5,8,0

            int leftDist = abs(m[clickNumber].first - left.first) + abs(m[clickNumber].second - left.second);

            int rightDist = abs(m[clickNumber].first - right.first) + abs(m[clickNumber].second - right.second);
            if (leftDist > rightDist) {
                //오른손으로 누른다
                answer += "R";
                right = m[clickNumber];
            }
            else if (leftDist < rightDist) {
                //왼손으로 누른다
                answer += "L";
                left = m[clickNumber];
            }
            else {
                //같으면
                if (hand == "right") {
                    //오른손잡이
                    answer += "R";
                    right = m[clickNumber];
                }
                else {
                    answer += "L";
                    left = m[clickNumber];
                }
            }

        }


    }
    return answer;
}
int main()
{
    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right") << endl;;
}