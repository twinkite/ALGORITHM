#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string s1, s2; 
    cin>>N;
    int arr1[26];
    int arr2[26];

    for(int i=0;i<N;i++){
        bool ck=true;
        fill(arr1, arr1+26, 0);
        fill(arr2, arr2+26, 0);
        cin>>s1>>s2;
        if(s1.size()!=s2.size()) ck=false;
        for(int j=0;j<s1.size();j++){
            arr1[s1[j]-'a']++;
            arr2[s2[j]-'a']++;
        }

        for(int j=0;j<26;j++){
            if(arr1[j]!=arr2[j]){
                ck=false;
                break;
            }
        }
        if(ck) cout<<"Possible"<<'\n';
        else cout<<"Impossible"<<'\n';
    }    
    return 0;
}