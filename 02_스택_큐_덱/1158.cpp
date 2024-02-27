#include <iostream>
#include <queue>

using namespace std;

void makeYo (vector<int>& ans, int k, int n) {
    
    queue<int> q;
    
    for(int i=1; i<=k; i++) {
        q.push(i);
    }
    
    int cnt = 1;
    
    while(ans.size() != k) {
        
        if(cnt!=n) {
            q.push(q.front());
            q.pop();
            cnt++;
        } else {
            ans.push_back(q.front());
            q.pop();
            cnt=1; // 카운트 초기화;
        } 
    }
}

int main()
{

    int k, n;
    
    cin >> k >> n;
    
    vector<int> ans;
    
    makeYo(ans, k, n);
    
    cout << "<";
    for(int i=0; i<k-1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[k-1] << ">";
    
    

    return 0;
}