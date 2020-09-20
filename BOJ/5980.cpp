#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define x second
#define y first

pii dir[4]={{0,1},{1,0},{-1,0},{0,-1}};
vector<vector<pii>> teleport(28);
vector<string> maze;
queue<pair<pii, int>> q;
bool visited[303][303];
int N, M;
pii fin;
pii start; 

void bfs(){
    visited[start.y][start.x]=1;
    q.push({start, 0});
    while(!q.empty()){
        pii here=q.front().y;
        int c=q.front().x;
        if(here==fin) {cout<<c; break;}
        q.pop();
        for(auto a: dir){
            pii next={here.y+a.y,here.x+a.x};
            if(next.y>=N||next.y<0||next.x>=M||next.x<0||maze[next.y][next.x]=='#'||visited[next.y][next.x]) continue;
            if(maze[next.y][next.x]>='A'&&maze[next.y][next.x]<='Z'){   //만약 텔포라면
                if(teleport[maze[next.y][next.x]-'A'][0]==next)
                    q.push({teleport[maze[next.y][next.x]-'A'][1],c+1});
                else q.push({teleport[maze[next.y][next.x]-'A'][0],c+1});
            }else{
                visited[next.y][next.x]=1;
                q.push({next,c+1});
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    string temp;
    maze=vector<string> (N+1);
    for(int i=0;i<N;i++){
        cin>>temp;
        maze[i]=temp;
        for(int j=0;j<M;j++){
            if(maze[i][j]>='A'&&maze[i][j]<='Z'){
                teleport[maze[i][j]-'A'].push_back({i,j});    // teleport 저장
            }
            else if(maze[i][j]=='='){
                fin={i,j};
            }
            else if(maze[i][j]=='@'){
                start={i,j};
            }
        }
    }
    bfs();
}
