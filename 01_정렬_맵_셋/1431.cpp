#include <iostream>
#include <algorithm>

using namespace std;

//자리수 합 구하는 함수
int sumNum(string str) {
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] <= 57 && str[i] >= 48) {
			sum += str[i] - 48;
		}
	}
	return sum;
}

//비교함수
bool cmp(const string& w1, const string& w2) {
	int l1 = w1.length();
	int l2 = w2.length();

	//길이 같은 경우 : 자리수 계산
	if (l1 == l2) {
		int sum1 = sumNum(w1);
		int sum2 = sumNum(w2);

		if (sum1 == sum2) {
			//자릿수 같으면 사전순 정렬
			return w1 < w2;
		}
		else {
			return sum1 < sum2; //자릿수 합 기준 오름차순 정렬
		}
	}

	//길이 다른 경우 : 길이 기준 오름차순 정렬
	else {
		return l1 < l2;
	}

}

int main() {

	int n;
	cin >> n;

	string word[50];
	int l[50];

	//입력
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	
	//연산
	sort(word, word + n, cmp); //비교함수


	//정렬된 문자열 배열을 출력
	for (int i = 0; i < n; i++) {
		cout << word[i] << endl;
	}

	return 0;
}