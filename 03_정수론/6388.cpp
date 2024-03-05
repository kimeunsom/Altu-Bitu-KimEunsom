#include <iostream>
#include <vector>

using namespace std;

//소수들을 남기고, 나머지는 지워나가는 벡터
    vector<bool> is_prime(1000001, true); 
    

int findPrime() {
    
    is_prime[0]=0;
    is_prime[1]=0;
    
    for(int i=2; i<=1000001; i++) {
        if(!is_prime[i]) { //이미 false이면 검토 X
            continue; //아래 무시하고 바로 다음 반복
        } 
        
        for(int j=i+i; j<=1000001; j+=i) {
            if(!is_prime[i]) { //이미 false이면 검토 X
                continue;
            }
            
            is_prime[j]=false;
        }
    }
    
    return 0;
}


int main()
{
    //시간초과 해결
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
   //소수 판별 (아리스토테네스의 체)
    findPrime();


    int n;
    cin >> n;

    
    while(n!=0) {
        
        int flag=0;
        
        int a=0;
        int b=0;
        
        
        //n 미만의 소수 b, 그리고 a=n-b. a가 소수면 그대로 a,b 확정 및 출력

        for(int i=n-1; i>=2; i--) {
            flag=0;
            
            if(is_prime[i]) { //소수면 true
                b=i;
                a=n-b;
                if(is_prime[a]) {
                    flag=1;
                }
            }
            
            if(flag==1) {
                cout << n << " = " << a << " + "<< b << '\n';
                break;
            }
        }
        
        if(flag==0) {
            cout << "Goldbach's conjecture is wrong." << "\n";
        }
        
        //다시 또 입력받고 반복
        cin >> n;

    }

    return 0;
}