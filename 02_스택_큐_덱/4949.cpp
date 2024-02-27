#include <iostream>
#include <stack>
#include <string> //getline() 함수

using namespace std;

bool isValid(string input) {
    stack<char> s;
    
    for (char c : input) {
        if (c=='(' || c=='[') { // 열린 괄호
            s.push(c);
        } else if (c==')' || c==']') {
            if(s.empty()) return false; // 비어있으면 false
            
            char t = s.top();
            s.pop();
            
            // 짝 안맞으면 false
            if(c == ')' && t !='(') return false;
            if(c == ']' && t !='[') return false;
        }
    }
    
    // 스택 안비어있으면 false
    //if(!s.empty()) return false;
    
    return s.empty();
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    
    while(true) {
        
        getline(cin, input);
        
        if(input==".") break;
        
        if(isValid(input)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    
    return 0;
}