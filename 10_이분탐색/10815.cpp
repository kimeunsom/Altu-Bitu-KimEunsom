#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(int key, const vector<int> &arr, int n) {
    int left = 0;
    int right = arr.size() - 1;
    int mid ;
    
    while(left <= right) {
        mid = (left+right)/2;
        
        if(arr[mid] == key) {
            return 1;
        } else if(arr[mid] < key) { //오른쪽으로
            left = mid + 1;
        } else { //왼쪽으로
            right = mid -1;
        }
    }
    
    return 0;
}

int main()
{

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n,m,t;
    vector <int> arr;
    cin >> n;
    
    while(n--) {
        cin >> t ;
        arr.push_back(t);
    }
    
    
    //이분탐색은 우선, 정렬 필수 !!
    sort(arr.begin(), arr.end());
    
    
    cin >> m ;
    
    while(m--) {
        
        cin >> t;
        cout << BinarySearch(t, arr, n) << ' ';
    }
    
    return 0;
}