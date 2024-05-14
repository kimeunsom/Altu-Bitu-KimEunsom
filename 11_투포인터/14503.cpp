#include <iostream>

using namespace std;

int n, m, r, c, d;
int room[51][51];

bool dirtyPlaceExsist() {
    
    int sum = 0; //청소된 방 카운트
    
    if(room[r-1][c]!=0) { //청소되었으면, sum +1
        sum ++;
    }
    
    if(room[r][c-1]!=0) {
        sum ++;
    }
    
    if(room[r+1][c]!=0) {
        sum ++;
    }
    
    if(room[r][c+1]!=0) {
        sum ++;
    }
    
    if(sum == 4) {
        return false; // 주변이 모두 청소됨. 청소 안된 곳이 없어.
    } else {
        return true;
    }
}




int cleanRobot() {
    
    int cnt=0;
    int tag = 0;

    
    while(true) {
        
        
        // #1. 현재 칸이 청소되지 않은 경우, 청소하기
        if(room[r][c]==0) {
            cnt++;
            room[r][c]=2; //청소된 상태
        }
        
        
        // #2. 주변 4칸 청소 안된 곳 있으면, 
        if(dirtyPlaceExsist()) 
        {
            tag = 0; // 전진 여부 표기할 태그값 초기화
            while(tag != 1) {
                
                // 1) 90도 회전
                d--;
                if(d<0) d+=4;

                
                
                // 2) 바라보는 방향의 앞쪽 칸이 청소안돼있으면 전진 !
                switch(d) {
                    case 0 : //북
                        if(room[r-1][c]==0) {
                            r--;
                            tag = 1;
                        }
                        break;
                    case 1 : //동
                        if(room[r][c+1]==0) {
                            c++;
                            tag = 1;
                        }
                        break;
                    case 2 : //남
                        if(room[r+1][c]==0) {
                            r++;
                            tag = 1;
                        }
                        break;
                    case 3 : //서
                        if(room[r][c-1]==0) {
                            c--;
                            tag = 1;
                        }
                        break;
                    
                }
            }
            
            
        }
        
    
    
        // #2. 주변 4칸 청소 안된 곳 없으면, 

        else 
        {
            
            // 후진 가능하면 후진. 벽이면 멈춤.
            switch(d) {
                case 0 : //북
                   if(room[r+1][c]==1) {
                        return cnt;
                    } else { //벽 아니면
                        r++;
                        break;
                    }
                case 1 : //동
                    if(room[r][c-1]==1) {
                        return cnt;
                    } else { //벽 아니면
                        c--;
                        break;
                    }
                case 2 : //남
                    if(room[r-1][c]==1) {
                        return cnt;
                   } else { //벽 아니면
                        r--;
                        break;
                    }
                case 3 : //서
                    if(room[r][c+1]==1) {
                        return cnt;
                    } else { //벽 아니면
                        c++;
                        break;
                    }
            }
            
            
        }
        
    }
    
    
    
    
    return cnt;
    
}

int main()
{
    
    cin >> n >> m >> r >> c >> d;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> room[i][j];
        }
    }

    cout << cleanRobot();

    return 0;
}