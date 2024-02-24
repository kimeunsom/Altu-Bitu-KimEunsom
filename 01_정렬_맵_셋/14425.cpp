#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<string> strings;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strings.insert(s);
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (strings.find(s) != strings.end()) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
