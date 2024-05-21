#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k; // 보드 크기와 사과 개수 입력

    vector<vector<int>> board(n, vector<int>(n, 0)); // 맵 초기화 (0: 빈 곳, 1: 사과, 2: 뱀)
    board[0][0] = 2; // 뱀의 시작 위치

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1; // 사과의 위치 표시
    }

    cin >> l; // 방향 변환 횟수 입력
    deque<pair<int, char>> directions; // 방향 변환 정보를 담을 deque

    for (int i = 0; i < l; ++i) {
        int x;
        char c;
        cin >> x >> c;
        directions.push_back({x, c}); // 시간과 방향 정보 저장
    }

    int game_time = 0; // 게임 진행 시간
    int head_x = 0, head_y = 0; // 뱀 머리의 좌표
    int dir = 0; // 초기 방향 (오른쪽)

    int dx[] = {0, 1, 0, -1}; // 우, 하, 좌, 상
    int dy[] = {1, 0, -1, 0};

    deque<pair<int, int>> snake; // 뱀 몸통 좌표를 담을 deque
    snake.push_front({0, 0}); // 뱀 머리 추가

    while (true) {
        game_time++; // 게임 시간 증가

        // 다음 칸으로 이동
        head_x += dx[dir];
        head_y += dy[dir];

        // 게임 종료 조건 확인
        if (head_x < 0 || head_y < 0 || head_x >= n || head_y >= n || board[head_x][head_y] == 2) {
            cout << game_time << endl; // 게임 종료 시간 출력
            break;
        }

        if (board[head_x][head_y] != 1) { // 사과를 먹지 않았으면
            int tail_x = snake.back().first;
            int tail_y = snake.back().second;
            board[tail_x][tail_y] = 0; // 꼬리 위치 업데이트
            snake.pop_back(); // 꼬리 줄임
        }

        board[head_x][head_y] = 2; // 머리 위치 업데이트
        snake.push_front({head_x, head_y}); // 머리 추가

        // 방향 전환
        if (!directions.empty() && directions.front().first == game_time) {
            if (directions.front().second == 'L') {
                dir = (dir + 3) % 4; // 왼쪽으로 방향 전환
            } else {
                dir = (dir + 1) % 4; // 오른쪽으로 방향 전환
            }
            directions.pop_front(); // 방향 전환 정보 삭제
        }
    }

    return 0;
}
