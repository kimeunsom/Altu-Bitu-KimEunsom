#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n, const vector<int> &stairs) {
    vector<int> v(n, 0);
    
    // 각 계단마다 최대 점수를 계산하여 저장
    v[0] = stairs[0]; // 첫 번째 계단
    v[1] = max(stairs[0] + stairs[1], stairs[1]); // 두 번째 계단
    for (int i = 2; i < n; i++) {
        // 한 칸 뛰어올라서 온 경우 vs 두 칸 뛰어올라서 온 경우 중 더 큰 값을 선택
        v[i] = max(v[i - 2] + stairs[i], v[i - 3] + stairs[i - 1] + stairs[i]);
    }
    
    // 마지막 계단에서의 최대 점수 반환
    return v[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> stairs(n, 0); // 전체 계단 값
    
    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }
    
    cout << climbStairs(n, stairs);

    return 0;
}
