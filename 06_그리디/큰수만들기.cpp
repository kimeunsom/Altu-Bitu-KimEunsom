#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = 0;
    
    // 최종 길이
    int l = number.length() - k;
    
    // 스택으로 큰 수를 유지 !!
    vector<char> s;

    for (char num : number) {
        // 스택이 비어있지 않고, 스택의 top이 현재 숫자보다 작은 경우
        // 스택의 top을 제거하고 현재 숫자를 추가
        // 최종적으로 높은 자리 수에 가장 큰 수를 배치하는 방향으로 
        while (!s.empty() && s.back() < num && cnt < k) {
            s.pop_back();
            cnt++;
        }
        
        // 현재 숫자 넣기
        s.push_back(num);
    }

    // 스택의 크기 l로
    s.resize(l);

    
    for (char num : s) {
        answer += num;
    }

    return answer;
}
