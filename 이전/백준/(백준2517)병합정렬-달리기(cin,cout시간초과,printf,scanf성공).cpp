#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N;
struct Person {
	int problem;
	int nowScore;
	int forSort;
};
vector<Person> sorted(500000);
const bool comp(const Person &a, const Person &b) {
	return a.forSort < b.forSort;
}
void merge(vector<Person> &data, int start, int mid, int end) {
	int i = start; int j = mid + 1;  int k = start;
	while (i <= mid && j <= end) {
		if (data[i].problem <= data[j].problem) { //실력이 좋아서 앞으로가는경우
			data[j].nowScore -= (j - k);
			sorted[k] = data[j];
			j++;
		}
		else {
			sorted[k] = data[i];
			i++;
		}
		k++;
	}
	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sorted[k] = data[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = data[t];
			k++;
		}
	}
	for (int t = start; t <= end; t++) {
		data[t] = sorted[t];
	}
}

void mergeSort(vector<Person> &data, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(data, start, mid);
		mergeSort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}
int main() {
	cin >> N;
	vector<Person> problems;
	problems.push_back(Person());
	problems[0].nowScore = -1; problems[0].problem = -1; //1부터 사용하기 위한 쓰레기값 삽입 필요없다고 생각하면 나중에 빼자
	for (int i = 1; i <= N; i++) {
		int a;
		scanf("%d", &a);
		problems.push_back(Person());
		problems[i].problem = a;
		problems[i].nowScore = i;
		problems[i].forSort = i;
	}
	mergeSort(problems, 1, N);
	sort(problems.begin(), problems.begin()+N+1,comp);
	for (int i = 1; i <= N; i++) {
		printf("%d\n", problems[i].nowScore);
	}
}

