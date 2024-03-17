#include <iostream>

using namespace std;

const int NUM = 666;

int main()
{
    
    int n;
    
    //입력
    cin >> n;
    
    
    //연산
    int cnt=0; //종말의 수의 개수
    int i=666; //현재 점검하고 있는 수
    int temp=i;
    
    while(n!=cnt) {
        
        while(temp>0) {
            
            if(temp%1000==NUM) { //끝자리 666이면 카운트 +1
                cnt++; //종말의 수다!
                break;
            } else { //끝자리 666아니면 일의 자리 수 자르고 다시 점검
                temp/=10;
            }
        }
        
        i++;
        temp=i;
        
    }


    //출력
    cout << i-1;

    return 0;
}