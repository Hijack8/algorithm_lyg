#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int f[k + 10];
    for(int i = 0; i < k; i ++) cin >> f[i];
    int remainn = n, remainm = m;
    bool flg1, flg2, flg3, flg4;
    flg1 = flg2 = flg3 = flg4 = 0;
    for(int i = 0; i < k; i ++){
        if(f[i] / n >= 3) flg3 = 1;
        if(f[i] / m >= 3) flg4 = 1;
        if(remainm && f[i] / n >= 2)
            remainm -= f[i] / n;
        if(remainn && f[i] / m >= 2)
            remainn -= f[i] / m;
        if(remainm <= 0) flg1 = 1;
        if(remainn <= 0) flg2 = 1;
    }
    if(flg1 || flg2) {
        if(!flg1 && !flg2) {
            cout << "No" << endl;
            return ;
        }
        if((n & 1) == 0 && flg2) {
            cout << "Yes" << endl;
            return;
        } 
        if((m & 1) == 0 && flg1){
            cout << "Yes" << endl;
            return;
        }
        if(flg1 && flg3){
            cout << "Yes" << endl;
            return;
        }
        if(flg2 && flg4){
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
    }
    else{
        cout << "No" << endl;
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