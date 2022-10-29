#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, m;
void solve(){
	cin >> n >> m;
	if(m < n || (n % 2 == 0 && m % 2 != 0)) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	if(n & 1){
		for(int i = 1; i <= n - 1; i ++) cout << 1 << ' ';
		cout << m - n + 1 << endl;
		return;
	}
	for(int i = 1; i <= n - 2; i ++) cout << 1 << ' ';
	cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << endl;
}

int main(){
	cin >> T;
	while(T --){
		solve();
	}
	return 0;
}