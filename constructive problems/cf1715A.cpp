#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }
    cout << n + m - 2 + min(m, n) << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}