#include<iostream>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
	char L[5][5] =
	{ {'B','W','W' ,'W','U'},
	{'O','G','G','G','R'},
	{ 'O','G','G','G','R' },
	{ 'O','G','G','G','R' },
	{'D','Y','Y','Y','F'} };
	char U[5][5] =
	{ {'L','O','O','O','B' },
	{'G','W','W','W','B'},
	{ 'G','W','W','W','B' },
	{ 'G','W','W','W','B' },
	{ 'F','R','R','R','R' } };
	char D[5][5] =
	{ {'L','R','R','R','F' },
	{ 'G','Y','Y','Y','B' },
	{ 'G','Y','Y','Y','B' },
	{ 'G','Y','Y','Y','B' },
	{ 'B','O','O','O','R' } };
	char R[5][5] =
	{ { 'F','W','W','W','U' },
	{ 'R','B','B','B','O' },
	{ 'R','B','B','B','O' },
	{ 'R','B','B','B','O' },
	{'D','Y','Y','Y','B' } };
	char B[5][5] =
	{ { 'Z','W','W' ,'W','Z' },
	{ 'O','G','G','G','R' },
	{ 'O','G','G','G','R' },
	{ 'O','G','G','G','R' },
	{ 'Z','Y','Y','Y','Z' } };
	char F[5][5] =
	{ { 'L','W','W','W','U' },
	{ 'G','R','R','R','B' },
	{ 'G','R','R','R','B' },
	{ 'G','R','R','R','B' },
	{ 'D','Y','Y','Y','R' } };


	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int rotation;
		cin >> rotation;
		for (int i = 0; i < rotation * 3; i++) {
			char a, b, c;
			cin >> a >> b >> c;

		}


	}
}
