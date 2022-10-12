#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;



int main(){
    int T, n;
    cin >> T;
    while(T --){
        cin >> n;
        int x[3], y[3];
        for(int i = 0; i < 3; i ++) cin >> x[i] >> y[i];
        sort(x, x + 3), sort(y, y + 3);
        int a = x[1], b = y[1];
        int xd, yd;
        cin >> xd >> yd;
        if(a == 1 && b == n || a == n && b == 1 || a == 1 && b == 1 || a == n && b == n){
            if(xd == a || yd == b) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }

        int dx = abs(xd - a), dy = abs(yd - b);
        if((dx & 1) && (dy & 1)) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}