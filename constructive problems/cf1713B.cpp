#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int f[n + 10];
    for(int i = 0; i < n; i ++) cin >> f[i];
    
    int j = 1, i = 1;
    while(j < n && f[j] >= f[j - 1]) j ++;
    i = j;
    for(; i < n; i ++){
        if(f[i] > f[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}