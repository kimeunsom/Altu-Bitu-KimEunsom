#include <iostream>
#include <vector>
#include <algorithm> //min 함수 헤더파일


using namespace std;

//블루레이 크기의 범위로이분 탐색. 반복문으로 구현.
int binarySearch(int left, int right, const vector<int> &lessons, int m) {
    int cnt = 0; //현재 사용한 블루레이 개수
    int res = 0;
    int sum = 0; //블루레이 하나에 들어간 강의들 총 길이합
    int mid=0;
    
    while(left <= right) {
        cnt = 0;
        sum=0;
        mid = (left+right) /2; //현재 블루레이의 크기
        
        
        
        //cnt 계산
        for(int i=0; i<lessons.size(); i++) {
            sum += lessons[i];

            if(sum>mid) { //블루레이 하나가 현재 지정한 크기(mid)를 초과했으면,
                cnt++;
                sum=lessons[i]; //현재 강의부터 다음 블루레이에 담기
            } else if(sum==mid)  { //블루레이 하나가 딱 맞게 찼으면,
                cnt++;
                sum=0; //다시 빈 블루레이에 채우기 시작 !
            }
            
        }
        
        if(sum>0) {
            cnt++; //마지막 블루레이 포함! 
        }
        
        
        
        if(cnt <= m) { //사용 가능한 블루레이수보다 적게 사용함
            //각 블루레이에 강의를 덜 담아야함. 현재 블루레이 크기보다 줄여야해 !
            right = mid-1;
            res = mid;
        } 
        
        /*else if(cnt == m) {
            right = mid-1; //더 최소의 블루레이 있나 탐색해보기.
            res = mid;
        } */
        
        else { //사용 가능한 블루레이수보다 많이 사용함
            //각 블루레이에 강의를 더 담아야함. 현재 블루레이 크기보다 늘여야해 !
            left = mid+1;
        }
        
        
    }
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, n, t;
    vector <int> lessons; //강의 길이 벡터
    
    cin >> n >> m;
    
    int all_lessons = 0; //모든 레슨의 길이 총 합
    int max_lessons = 0; //가장 짧은 레슨 길이
    
    //강의 길이 입력받기
    while(n--) {
        cin >> t ;
        lessons.push_back(t);
        all_lessons += t;
        max_lessons = max(max_lessons, t);
    }
    
    cout << binarySearch(max_lessons, all_lessons, lessons, m);

    return 0;
}