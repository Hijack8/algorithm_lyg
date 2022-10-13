#include<iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

void solve(){
    LL n;
    cin >> n;
    string t = to_string(n);
    string s = "1";
    for(int i = 1; i < t.size(); i ++){
        s += '0';
    }
    int k = stoi(s);
    cout << n - k << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}