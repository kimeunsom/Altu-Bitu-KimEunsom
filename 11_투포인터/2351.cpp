#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(const vector<int> &dish, int *visited, int k, int c, int n) {
    
    //최대, 현재의 최대한 다양하게 먹은 생선의 가짓수 저장할 변수
    int max_cnt=0;
    int cur_cnt=0;
    
    int lp=0;
    int rp=0;
    int left=0;
    int right=0;
    
    int coupon = 0; // 쿠폰 적용 여부 표시
    
    while ( rp-lp < k ) { //k개 이하로 먹었을 때, 초반 세팅.
            
        right = dish[rp];
        visited[right]++;
            
        if(visited[right] == 1) { //새로운 초밥이 추가되었다면, 가짓수 +1
           cur_cnt++;
        }
           
            
        if(rp-lp == k-1 ) { // k개의 초밥이 충족됐으면, 현재의 cnt 값을 max에 저장
            max_cnt = cur_cnt;
            break;
        }
            
        rp++;
            
    } 
    
    
    do { //딱 k개만큼 연속해서 다 먹었을 때, 
        
           // 포인터 조정 전, 지난 lp값 제외
            left = dish[lp%n]; 
            visited[left]--;
            if(visited[left] == 0) { //딱 하나뿐인 초밥이 빠졌다면, 가짓수 -1
                cur_cnt--;
            } 
            
            // 포인터 조정, lp부터 rp까지 새로운 k개의 초밥
            lp++;
            rp++;
            lp%=n;
            rp%=n;
            
            // 회전 초밥이니깐, 원형큐의 개념 떠올리며 mod 연산해주기
            
            
            //rp 조정
            right = dish[rp%n];
            visited[right]++;
            if(visited[right] == 1) { //새로운 초밥이 추가되었다면, 가짓수 +1
                cur_cnt++;
            } 
            
            //쿠폰 초밥 구간 내 미포함이면, 쿠폰 한 종류 더 추가 !
            if(visited[c]==0) {
                cur_cnt++;
                coupon=1;
            }
            
            
            
            
            max_cnt = max(cur_cnt, max_cnt);
            
            
            if(coupon==1) { //쿠폰 적용 되어있으면, 초기화 !
                coupon=0;
                cur_cnt--;
            }    
            
    } while( lp !=0 );
    
    return max_cnt;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, d, k, c, t;
    cin >> n >> d >> k >> c ; //접시 개수, 초밥 가짓수, 이벤트 연속 횟수, 쿠폰 초밥
    vector <int> dish; //n개의 접시에 담긴 초밥들 저장
    int visited[d+1] = {0}; //초밥 중복 여부 체크 위한 배열
    
    int x = n;
    while(x--) {
        cin >> t;
        dish.push_back(t);
    }
    
    cout << solution(dish, visited, k, c, n);

    return 0;
}