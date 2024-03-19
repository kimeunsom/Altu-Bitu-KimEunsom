#include <iostream>
#include <queue>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n, a, gift;
    priority_queue<int> pq;

    
    cin >> n;
    
    while(n--) {
        cin >> a;
        
        if(!a) {
            
            if (pq.empty()) { //줄 선물 없으면 -1 출력
				cout << "-1\n";
			} else{ //우선순위 큐에 가치 큰 선물순으로 정렬되어 있으니, top, pop!
			    cout << pq.top() << "\n";
				pq.pop();
			}
        } 
        
        else {
            for(int i=0; i<a; i++) {
                cin >> gift;
                pq.push(gift);
            }
        }
        
    }

    return 0;
}