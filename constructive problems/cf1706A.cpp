#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

void solve(){
    int n, m;
    string s = "";
    cin >> n >> m;
    for(int i = 0; i < m ; i ++) s += 'B';
    for(int i = 0; i < n; i ++){
        int a;
        cin >> a;
        int l = min(a - 1, m - a), r = max(a - 1, m - a);
        if(s[l] == 'A') s[r] = 'A';
        else s[l] = 'A';
    }
    cout << s << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}