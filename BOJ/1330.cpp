#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    int a, b;
    while(getline(cin, s)){
        a = s[0]-'0';
        b = s[2]-'0';
        cout<<a+b<<"\n";
    }
}