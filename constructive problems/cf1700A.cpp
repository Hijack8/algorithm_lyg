#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

void solve(){
    int n, m;
    cin >> n >> m;
    LL rst  = 0;
    rst += (LL) m * (m - 1) / 2;
    rst += (LL)n * (LL)(n + 1) * m / 2;
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