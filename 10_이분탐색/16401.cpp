#include <iostream>
#include <vector>
#include <algorithm> //max 함수 헤더파일


using namespace std;

//이분 탐색. 반복문으로 구현.
int binarySearch(int max_snack, const vector<int> &snack_length, int m) {
    int cnt = 0; //나눠줄 수 있는 총 과자의 수
    int res = 0;
    
    int left = 1;
    int right = max_snack;
    int mid=0;
    
    while(left <= right) {
        cnt = 0;
        mid = (left+right) / 2;
        
        for(int i=0; i<snack_length.size(); i++) {
            cnt += snack_length[i]/mid;
        }
        
        //나눠줄 수 있는 과자가 조카 수보다 많으면, 현재 길이로 잘라 나눠줄 수 있음 !
        if(cnt >= m) { 
            left = mid+1; //오른쪽 이동 (더 큰 과자 사이즈로)
            res = mid ;
        
            
        } 
        
        //나눠줄 수 있는 과자가 조카 수보다 작으면, 현재 길이로는 잘라줄 수 없음.
        else {
            right = mid-1; //왼쪽 이동 (더 작은 과자 사이즈로 자르기)
        } 
        
    } 
    
    return res;
}

int main()
{
    int m, n, t;
    vector <int> snack_length; //과자 길이들 저장할 벡터
    
    cin >> m >> n;
    
    int max_snack = 1; //과자의 최대 길이 저장할 변수
    
    //과자 길이 입력받기
    while(n--) {
        cin >> t ;
        snack_length.push_back(t);
        max_snack = max(t, max_snack);
    }
    
    cout << binarySearch(max_snack, snack_length, m);

    return 0;
}