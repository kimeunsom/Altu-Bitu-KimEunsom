#include <iostream>
#include <stack>
#include <vector>

using namespace std;

    
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> s;
    
    for (char c : infix) {
        if (isalnum(c)) { // 피연산자인 경우
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // '(' 제거
        } else { // 연산자인 경우
            while (!s.empty() && getPriority(s.top()) >= getPriority(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while (!s.empty()) { // 스택에 남아있는 모든 연산자를 pop하여 출력
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}


int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin >> str;
    
    string postfix = infixToPostfix(str);
    
    cout << postfix;
    

    return 0;
}