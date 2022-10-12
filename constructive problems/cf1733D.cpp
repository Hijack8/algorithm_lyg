#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

// 卡住了

int main(){
    int T;
    cin >> T;
    while(T --){
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<int> q;
        for(int i = 0; i < n; i ++){
            if(a[i] != b[i]) q.push_back(i);
        }

        if(q.size() & 1) {
            cout << -1 << endl;
            continue;
        }
        if(q.size() == 0) {
            cout << 0 << endl;
            continue;
        }
        int f[n + 10];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for(int i = 2; i <= q.size() / 2; i ++){
            if(q[i] - q[i - 1] == 1) f[i] = min(f[i], f[i - 2] + x);
            else if(q[i] - q[i - 1] == 2) f[i] = min(f[i], f[i - 2] + 2 * x);
            else f[i] = min(f[i], f[i - 1] + y);
        }
    }
    return 0;
}