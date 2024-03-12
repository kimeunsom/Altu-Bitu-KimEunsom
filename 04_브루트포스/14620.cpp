#include <iostream>
#include <algorithm>


using namespace std;

int groundCost[10][10];


//꽃 심는 좌표가 주어지면, 그 꽃의 가격 구하는 함수.
int calCost(int x, int y ) {
    
    int cost=groundCost[x][y]
            +groundCost[x-1][y]
            +groundCost[x+1][y]
            +groundCost[x][y-1]
            +groundCost[x][y+1];
        

    return cost;
}



//꽃 심는 좌표 3개가 주어지면, 죽는지 여부 판별하는 함수.
bool death(int x[3], int y[3]) {
    
    //x,y 좌표의 차가 3이상이어야 안죽어. 최소 3칸은 떨어져서 심어야 함.

    for(int i=0; i<2; i++) {
        int subX = abs(x[i]-x[i+1]); 
        int subY = abs(y[i]-y[i+1]); 
        if(subX+subY<3) {
            return true; //꽃 죽었다.
        }
    }
    
    int subX = abs(x[0]-x[2]); 
    int subY = abs(y[0]-y[2]);
    if(subX+subY<3) {
        return true; //꽃 죽었다.
    }

    return false; //꽃 살았다.
}



//꽃 심기
int plant(int n) {

    int res=0;
    int lastRes=0;
    int count=0;
    //꽃 심는 위치
    int x[3]={0,0,0};
    int y[3]={0,0,0};
    
    
    //꽃 심을 3개의 좌표 설정 : 완전탐색
    //꽃은 가장 테두리엔 심지 않는다. 1 ~ n-2만 탐색
    for (int x1 = 1; x1 <= n-2; x1++) {
        for (int y1 = 1; y1 <= n-2; y1++) {
            for (int x2 = 1; x2 <= n-2; x2++) {
                for (int y2 = 1; y2 <= n-2; y2++) {
                    
                     if (x1 == x2 && y1 == y2) {
                         continue;
                    }
                    
                    for (int x3 = 1; x3 <= n-2; x3++) {
                        for (int y3 = 1; y3 <= n-2; y3++) {
                            // 중복되지 않는 좌표인지 확인
                            if ((x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)) {
                                 continue;
                            }
                            
                            x[0]=x1;
                            x[1]=x2;
                            x[2]=x3;
                            
                            y[0]=y1;
                            y[1]=y2;
                            y[2]=y3;
                            
                            
                            if(!death(x, y)) { //세 꽃이 죽지 않으면
                                    
                                res = 0; //현재 구할 변수는 초기화
                            
                                //꽃 3송이 심는 데 드는 땅가격 계산
                                for(int i=0; i<3; i++) {
                                    res+=calCost(x[i], y[i]);
                                }
                                

                                if(lastRes!=0) { //지난번 땅값 0이 아니라면, 즉 한번이라도 구해졌다면,
                                    res=min(lastRes,res);
                                }
                                                    
                                lastRes = res; //지난 최솟값 저장해두고,
                        
                            }
                                
                        }
                    }
                }
            }
        }
    }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int res;

    //입력
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> groundCost[i][j];
        }
    }
    
    //연산
    res = plant(n);
    
    
    //출력
    cout << res << "\n";
    
    return 0;
}