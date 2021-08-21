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
vvi graph;
int n;
int solution(vector<vector<string>> relation) {
    //이름,전공,학년으로 구분하게 되면
    // 속성중 하나라도 제외하게 될 떄 유일성이 깨지지 않으므로 최소성을 만족하지 않는다    
    int answer = 0;

    
    vector<int> vg(relation[0].size());
    for (int i = 0; i < vg.size(); i++) {
        vg[i] = i;
    }
    vector<int> v(vg.size() , 0);
    vector<string> combinations;
    for (int i = 0; i < vg.size(); i++) {
        fill(v.begin(), v.end(), 0);
        for (int j = vg.size()-1; j >= vg.size()-i; j--) {
            v[j] = 1;
        }

        do {
            set<string> hi;
            vi index;
            string combination = "";
            for (int i = 0; i < v.size(); i++) {
                if (v.at(i) == 0) {

                    index.push_back(vg[i]);
                    combination += to_string(vg[i]);
                }
            }
            //0,1,2,3,4,5
            for (int relationRow = 0; relationRow < relation.size(); relationRow++) {
                string row = "";
                for (int i = 0; i < index.size(); i++) {
                    row += relation[relationRow][index[i]] + " ";
                }
                hi.insert(row);
            }

            if (hi.size() == relation.size()) {
                //set에 들어가있는 string들과 릴레이션의 로우사이즈가 같으면
                //해당 열의 조합으로 전체 식별이 가능한 것이므로 후보키가 될 가능성이 있다.

                //조합한 콤비네이션 중에서 기존 콤비네이션에 포함되는게 있으면
                //후보키 조건에 맞추기 위해 기존 콤비네이션을 삭제시킨다

                //combination이 02이고
                //기존에 들어있는 combination이 012라면?
                sort(combination.begin(), combination.end());
                int i = 0;
                for (i = 0; i < combinations.size(); i++) {
                    bool isDelete = true;

                    for (int j = 0; j < combination.size(); j++) {

                        //02가 012에 포함되지 않으면
                        if (combinations[i].find(combination[j]) == string::npos) {
                            isDelete = false;
                        }
                            
                    }
                    if (isDelete) {
                        combinations.erase(combinations.begin() + i);
                        i--;
                    }
                }
                
                combinations.push_back(combination);
            }
            hi.clear();
        } while (next_permutation(v.begin(), v.end()));
        

        
    }
    return combinations.size();
}
int main()
{
    //cout << solution({{"100", "100", "ryan", "music", "2"}, {"200", "200", "apeach", "math", "2"}, {"300", "300", "tube", "computer", "3"}, {"400", "400", "con", "computer", "4"}, {"500", "500", "muzi", "music", "3"}, {"600", "600", "apeach", "music", "2"}} ) << endl;;
    //cout << solution({ {"a","aa"},{"aa","a"},{"a","a"}}) << endl;
    cout << solution({ {"a", "1", "aaa", "c", "ng"},{"b","1", "bbb", "c", "g"},{"c", "1", "aaa", "d", "ng"},{"d", "2", "bbb", "d", "ng"}}) << endl;
}