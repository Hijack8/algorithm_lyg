#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int case1 = 0, case2 = 0;
    for(int i = 0; i < n - 2; i ++){
        case1 ^= i, case2 ^= i + 1;
    }
    int addlast = ((long long) 1 << 31) - 1;
    if(case1){
        for(int i = 0; i < n - 2; i ++) cout << i << ' ';
        cout << addlast << ' ' << (case1 ^ addlast) << endl;
    }
    else {
        for(int i = 1; i <= n - 2; i ++) cout << i << ' ';
        cout << addlast << ' ' << (case2 ^ addlast) << endl;
    }
}

int main(){
    int T, n;
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}