#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int ans = 0;
    int cnt = 0;
    int temp;
    
    while(true){
        
        // 초기화
        cnt = 0;
        temp = n;
        
        while(temp > 0){
            if(temp%2 > 0 ) {
                cnt++;
            }

            temp/=2; 2의 제곱승ㅇ
        }
        
        
        if(cnt <= k) break;
        
        n++;
        ans++;
    }
    
    cout << ans;
}