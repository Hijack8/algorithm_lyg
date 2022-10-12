#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

void solve(){
    LL n, k, b, s;
    cin >> n >> k >> b >> s;
    LL kb = k * b;
    LL re = s - kb;
    LL maxre = (k - 1) * n;
    if(re < 0 || re > maxre) {
        cout << - 1 << endl;
        return;
    }
    for(int i = 0; i < n - 1; i ++){
        if(re > 0){
            if(re >= k - 1) cout << k - 1 << ' ';
            else cout << re << ' ';
            re -= k - 1;
        }
        else cout << 0 << ' ';
    }
    
    if(re <= 0) re = 0;
    cout << kb + re << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}