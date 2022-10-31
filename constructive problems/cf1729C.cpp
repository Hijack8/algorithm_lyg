#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;
#define forn(i, n) for(int i = 0; i < int(n); i ++)

typedef pair<char, int > PCI;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    map<char, vector<int>> let_to_ind;
    
    forn(i, n){
        let_to_ind[s[i]].push_back(i);
    }
    int direction = (s[0] < s[n - 1]) ? 1 : -1;
    vector<int> ans;
    for(char c = s[0]; c != s[n - 1] + direction; c += direction){
        for(auto now : let_to_ind[c]){
            ans.push_back(now);
        }
    }
    int cost = 0;
    for(int i = 1; i < ans.size(); i ++)
        cost += abs(s[ans[i]] - s[ans[i - 1]]);
    
    cout << cost << " " << ans.size() << '\n';
    for(auto now : ans)
        cout << now + 1 << ' ';
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T --){
        solve();
    }

    return 0;
}