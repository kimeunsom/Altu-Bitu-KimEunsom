#include <iostream>
#include <vector> 

using namespace std;

typedef pair<int,int> p;

void setTop(vector<p>& haveto_turn, vector<int>& top) {
    
    for (int i=0; i<haveto_turn.size(); i++) {
        
        if(haveto_turn[i].second == 1) 
        { // 시계방향 회전이면,
            top[haveto_turn[i].first]--;
        } 
        
        else 
        { // 반시계방향 회전이라면,
            top[haveto_turn[i].first]++;
        }
        
        top[haveto_turn[i].first] = (top[haveto_turn[i].first]+8)%8; //모듈러 연산
    }
    
}


void turnWheels(int t, vector<vector<int>>& wheel, vector<int>& top, int num, int clockwise) {
    
    vector<bool> is_same(t, true); // 바퀴들이 만난 극이 같은지 다른지 담을 벡터
    
    
    // 두 바퀴 맞닿는 면이 같은지 다른지 체크
    for(int i=1; i<t; i++) {
        if (wheel[i][(top[i]+2)%8] != wheel[i+1][(top[i+1]-2+8)%8])  {
            // 두 바퀴가 맞닿는 부분이 다르면 false로 !
            is_same[i] = false;
        }
    }
    
    // 돌려야 하는 바퀴들 담을 배열
    vector<p> haveto_turn;
    
    // 돌리라고 입력받은 바퀴 배열에 추가.
    haveto_turn.push_back(make_pair(num, clockwise));
    
    
    // 맞닿은 두 바퀴 극 다르면, 얘네도 회전 !
    
    int temp = clockwise;
    // 왼쪽 바퀴와 맞닿은 극 체크
    for(int i=num-1; i>0; i--) {
        if(is_same[i]) {
           break; 
        } else {
            if(clockwise==1) {
                haveto_turn.push_back(make_pair(i, -1));
                clockwise=-1;
            } else {
                haveto_turn.push_back(make_pair(i, 1));
                clockwise=1;
            }
        }
    }
    
    clockwise = temp; // 회전방향 다시 처음 입력대로 세팅
    
    // 오른쪽 바퀴와 맞닿은 극 체크
    for(int i=num; i<is_same.size(); i++) {
        if(is_same[i]) {
           break; 
        } else {
            if(clockwise==1) {
                haveto_turn.push_back(make_pair(i+1, -1));
                clockwise=-1;
            } else {
                haveto_turn.push_back(make_pair(i+1, 1));
                clockwise=1;
            }
        }
    }
    
    // 바퀴 돌리기. 12시방향 인덱스(top) 조정 !
    setTop(haveto_turn, top);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, k, num, clockwise;
    int cnt=0;
    string cmd;
    cin >> t;
    
    vector <vector<int>> wheel(t+1, vector<int>(8)); //t+1행 8열의 벡터 생성
    vector <int> top(t+1, 0); //12시 방향의 인덱스를 담을 벡터. 0으로 모두 초기화.
    
    for (int i = 1; i <= t; i++) {
        cin >> cmd ; 
        for (int j = 0; j < 8; j++) {
            wheel[i][j] = cmd[j]-'0'; //char를 int로 변환하여 할당.
        }
    }
    
    cin >> k;
    
    while(k--) {
        
        cin >> num >> clockwise ; 
        turnWheels(t, wheel, top, num, clockwise);    
    
    }
    
    
    for(int i=1; i<=t; i++) {
        if(wheel[i][top[i]] == 1) { //12시 방향이 s극이면 cnt++
            cnt ++ ; 
        }
    }
    
    cout << cnt; 
     
    return 0;
}