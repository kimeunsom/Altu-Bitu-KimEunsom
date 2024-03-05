#include <iostream>

using namespace std;

int getGcdRecur(int a, int b)  {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a%b);
}

int main()
{

    int u1, u2, d1, d2; //입력받을 분자와 분모
    int uRes, dRes; //최종 분자와 분모
    
    
    //입력
    cin >> u1 >> d1 >> u2 >> d2;
    
    //Part.1
    uRes = u1*d2 + u2*d1;
    dRes = d1 * d2;
    
    //일단 더한 후(Part.1), 이 값을 기약분수로 정리(Part.2)
    
    
    //Part.2 : 분자와 분모를 두 수의 최대공약수로 나눈다!
    int gcd = getGcdRecur(uRes,dRes);
    
    uRes/=gcd;
    dRes/=gcd;
    
    cout << uRes << " " << dRes ;
    
    
    return 0;
}