#include<bits/stdc++.h>
using namespace std;

struct cell{
    int x,y;
    int distance;
    cell(int _x,int _y,int _distance):x(_x),y(_y),distance(_distance){}
};

int shortestPath(int* maze, int n, int m, int start_x, int start_y){
    bool* visited = new bool[n*m];
    for(int i=0; i< n*m; i++) visited[i] = false;

    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};

    queue<cell> q;
    q.push(cell(start_x,start_y,0));
    visited[start_x*m + start_y] = true;

    while(!q.empty()){
        cell curr = q.front();
        q.pop();

        if(curr.x == 0 || curr.x == n-1 || curr.y == 0 || curr.y == m-1){
            delete[] visited;
            return curr.distance+1;
        }

        for(int i=0; i<4; i++){
            int nextX = curr.x + dx[i];
            int nextY = curr.y + dy[i];

            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m
                && maze[nextX*m + nextY] == 0 && !visited[nextX*m + nextY]){
                    q.push(cell(nextX, nextY, curr.distance + 1));
                    visited[nextX*m + nextY] = true;
            }
        }
    }
    delete[] visited;

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    int* maze = new int[n*m];
    for(int i=0; i<n*m; i++){
        cin >> maze[i];
    }

    int res = shortestPath(maze, n, m, r-1, c-1);
    cout << res << endl;

    delete[] maze;
    return 0;

}