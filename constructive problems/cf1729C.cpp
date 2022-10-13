#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

typedef pair<char, int > PCI;

PCI pci[200010];
bool cmp(PCI a, PCI b){
    if(a.first != b.first) return a.first < b.first;
}

void solve(){
    string a;
    cin >> a;
    int n = a.size();
    for(int i = 0; i < n; i ++) {
        pci[i] = {a[i], i};
    }
    char start = a[0], end = a[a.size() - 1];
    sort(a.begin(), a.end());
    int p, q;
    for(p = 0; p < a.size(); p ++){
        if(p == start) break;
    }
    for(q = a.size() - 1; q >= 0; q --){
        if(q == end) break;
    }
    cout << 
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}