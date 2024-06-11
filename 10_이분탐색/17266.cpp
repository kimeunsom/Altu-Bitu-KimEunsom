#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> x(m+2); // 등불의 위치를 저장할 벡터 (굴다리의 양 끝을 포함)
    
    x[0] = 0; // 굴다리의 시작
    
    for(int i=1; i<=m; i++) {
        cin >> x[i];
    }
    
    x[m+1] = n; // 굴다리의 끝
    
    int max_d = 0;
    for(int i=1; i<x.size(); i++) {
        int dist = ceil((x[i] - x[i-1]) / 2.0); // 천장함수
        if(max_d < dist) {
            max_d = dist;
        }
    }
    
    // 굴다리의 시작과 첫 등불 사이, 마지막 등불과 굴다리 끝 사이의 거리를 고려
    max_d = max(max_d, x[1] - x[0]);
    max_d = max(max_d, x[m+1] - x[m]);
    
    cout << max_d;
    
    return 0;
}
