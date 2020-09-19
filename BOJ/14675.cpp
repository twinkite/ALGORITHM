#include <iostream>
#include <vector>
using namespace std;

int N, q;
vector<int> indegree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N;
    indegree=vector<int> (N+1);
    int a, b;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        indegree[a]++;
        indegree[b]++;
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(a==1){
            (indegree[b]==1)?cout<<"no"<<'\n':cout<<"yes"<<'\n';
        }
        else{
            cout<<"yes"<<'\n';
        }
    }
    return 0;
}