#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n;
    vector<int> v = vector<int>(n);
    vector<int> v1 = vector<int>(1000002);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cin>>k;

    int cnt = 0;
    for(int i=0; i<n;i++)
    {
        if (k-v[i] > 1000000 || k <= v[i]) continue;
        cnt += v1[k-v[i]];
        v1[v[i]]++;
    }

    cout<<cnt;
    return 0;
}