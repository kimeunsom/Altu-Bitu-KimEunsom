#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

//비교함수
bool cmp (const p &a, const p &b) {
    return a.first < b.first; // pair의 first값 오름차순 정렬
}

int checkScore(int n, vector <p> scores) {
    int ans = 1;
    
    // 서류심사 값 순위에 따라 오름차순 정렬
    sort(scores.begin(), scores.end(), cmp);
    
    int maxScore = scores[0].second;
    for(int i=0; i<n; i++) {
        if(scores[i].second < maxScore) { // 기존 면접심사 최고 순위보다 더 높은 순위
            ans++;
            maxScore = scores[i].second; // 최고 순위값 갱신
        }
    }
    
    return ans;
}

int main()
{
    int t, n;
    
    cin >> t;
    
    while(t--) {
        cin >> n;
        vector <p> scores(n); // 두 점수 순위를 페어로 담을 벡터
        // 벡터 크기를 지정해야 인덱스로 요소에 접근 가능함 !
        
        for(int i=0; i<n; i++) {
            cin >> scores[i].first >> scores[i].second;
        }
        
        cout << checkScore(n, scores) << '\n';
    }
    

    return 0;
}