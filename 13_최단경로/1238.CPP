#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
typedef pair<int, int> ci;
const int INF = numeric_limits<int>::max(); // 무한대

// 다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int> dist(v + 1, INF); // 각 정점까지의 최단 거리
    priority_queue<ci, vector<ci>, greater<ci>> pq;
    
    int weight, node, next_node, next_weight;

    dist[start] = 0;
    pq.push({0, start}); // 시작. 우선순위 큐
    while (!pq.empty()) {
        weight = pq.top().first; // 현재까지의 경로값
        node = pq.top().second; // 탐색
        pq.pop(); // 탐색한 정점 제거

        if (weight > dist[node]) continue; // 최단거리 아니면, 건너뛰기 !

        for (int i = 0; i < graph[node].size(); i++) {
            next_node = graph[node][i].first; // 연결된 정점
            next_weight = weight + graph[node][i].second; // 경로값

            // 최단거리 갱신하고 큐에 삽입
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist; // 벡터를 반환함.
}

int main() {
    int n, m, x;
    cin >> n >> m >> x; // 정점의 개수, 간선의 개수, 파티 장소

    vector<vector<ci>> graph(n + 1, vector<ci>()); // 인접 리스트
    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t}); // 간선 정보
    }

    vector<int> from = dijkstra(x, n, graph); // 파티 장소부터 ~
    vector<vector<ci>> reverse(n + 1, vector<ci>());

    // 간선 방향 뒤집기
    for (int i = 1; i <= n; ++i) {
        for (auto edge : graph[i]) {
            reverse[edge.first].push_back({i, edge.second});
        }
    }
    vector<int> to = dijkstra(x, n, reverse); // ~ 파티 장소까지

    int max_time =0;
    int total = 0;
    
    for (int i = 1; i <= n; ++i) {
        total = from[i] + to[i]; // 파티까지 가는데 걸리는 토탈 시간
        max_time = max(max_time, total);
    }

    cout << max_time << '\n';

    return 0;
}
