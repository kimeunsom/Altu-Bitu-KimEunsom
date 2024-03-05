#include <iostream>
#include <vector>

using namespace std;

// 시계 방향으로 바퀴가 돌면, 바퀴를 고정된 배열로 뒀을 때, 화살표는 반시계로 도는 것이다.
// 양의 방향을 반시계방향이라 가정하고, 모듈러 연산을 통해 바퀴를 채워나갈 것이다.
    
// 바퀴에 같은 글자는 두 번 이상 등장하지 않는다 !!!!!!!!

int setWheel(int n, vector<char> &wheel, const vector<pair<int, char>> &info) {
    
    wheel[0] = info[0].second; // 첫 알파벳 배열에 고정 ! 얘 기준으로 이제 돌기.알
    int arrow = 0;
    
    vector<int> use_alphabet (26, -1); // 이미 쓰인 알파벳의 인덱스 표기 !
    
    // 0번은 이미 위에서 처리함. 1번 정보부터 확인하며 배열 채우기
    for(int i=1; i<info.size(); i++) {
        
        arrow = (arrow + info[i].first) % n ; // 모듈러 연산
        
        //이미 다른값이 채워져있다면,
        if(wheel[arrow]!='?' && wheel[arrow]!=info[i].second ) { 
            return -1;    
        }
        
        // 같은 알파벳이 중복되어 또 사용된다면,
        if( use_alphabet[info[i].second-'A'] != -1 && use_alphabet[info[i].second-'A'] != arrow) {
            return -1;
        }
        
        wheel[arrow] = info[i].second;
        
        // 현재 화살표가 가리키는 인덱스. 즉 알파벳이 적힌 위치를 저장해줌 !
        use_alphabet[info[i].second-'A']=arrow; 
         
    }
    
    return arrow; // 화살표 인덱스 리턴
    
    
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k, s;
    char c;
    
    cin >> n >> k ;
    vector<char> wheel (n, '?'); // 바퀴 벡터
    vector<pair<int, char>> info; // 입력 정보 저장할 pair 벡터
    
    while(k--) {
        cin >> s >> c ;
        info.push_back(make_pair(s,c));
    }
    
    char ans = setWheel (n, wheel, info);
    
    if( ans == -1 ) {
        cout << "!";
    } else {
        
        // 화살표가 가리키는 곳부터 시계방향(음의 방향) 출력
        for(int i=0; i<wheel.size(); i++) {
            
            cout << wheel[ans%n];
            
            if((--ans)<0) {
                ans += n; // 음의 방향으로 인덱스 이동하다가, 음수가 되면, 바퀴 칸 수만큼 더하기 !
            }
        }
        
        
    }

    return 0;
}