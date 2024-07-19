#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> list, tree; // 각 노드의 연결 정보 및 트리 구조를 담을 벡터
vector<int> parent, subtree_size; // 부모 노드 정보 및 각 노드의 서브트리 크기를 담을 벡터

void makeTree(int curNode, int p) {
    for (int node : list[curNode]) {
        if (node != p) {
            tree[curNode].push_back(node); // 트리 구조 생성
            parent[node] = curNode; // 부모 노드 정보 업데이트
            makeTree(node, curNode); // 재귀적으로 서브트리 생성
        }
    }
}

void countSubtreeNodes(int curNode) {
    subtree_size[curNode] = 1; // 현재 노드를 포함한 서브트리의 크기 초기화

    for (int node : tree[curNode]) {
        countSubtreeNodes(node); // 재귀적으로 서브트리의 크기 계산
        subtree_size[curNode] += subtree_size[node]; // 서브트리의 크기 누적
    }
}

int main() {
    ios::sync_with_stdio(false); // 속도 향상
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q; // 노드 수, 루트 노드, 쿼리 수 입력

    parent.resize(n + 1); // 부모 노드 벡터 크기 할당
    subtree_size.resize(n + 1); // 서브트리 크기 벡터 크기 할당
    list.resize(n + 1); // 연결 정보 벡터 크기 할당
    tree.resize(n + 1); // 트리 구조 벡터 크기 할당

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v; // 노드 간 연결 정보 입력
        list[u].push_back(v);
        list[v].push_back(u);
    }

    makeTree(r, -1); // 트리 구성
    countSubtreeNodes(r); // 각 노드의 서브트리 크기 계산

    int query;
    
    while (q-- ) {
        cin >> query; // 쿼리 입력
        cout << subtree_size[query] << "\n"; // 결과 출력
    }

    return 0;
}
