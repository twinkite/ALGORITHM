#include <iostream>
#define INF 1111111
using namespace std;

int arr[1000003];

void dp(int n){
    arr[1]=0;
    for(int i=2;i<=n;i++){
        int temp1=INF, temp2=INF, temp3=INF;
        if(i%3==0) temp1=arr[i/3]+1;
        if(i%2==0) temp2=arr[i/2]+1;
        temp3=arr[i-1]+1;
        arr[i]=min(temp1, temp2);
        arr[i]=min(arr[i],temp3);
    }    
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    dp(N);

    cout<<arr[N];
    return 0;
}