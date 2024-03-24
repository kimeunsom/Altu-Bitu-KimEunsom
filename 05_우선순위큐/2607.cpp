#include <iostream>

using namespace std;

bool similarWord(string word, string str) {
        
        
    //두 단어의 알파벳 갯수 저장
    int alpW[26]={0};
    int alpS[26]={0};
    
    //두 단어의 알파벳 갯수 카운트
    for(int i=0; i<word.length(); i++) {
        //만약 word의 i번째 문자가 A면 alpW의 0번 인덱스가 +1
        alpW[(int)word[i]-65]++; //'A'=65 
    }
    
    for(int i=0; i<str.length(); i++) {
        //만약 str의 i번째 문자가 B면 alpS의 1번 인덱스가 +1
        alpS[(int)str[i]-65]++; //'A'=65 
    }
    
    
    
    
    int sameAlp=0;
    for(int i=0; i<26; i++) {
        if(alpS[i]==alpW[i]) {
            sameAlp++;
        }
    }
    
    //아예 구성 같은 경우
    if(sameAlp==26) {
        return true;
    }
        
        
    //하나 바꿔서 같아지는 경우
    else if(sameAlp==24) {
        int swap[2]; //서로 바꿀 두 변수
        int j=0;
        
        for(int i=0; i<26; i++) {
            if(alpS[i]!=alpW[i]) {
                swap[j++]=i;
                if(j==2) {
                    break;
                }
            }
        }
        
        if((alpW[swap[0]]-alpS[swap[0]]) ==1 && (alpW[swap[1]]-alpS[swap[1]]) ==-1) {
            return true; //스와핑 가능
        } else if((alpW[swap[0]]-alpS[swap[0]]) ==-1 && (alpW[swap[1]]-alpS[swap[1]]) ==1) {
            return true; //스와핑 가능
        }
    }
        
        
    //하나 더하거나 빼서 같아지는 경우
    else if(sameAlp==25) {
        
        int difAlp=0;
        
        for(int i=0; i<26; i++) {
            if(alpS[i]!=alpW[i]) {
                difAlp=i;
                break;
            }
        }
        
        if(abs(alpW[difAlp]-alpS[difAlp])==1) {
            return true; 
            //25개가 같은데 하나만 갯수가 1 차이나면 더하거나 빼면 돼.
        }
    }     
    
    
    
    
    return false; //위에서 안걸리면 비슷해질 수 없어
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    
    int n;
    string word; //기준 단어
    int cnt=0; //비슷한 단어 개수
    
    cin >> n >> word;
    
    while(n>1) {
        
        string str;
        cin >> str;
        
        if(similarWord(word, str)) {
            cnt++;
        }
        
        n--;
    }
    
    cout<<cnt;

    return 0;
}