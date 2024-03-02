#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> NGE(const vector<int>& num) {
    
    stack<int> s;
    vector<int> ans(num.size(), -1); // 각 숫자의 오큰수를 저장할 벡터, 초기값은 -1로 설정
    
    for(int i=0; i<num.size(); i++) {
        
        while(!s.empty() && num[s.top()] < num[i]) {
                ans[s.top()]=num[i];
                s.pop();
        }
        
        s.push(i);
        
    }
    
    
    return ans;
    
    
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> num(n);
    
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    
    vector<int> ans = NGE(num);
    
    
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    

    return 0;
}