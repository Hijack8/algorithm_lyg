#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 100010;
int T, n, l, r;
LL ans[N];

void solve(){
	cin >> n >> l >> r;
	int ok = 1;
	for(int i = 1 ; i <= n ; ++i){
		ans[i] = ((l - 1) / i + 1) * i;
		ok = ok && ans[i] <= r;
	}
	if(ok) {
		cout << "YES" << endl;
		for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
		cout << endl;
	}
	else cout << "NO" << endl;
}

int main(){
	cin >> T;
	while(T --){
		solve();
	}
	return 0;
}