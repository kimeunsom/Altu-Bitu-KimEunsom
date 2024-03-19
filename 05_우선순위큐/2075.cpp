#include <iostream>
#include <queue>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n, temp;
    
    // 최소힙 선언
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    cin >> n; 
    
    for(int i=0; i<n*n; i++) {
        cin >> temp;
        minHeap.push(temp);
        
        if(minHeap.size()>n) {
            minHeap.pop();
        }
    }
    
    cout << minHeap.top();
    
    

    return 0;
}