#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    if(k & 1){
        cout << "YES" << endl;
        for(int i = 1; i <= n; i += 2){
            cout << i << ' ' << i + 1 << ' ' << endl;
        }
        return ;
    }
    bool st[n + 10];
    memset(st, 0, sizeof st);
    for(int i = 2; i <= n; i += 2){
        if(i % 4 && (i + k) % 4){
            cout << "NO" << endl;
            return;
        }
        if(i % 4 == 0) st[i] = true; 
    }
    cout << "YES" << endl;
    for(int i = 2; i <= n; i += 2){
        if(st[i]){
            cout << i - 1 << ' ' << i << ' ' << endl;
        }
        else cout << i << ' ' << i - 1 << ' ' << endl;
    }

}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}