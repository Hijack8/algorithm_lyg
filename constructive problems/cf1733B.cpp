#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    if(max(x, y) == 0 || min(x, y) != 0 || (n - 1) % max(x, y) != 0) {
        cout << -1 << endl;
        return ;
    }
    int a = max(x, y);
    for(int i = 2; i <= n; i += a){
        for(int k = 0; k < a; k ++) cout << i << ' ';
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