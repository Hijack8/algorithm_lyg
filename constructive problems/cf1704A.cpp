#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

void solve(){
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    int i, j;
    for(i = m - 1, j = n - 1; i >= 1; i --, j --){
        if(a[j] != b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    if(a[n - m] == b[0]){
        cout << "YES" << endl;
        return;
    }
    for(int i = 0; i < n - m; i ++){
        if(a[i] == b[0]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}