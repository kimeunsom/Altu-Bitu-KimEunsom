#include <iostream>
#include <vector>

using namespace std;

int solution(int n, const vector<int>& a) {
    int ans = 0;
    vector<int> dp(n, 1);
    
    
    for(int i=0; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(a[i]>a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] > ans) ans = dp[i];

    }
    
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> a(n,0);
    
    for(int i=0; i<n; i++) {
        cin >> a[i]; 
    }
    
    cout << solution(n, a);

    return 0;
}