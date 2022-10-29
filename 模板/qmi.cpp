#include <iostream>

using namespace std;
// 快速幂模板
int qmi(int a, int k){
    int rst = 1;
    while(k){
        if(k & 1) rst *= a;
        a *= a;
        k >>= 1;
    }
    return rst;
}

int main(){
    cout << qmi(32,2);
    cout << "hello world" << endl;
    return 0;
}