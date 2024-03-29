#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // reverse 함수를 사용하기 위한 헤더

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string line;
    cin >> line;

    vector<int> alpha(26, 0);
    for (int i = 0; i < line.length(); i++) {
        int idx = line[i] - 'A';
        alpha[idx]++;
    }

    int isOne = 0;
    for (int i = 0; i < alpha.size(); i++) {
        if (alpha[i] % 2 != 0) isOne++;
    }

    string answer = "";
    string sb = "";
    if (isOne > 1) {
        answer += "I'm Sorry Hansoo";
    } else {
        for (int i = 0; i < alpha.size(); i++) {
            for (int r = 0; r < alpha[i] / 2; r++) {
                sb += (char)(i + 'A');
            }
        }
        answer += sb;
        string end = sb;
        reverse(end.begin(), end.end());

        sb = "";
        for (int i = 0; i < alpha.size(); i++) {
            if (alpha[i] % 2 == 1) {
                sb += (char)(i + 'A');
            }
        }
        answer += sb + end;
    }
    cout << answer << "\n";

    return 0;
}
