#include<iostream>
#include<vector>

using namespace std;

// 후위 순회를 수행하는 함수 정의
void postOrder(int left, int right, vector<int>& tree) {
	if (left > right) {
		return; // 기저 조건: 범위가 비정상적일 때 종료
	}

	int root = tree[left];// 루트 노드 값을 따로 저장

	// 루트보다 큰 첫 번째 노드를 찾기 위한 탐색
	int tmp = left + 1;
	for (int i = left+1 ; i <= right ; i++) {
		if (tree[i] > root) {
			tmp = i;
			break;
		}
	}

	// 후위 순회 재귀 호출
	postOrder(left + 1, tmp - 1, tree); // 루트보다 작은 노드들에 대해 후위 순회
	postOrder(tmp, right, tree); // 루트보다 큰 노드들에 대해 후위 순회

	// 모든 자식 노드들을 탐색한 후 루트 노드 출력
	cout << root << '\n';
}

/*
* 이진 검색 트리: 루트의 왼쪽은 루트보다 작고, 오른쪽은 루트보다 크다.
* 이진 검색 트리의 전위 순회 결과를 입력받아 후위 순회 결과를 출력하는 프로그램
* 전위 순회: 루트 -> 왼쪽 -> 오른쪽, 후위 순회: 왼쪽 -> 오른쪽 -> 루트
* 전위 순회 결과를 바탕으로 후위 순회 순서대로 탐색을 진행
*/

int main() {

    // 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력 받기
	int num;
	vector<int> tree;
	while (cin >> num) {
		tree.push_back(num); // 트리 구성을 위한 숫자 입력
	}

	// 후위 순회 실행 및 결과 출력
	postOrder(0, tree.size() - 1, tree);
}
