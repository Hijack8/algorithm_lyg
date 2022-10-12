#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int n;
int f[110];

void display(){
    for(int i = 1; i <= n; i ++) cout << f[i] << ' ';
    cout << endl;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++) f[i] = i;
    cout << n << endl;
    if(n & 1){
        display();
        int p = n / 2, q = n / 2 + 2;
        swap(f[p], f[q]);
        display();
        for(int i = p; i >= 1; i --){
            swap(f[i], f[p + 1]);
            display();
        }
        for(int i = q + 1; i <= n; i ++){
            swap(f[i], f[q]);
            display();
        }
        return;
    }
    display();
    int p = n / 2, q = n / 2 + 1;
    swap(f[p], f[q]);
    display();
    for(int i = p - 1; i >= 1; i --){
        swap(f[i], f[p + 1]);
        display();
    }
    for(int i = q + 1; i <= n; i ++){
        swap(f[i], f[q]);
        display();
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