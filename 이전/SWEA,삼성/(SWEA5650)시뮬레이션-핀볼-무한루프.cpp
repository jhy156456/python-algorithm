#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include<cstring>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int problem[101][101];
int wallNextLocation[6][4] =
{ { -1,-1,-1,-1 } ,{ 1,3,0,2 },{ 3,0,1,2 },{ 2,0,3,1 },{ 1,2,3,0 },{ 1,0,3,2 } };
int t, n, result;
vector<ii> oneHole, twoHole, threeHole, fourHole, fiveHole;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int main() {
	cin >> t;
	int testCase = 1;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> problem[i][j];
				if (problem[i][j] == 6) {
					oneHole.push_back(ii(i, j));
				}
				else if (problem[i][j] == 7) {
					twoHole.push_back(ii(i, j));
				}
				else if (problem[i][j] == 8) {
					threeHole.push_back(ii(i, j));
				}
				else if (problem[i][j] == 9) {
					fourHole.push_back(ii(i, j));
				}
				else if (problem[i][j] == 10) {
					fiveHole.push_back(ii(i, j));
				}
			}
		}


		for (int i = 8; i < n; i++) {
			for (int j = 6; j < n; j++) {
				if (problem[i][j] == 0) {
					//��,��,��,�� �� ������

					for (int k = 0; k < 4; k++) {
						int ballLocationY = i + dy[k];
						int ballLocationX = j + dx[k];
						if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) continue;
						int ballDirection = k;
						int score = 0;
						//ó���� ���� �����..
						while (ballLocationY != i || ballLocationX != j) {
							//�ö󰡴ٰ� ������ ƨ��
							if ((ballLocationY == 0 && ballDirection == 0 && problem[ballLocationY][ballLocationX] == 0)
								|| (ballLocationY == n && ballDirection == 1 && problem[ballLocationY][ballLocationX] == 0)
								|| (ballLocationX == 0 && ballDirection == 2 && problem[ballLocationY][ballLocationX] == 0)
								|| (ballLocationX == n && ballDirection == 3 && problem[ballLocationY][ballLocationX] == 0)) {
								ballDirection = wallNextLocation[5][ballDirection];
								ballLocationY = ballLocationY + dy[ballDirection];
								ballLocationX = ballLocationX + dx[ballDirection];
								score++;
							}
							//���⺯��
							else if (problem[ballLocationY][ballLocationX] == 1
								|| problem[ballLocationY][ballLocationX] == 2
								|| problem[ballLocationY][ballLocationX] == 3
								|| problem[ballLocationY][ballLocationX] == 4
								|| problem[ballLocationY][ballLocationX] == 5) {
								int tempballDirection = ballDirection;
								ballDirection = wallNextLocation[problem[ballLocationY][ballLocationX]][ballDirection];
								ballLocationY = ballLocationY + dy[ballDirection];
								ballLocationX = ballLocationX + dx[ballDirection];
								//������ ��Ͽ� ƨ�ܼ� �����°� �ٽõ��ƿ��� ���
								if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
									ballLocationY = ballLocationY - dy[ballDirection];
									ballLocationX = ballLocationX - dx[ballDirection];
									ballDirection = wallNextLocation[5][tempballDirection];
									ballLocationY = ballLocationY + dy[ballDirection];
									ballLocationX = ballLocationX + dx[ballDirection];
									score++;
								}
								score++;

							}

							else if (problem[ballLocationY][ballLocationX] == 6) {
								//ù���� ��Ȧ�� �������̶��
								if (oneHole[0].first == ballLocationY && oneHole[0].second == ballLocationX) {
									ballLocationY = oneHole[1].first + dy[ballDirection];
									ballLocationX = oneHole[1].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballLocationY = oneHole[0].first + dy[ballDirection];
										ballLocationX = oneHole[0].second + dx[ballDirection];
										score++;
									}
								}
								//�ι�° ��Ȧ�� �������̶��
								else {
									ballLocationY = oneHole[0].first + dy[ballDirection];
									ballLocationX = oneHole[0].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballLocationY = oneHole[1].first + dy[ballDirection];
										ballLocationX = oneHole[1].second + dx[ballDirection];
										score++;
									}
								}

							}
							else if (problem[ballLocationY][ballLocationX] == 7) {
								//ù���� ��Ȧ�� �������̶��
								if (twoHole[0].first == ballLocationY && twoHole[0].second == ballLocationX) {
									ballLocationY = twoHole[1].first + dy[ballDirection];
									ballLocationX = twoHole[1].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballDirection = wallNextLocation[5][ballDirection];
										ballLocationY = twoHole[0].first + dy[ballDirection];
										ballLocationX = twoHole[0].second + dx[ballDirection];

										score++;
									}
								}
								//�ι�° ��Ȧ�� �������̶��
								else {
									ballLocationY = twoHole[0].first + dy[ballDirection];
									ballLocationX = twoHole[0].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballDirection = wallNextLocation[5][ballDirection];
										ballLocationY = twoHole[1].first + dy[ballDirection];
										ballLocationX = twoHole[1].second + dx[ballDirection];
										score++;
									}
								}
							}
							else if (problem[ballLocationY][ballLocationX] == 8) {
								//ù���� ��Ȧ�� �������̶��
								if (threeHole[0].first == ballLocationY && threeHole[0].second == ballLocationX) {
									ballLocationY = threeHole[1].first + dy[ballDirection];
									ballLocationX = threeHole[1].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballLocationY = threeHole[0].first + dy[ballDirection];
										ballLocationX = threeHole[0].second + dx[ballDirection];
										score++;
									}
								}
								//�ι�° ��Ȧ�� �������̶��
								else {
									ballLocationY = threeHole[0].first + dy[ballDirection];
									ballLocationX = threeHole[0].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballDirection = wallNextLocation[5][ballDirection];
										ballLocationY = threeHole[1].first + dy[ballDirection];
										ballLocationX = threeHole[1].second + dx[ballDirection];
										score++;
									}
								}
							}
							else if (problem[ballLocationY][ballLocationX] == 9) {
								//ù���� ��Ȧ�� �������̶��
								if (fourHole[0].first == ballLocationY && fourHole[0].second == ballLocationX) {
									ballLocationY = fourHole[1].first + dy[ballDirection];
									ballLocationX = fourHole[1].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballDirection = wallNextLocation[5][ballDirection];
										ballLocationY = fourHole[0].first + dy[ballDirection];
										ballLocationX = fourHole[0].second + dx[ballDirection];
										score++;
									}
								}
								//�ι�° ��Ȧ�� �������̶��
								else {
									ballLocationY = fourHole[0].first + dy[ballDirection];
									ballLocationX = fourHole[0].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballDirection = wallNextLocation[5][ballDirection];
										ballLocationY = fourHole[1].first + dy[ballDirection];
										ballLocationX = fourHole[1].second + dx[ballDirection];
										score++;
									}
								}
							}
							else if (problem[ballLocationY][ballLocationX] == 10) {
								//ù���� ��Ȧ�� �������̶��
								if (fiveHole[0].first == ballLocationY && fiveHole[0].second == ballLocationX) {
									ballLocationY = fiveHole[1].first + dy[ballDirection];
									ballLocationX = fiveHole[1].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballDirection = wallNextLocation[5][ballDirection];
										ballLocationY = fiveHole[0].first + dy[ballDirection];
										ballLocationX = fiveHole[0].second + dx[ballDirection];
										score++;
									}
								}
								//�ι�° ��Ȧ�� �������̶��
								else {
									ballLocationY = fiveHole[0].first + dy[ballDirection];
									ballLocationX = fiveHole[0].second + dx[ballDirection];
									if (ballLocationY < 0 || ballLocationX < 0 || ballLocationY >= n || ballLocationX >= n) {
										ballDirection = wallNextLocation[5][ballDirection];
										ballLocationY = fiveHole[1].first + dy[ballDirection];
										ballLocationX = fiveHole[1].second + dx[ballDirection];
										score++;
									}
								}
							}
							//��Ȧ
							else if (problem[ballLocationY][ballLocationX] == -1) {
								break;
							}
							//���� ��ƨ��� �� ����
							else {
								ballLocationY = ballLocationY + dy[ballDirection];
								ballLocationX = ballLocationX + dx[ballDirection];
							}

						}
						//���� while�ǳ�
						if (result < score) {
							result = score;
						}
					}
					//�� �߰�ȣ�� for4�����ǳ�

				}
			}
		}


		cout << "#" << testCase << " " << result << endl;
		memset(problem, 0, sizeof(problem));
		oneHole.clear();
		twoHole.clear();
		threeHole.clear();
		fourHole.clear();
		fiveHole.clear();
		testCase++; result = 0;
	}
}

