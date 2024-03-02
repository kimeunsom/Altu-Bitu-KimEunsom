#include <iostream>
#include <string>
#include <array>

using namespace std;

string SumAB (string a, string b) {

    
    string result="";
    
    int lenA = a.length();
    int lenB = b.length();

    // 01. 무조건 A 자릿수 크게 만들기
    if (lenB > lenA) {
        swap(a, b);
        swap(lenA, lenB);
    }
    
    //0 넣어서 자릿수 채워주기
    string temp = "";
    if( lenA != lenB ) {
        for(int i=0; i< (lenA - lenB); i++) {
            temp+="0";
        }
    }
    b=temp+b;
    
    int sum[lenA]={0};
    bool carry = false;
    
    
    for(int i=lenA-1; i>0; i--) {
        sum[i] += a[i]+b[i]-'0'-'0';
        
        if(sum[i]>=10) {
            carry=true;
            sum[i]%=10;
            sum[i-1]++;
        }
    }
    
    sum[0] += a[0]+b[0]-'0'-'0';

    
    for(int i=0; i<lenA; i++) {
        result += to_string(sum[i]);   
    }

    return result;
    
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a,b;
    
    cin >> a >> b;
    
    cout << SumAB(a, b);
    
    return 0;
}