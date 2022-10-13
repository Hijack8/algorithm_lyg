#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

void solve(){
    int n;
    cin >> n;
    int f[n + 10];
    LL rst = 0;
    for(int i = 0; i < n; i ++) {
        cin >> f[i];
        if(i != n - 1) rst += f[i];
    }
    int p = 0;
    while(f[p] == 0) p ++;
    for(int i = p; i < n - 1; i ++)     
        if(f[i] == 0) rst ++;
    cout << rst << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}