#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n, temp;
    
    // 최대, 최소힙 선언
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    
    cin >> n; 
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        
        // 중앙값은 작은 것들 중 가장 크고, 큰 값들 중 가장 작은 것.
        // 비교적 작은 수는 최대 힙에, 비교적 큰 수는 최소힙에 담으면,
        // 각 힙의 top이 중앙값이 된다 !
        
        if(i==0) { // 이러지 않으면, 에러... 근데 왜지
            maxHeap.push(temp);
            cout << maxHeap.top() << "\n";
            continue;
        }
        
        
        // 입력값들 중 현재 중앙값보다 작다면 최대힙에 !
        if( temp < maxHeap.top()) {
            maxHeap.push(temp);
        } else {
            minHeap.push(temp);
        }
        
        
        // 두 힙은 중간값을 찾기 위해, 항상 크기가 2 이상 차이나면 안됨.
        // 항상 크기가 같거나, 최대힙이 한 개 커야함.
        
        
        if( maxHeap.size() > minHeap.size() +1 ) { // 최대힙이 너무 커진경우
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if ( minHeap.size() > maxHeap.size() ) { // 최소힙이 최대힙보다 큰 경우
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        
        // 중앙값 출력

        // 짝수인 경우, 두 탑 비교
        if(i%2 == 0) {
            cout << min(maxHeap.top(), minHeap.top()) << "\n";
        } 
        
        // 홀수인 경우, 크기가 하나 더 크게 설정해둔 최대힙의 탑 출력
        else {
            cout << maxHeap.top() << "\n";
        }
    }
    
    
    

    return 0;
}