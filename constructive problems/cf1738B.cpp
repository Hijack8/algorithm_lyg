#include <iostream>
using namespace std;
typedef long long LL;

int main(){
    int T;
    cin >> T;
    while(T --){
        int n, k;
        cin >> n >> k;
        LL s[n + 10];
        LL a[n + 10];
        s[0] = 0;
        for(int i = 1; i <= k; i ++){
            cin >> s[i];
        }
        for(int i = 1; i <= k; i ++){
            a[i] = s[i] - s[i - 1];
        }
        if(k == 1) {
            cout << "Yes" << endl;
            continue;
        }
        if(a[1] > a[2] * (n - k + 1)) {
            cout << "No" << endl;
            continue;
        }
        bool flg = true;
        for(int i = 3; i <= k; i ++){
            if(a[i] < a[i - 1]) {
                flg = false;
                break;
            }
        }
        if(flg) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
    return 0;
}