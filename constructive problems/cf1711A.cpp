#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n & 1){
        cout << 1 << ' ';
    }
    for(int i = 1 + (n & 1); i <= n; i += 2){
        cout << i + 1 << ' ' << i << ' '; 
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}