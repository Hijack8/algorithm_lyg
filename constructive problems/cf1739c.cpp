#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 62, mod = 998244353;
int C[N][N];
int A[N], B[N];

void init(){
    C[0][0] = 1;
    for(int i = 1; i < N; i ++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j ++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
    
    for(int i = 2; i < N; i ++){
        if(i % 2 == 0){
            A[i] = (C[i - 1][i / 2] + B[i - 2]) % mod;
            B[i] = (C[i - 2][i / 2] + A[i - 2]) % mod;
        }
    }
}

int main(){
    int T, n;
    cin >> T;
    init();
    while(T --){
        cin >> n;
        cout << A[n] << ' ' << B[n] << ' ' << 1 << endl;
    }
    return 0;
}