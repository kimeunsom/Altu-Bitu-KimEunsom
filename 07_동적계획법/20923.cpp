#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;  // 카드 덱을 나타내는 typedef. 0: 도도, 1: 수연

const int DO = 0, SU = 1;  // 상수 정의. 도도는 0, 수연은 1로 표시.

/** 승리 상태 출력 */
string judge(cards& deck) {
    int do_deck = deck[DO].size(), su_deck = deck[SU].size();
    if (do_deck > su_deck) {
        return "do";  // 도도가 승리한 경우
    }
    else if (do_deck < su_deck) {
        return "su";  // 수연이 승리한 경우
    }
    return "dosu";  // 무승부인 경우
}

/** 그라운드에서 덱으로 카드 옮기기 */
void groundToDeck(deque<int>& deck, deque<int>& ground) {
    while (!ground.empty()) {
        deck.push_back(ground.back());  // 그라운드에서 덱으로 카드를 옮김
        ground.pop_back();  // 옮긴 카드를 그라운드에서 제거
    }
}

/** 종을 쳤을 때 */
void ringTheBell(int player, cards& deck, cards& ground) {
    groundToDeck(deck[player], ground[!player]);  // 상대방 그라운드의 카드를 자신의 덱으로 이동
    groundToDeck(deck[player], ground[player]);  // 자신의 그라운드의 카드를 자신의 덱으로 이동
}

/** 종을 울릴 수 있는 사람 판단 */
int whoCanRingTheBell(cards& deck, cards& ground) {
    if (!ground[DO].empty() && ground[DO].front() == 5) {
        return DO;  // 도도가 종을 칠 수 있는 경우
    }
    else if (!ground[SU].empty() && ground[SU].front() == 5) {
        return SU;  // 수연이 종을 칠 수 있는 경우
    }
    else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) {
        return SU;  // 도도와 수연이 함께 종을 칠 수 있는 경우. 수연이 우선권을 가짐
    }
    return -1;  // 종을 칠 수 있는 사람이 없는 경우
}

/** 게임 진행 */
string game(int m, cards& deck, cards& ground) {
    bool turn = DO;  // 현재 턴 저장. 도도부터 시작
    while (m--) {
        ground[turn].push_front(deck[turn].front());  // 카드 내려놓기
        deck[turn].pop_front();  // 내려놓은 카드는 쥐고있던 묶음에서 제거
        if (deck[turn].empty()) {
            break;  // 카드 다 쓰면 루프 종료
        }

        int bell = whoCanRingTheBell(deck, ground);  // 종을 울릴 수 있는 사람 찾기
        if (bell != -1) {  // 종을 칠 수 있는 경우 !
            ringTheBell(bell, deck, ground);  // 종 치기 함수 수행
        }
        turn = !turn;  // 차례 바꾸기
    }
    return judge(deck);  // 승자 리턴
}

/** 메인 함수 */
int main() {
    int n, m, card1, card2;
    cards deck(2), ground(2);  // 카드 덱과 그라운드 초기화. 0: 도도, 1: 수연

    // 입력 받기
    cin >> n >> m;
    while (n--) {
        cin >> card1 >> card2;
        deck[DO].push_front(card1);  // 도도의 카드 입력
        deck[SU].push_front(card2);  // 수연의 카드 입력
    }

    
    cout << game(m, deck, ground); // 게임 진행 및 결과 출력
    
    return 0;
}
