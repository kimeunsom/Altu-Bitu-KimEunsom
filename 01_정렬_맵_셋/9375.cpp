#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<string, int> clothes;

        for (int i = 0; i < n; ++i) {
            string name, type;
            cin >> name >> type;
            clothes[type]++;
        }

        int answer = 1;
        for (const auto& pair : clothes) {
            answer *= (pair.second + 1); // 각 종류별로 옷을 선택하지 않는 경우를 포함하기 위해 +1
        }

        // 알몸은 제외해야 하므로 -1
        cout << answer - 1 << "\n";
    }

    return 0;
}
