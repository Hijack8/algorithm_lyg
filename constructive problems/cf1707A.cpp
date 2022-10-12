#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    int a[n + 10];
    bool st[n + 10];
    memset(st, 0, sizeof st);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int Q = 0;
    for(int i = n - 1; i >= 0; i --){
        if(a[i] > Q && Q < q) {
            Q ++;
            st[i] = true;
        } 
        else if(a[i] <= Q){
            st[i] = true;
        }
    }
    string rst = "";
    for(int i = 0; i < n; i ++){
        if(st[i]) rst += '1';
        else rst += '0';
    }
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