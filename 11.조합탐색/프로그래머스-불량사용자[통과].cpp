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
vs userId;
void printVector(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int user_id_idx_row_size;
set<string> possbleString;
int banned_id_size;
void getPossibleCombination(string answer,int row, int col,vvi &user_id_idx) {

    if (row == banned_id_size-1) {
        //기저사례
        answer = answer + to_string(user_id_idx[row][col]);
        set<char> hi;
        for (int i = 0; i < answer.size(); i++) {
            hi.insert(answer[i]);
        }
        string newAnswer = "";
        for (auto it = hi.begin(); it != hi.end(); it++) {
            newAnswer += *it;
        }
        
        cout << newAnswer << endl;
        if (newAnswer.size() == banned_id_size) {
            possbleString.insert(newAnswer);
        }
        return;
    }
    row++;
    for (int i = 0; i < user_id_idx[row].size(); i++) {
        getPossibleCombination(answer+to_string(user_id_idx[row-1][col]), row, i, user_id_idx);
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    userId = user_id;
    int answer = 0;
    vector<set<string>> v;
    vvi user_id_idx(banned_id.size());
    for (int i = 0; i < user_id.size(); i++) {
        for (int j = 0; j < banned_id.size(); j++) {
            if (user_id[i].size() == banned_id[j].size()) {
                //size같은지 검사하고
                string userId = user_id[i];
                string banId = banned_id[j];
                bool same = true;
                for (int k = 0; k < userId.size(); k++) {
                    if (banId[k] == '*') {
                        continue;
                    }
                    if (userId[k] != banId[k]) {
                        //하나라도 다른 값이 있으면 경우에 수에 추가하지 않는다
                        same = false;
                        break;
                    }
                }
                if (same) {
                    user_id_idx[j].push_back(i);
                }

            }



        }
    }
    //printVector(user_id_idx);

    user_id_idx_row_size = user_id_idx.size();
    banned_id_size = banned_id.size();
    for (int i = 0; i < user_id_idx[0].size(); i++) {
         getPossibleCombination("",0, i, user_id_idx);
    }
    return possbleString.size();
}
int main()
{
    //cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" }) << endl;
    cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" }) << endl;
}