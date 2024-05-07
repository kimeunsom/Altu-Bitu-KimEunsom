#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long binarySearch(const vector<unsigned long long>& t, unsigned long long m, unsigned long long left, unsigned long long right) {
    unsigned long long res = 0;
    unsigned long long mid = 0;
    unsigned long long q = 0;
    
    while (left <= right) {
        mid = (left + right) / 2;
        q=0;
        
        for (int t : t) {
            q += mid / t;
        }
        
        if (q >= m) {
            right = mid - 1;
            res = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return res;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    unsigned long long n,m,temp;
    
    
    vector <unsigned long long> t;
    
    //입력
    cin >> n >> m;
    while(n--) {
        cin >> temp;
        t.push_back(temp);
    }
    
    //이분탐색 전 정렬 필수 !
    sort(t.begin(), t.end());
    
    cout << binarySearch(t, m, 0, t[0] * m);
    
    return 0;
}
