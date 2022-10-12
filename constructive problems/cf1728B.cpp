#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n & 1){
        cout << 1 << ' ';
        for(int i = n - 2; i >= 2; i --) cout << i << ' ';
        cout << n - 1 << ' ' << n << endl;
    }
    else{
        for(int i = n - 2; i >= 1; i --) cout << i << ' ';
        cout << n - 1 << ' ' << n << endl;
    }
}

using namespace std;

int main(){
    int T;
    cin >> T;
    while( T --){
        solve();
    }
    return 0;
}