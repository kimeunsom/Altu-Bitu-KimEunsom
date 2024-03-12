#include <iostream>
#include <vector>

using namespace std;

int BF(int n, string& k, string& d, vector<string>& moveD) {
    
    //주소값으로 전달해 함수에서 k,d의 값을 변형시킴
    
    string lastK, lastD; //움직이기 전 k,d의 위치
    
    for(int i=0; i<n; i++) {
        
        lastK=k;
        lastD=d;
        
        //킹의 이동
        if(!moveD[i].compare("T")) { //직진
            k[1]++;
        } else if (!moveD[i].compare("R")) {//오른쪽
            k[0]++;
        } else if (!moveD[i].compare("B")) {
            k[1]--;
        } else if (!moveD[i].compare("L")) {
            k[0]--;
        } else if (!moveD[i].compare("RT")) {
            k[0]++;
            k[1]++;
        } else if (!moveD[i].compare("RB")) {
            k[0]++;
            k[1]--;
        } else if (!moveD[i].compare("LB")) {
            k[0]--;
            k[1]--;
        } else if (!moveD[i].compare("LT")) {
            k[1]++;
            k[0]--;
        }
        
        
        //킹이 밖으로 나갔을 때
        if(k[0]<'A' || k[0]>'H' || k[1]<'1' || k[1]>'8') {
            k=lastK; //방금 한 이동은 취소하고, 다음 반복 진행!
            continue;
        }
        
        
        //킹이 돌이 있는 곳으로 움직일 때
        if(!k.compare(d)) {
            
            //k가 움직인 만큼 d도 움직여!
            d[0]+=(k[0]-lastK[0]);
            d[1]+=(k[1]-lastK[1]);
            
            //움직인 돌이 밖으로 나갔을 때
            if(d[0]<'A' || d[0]>'H' || d[1]<'1' || d[1]>'8') {
                
                d=lastD; //방금 한 이동은 취소하고, 다음 반복 진행!
                k=lastK;
                continue;
            }
        }
        
        
    }
    
    return 0;
}



int main()
{
    
    int n; //킹이 움직인 횟수
    string k, d; //킹과 돌의 위치
    vector <string> moveD (n, "?"); //킹의 이동 방향 저장
    string temp;
    
    
    //입력

    cin >> k >> d >> n;
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        moveD.push_back(temp);
    }
    
    //연산
    BF(n, k, d, moveD);
    
    
    //출력
    cout << k << '\n' << d;

    
    return 0;
}