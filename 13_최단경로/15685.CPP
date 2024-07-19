 #include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100; //맵은 최대 100,100
bool visited [MAX_SIZE+1][MAX_SIZE+1]={false,};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

//드래곤 커브 그려서, 맵에 지나간 꼭짓점 표시
void drowCurve(int x, int y, int d, int g) {
    
    int cur_size=0; //현재의 벡터 사이즈
    int cx=x; //커브의 가장 마지막 점
    int cy=y;
    vector<int> curve;
    visited[y][x]=true;
    curve.push_back(d);
    int tag = 0;
    
    if(g==0) {
        
        cx+=dx[curve[cur_size]];
        cy+=dy[curve[cur_size]]; //위치 이동!
            
        visited[cy][cx]=true;
        
        return;
    }
    
    while(g--) {
        
        cur_size = curve.size()-1;
        
        // 해당 세대에 추가된 드래곤 커브의 방향 추가
        for(int i=cur_size; i>=0; i--) {
            curve.push_back((curve[i]+1)%4); //드래곤 커브 방향 벡터에 넣기
        }
        
        
        if(tag==0) {
            cx+=dx[curve[cur_size]];
            cy+=dy[curve[cur_size]]; //위치 이동!
            
            visited[cy][cx]=true;
            tag = 1;
        }
        
        
        // 방문한 꼭짓점 표시
        for(int i=cur_size+1; i<curve.size(); i++) {
            
            cx+=dx[curve[i]];
            cy+=dy[curve[i]]; //위치 이동!
            
            visited[cy][cx]=true;
        }
    }
}

int main()
{
    int n, x, y, d, g;
    int cnt=0; //꼭짓점 모두를 커브가 지나간 1x1 정사각형 개수
    
    cin >> n;


    
    while(n--) {
        cin >> x >> y >> d >> g;
        drowCurve(x,y,d,g);
    }
    
    for(int i=0; i<MAX_SIZE; i++) {
        for(int j=0; j<MAX_SIZE; j++) {
            if(visited[i][j] && visited[i+1][j] && visited[i][j+1] && visited[i+1][j+1]) {
                cnt++;
            }
        }
    }
    
    cout << cnt;

    return 0;
}