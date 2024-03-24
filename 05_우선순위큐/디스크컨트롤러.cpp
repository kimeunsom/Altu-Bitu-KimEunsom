#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> p;

struct cmp {
    bool operator()(const p& a, const p& b) {
        return a.second > b.second; // 처리 시간을 기준으로 우선순위 큐 정렬
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int time = 0;
    int end = 0 ; // 처리 완료한 작업의 수
    int done = 0; // 힙에 들어간 작업의 수
    
    // 최소 힙 선언
    priority_queue<p, vector<p>, cmp> works;
    
    // 작업 요청 시간순으로 정렬
    sort(jobs.begin(), jobs.end());
    
    while(end < jobs.size()) {
        
        // 요청받은 시간이 됐다면, 최소힙에 넣기.
        
        while(done < jobs.size() && time >= jobs[done][0] ) {
            works.push({jobs[done][0], jobs[done][1]}); 
            // 소요시간 처리시간 둘 다 넣음
            done++;
        }
        
        
        if(works.empty()) {
            // 요청받은 일이 없다면,
            time = jobs[done][0]; // 첫 작업을 시작할 수 있는 시간으로 이동 !!
            continue;
        } else {
            
            end ++ ;
            
            // 현재까지 기다린 시간과 처리시간 더해주기
            
            answer += time - works.top().first; //기다린 시간
            answer += works.top().second; // 처리시간
            
            // 처리 시간만큼 시간 늘림 !
            time += works.top().second;
            works.pop();
        }
        
    }
    
    answer /= jobs.size();
    
    return answer;
}