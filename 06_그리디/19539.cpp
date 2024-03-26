#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, tree;
    int sum = 0;
    int use2 = 0;
    cin >> n;
    
    
    while(n--) {
        cin >> tree;
        sum += tree;
        use2 += tree / 2;
    }
    
    int grow = sum/3; // 자라는데 걸리는 최소 일자
    
    if (sum%3 != 0) { 
        // 총 자라는데 걸리는 일자가 3의 배수가 아니면 no
        cout << "NO";
    } 
    
    else if (use2 < grow) { 
        // 2짜리 물뿌리개를 사용할 수 있는 최대 횟수가, 최소 성장일자보다도 적으면 no
        cout << "NO";
        
    }
    
    else {
        cout << "YES";
    }
    
     
    

    return 0;
}