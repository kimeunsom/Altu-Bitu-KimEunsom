#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLength(const vector<int> &sequence, int * cnt, int k) {
    
    int lp=0; //시작 포인터
    int rp=0; //끝 포인터
    
    int left = 0;
    int right = 0;
    
    int cur_length=0;
    int max_length=0;
    int tag=0;
    
    while(rp<sequence.size()) { //끝 배열이 전체 수열 끝에 도달할 때까지 
        
        if(tag==0) {
            right = sequence[rp]; //현재 ep가 가리키는 수
            cnt[right]++; //카운팅 +1
        }
        
        
        if(cnt[right]<=k) { //아직 중복 개수가 2보다 작은 동안,
            tag = 0;
            rp++;
            
        } else { //중복이 k 초과한 순간,
            tag = 1;
            
            left = sequence[lp]; //현재 sp가 가리키는 수
            cnt[left]--; //카운트 -1
            lp++;
            continue;
        }
        
        cur_length = rp-lp; //rp는 위에서 추가되었으므로 계산 시 +1 할 필요 x
        max_length = max(max_length, cur_length);
        
    }
    
    return max_length;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k, t;
    cin >> n >> k;
    
    vector <int> sequence; //전체 수열 입력받을 벡터
    int cnt[200001]; //부분 수열 내 숫자들 갯수 카운팅할 배열
    
    while(n--) {
        cin >> t;
        sequence.push_back(t);
    }
    
    cout<<findLength(sequence, cnt, k);;

    return 0;
}

