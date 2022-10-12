#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T --){
        int n;
        cin >> n;
        cout << (n - 3) / 3 - 1 << endl;
    }
    return 0;
}