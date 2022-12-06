#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int n, T;
int a[N];
int rst[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		if(i == n || a[i] != a[i + 1]) {
			cout << -1 << endl;
			return;
		}
		int j = i;
		for(j = i; j <= n && a[j] == a[i]; j ++){
			rst[j] = j + 1;
		}
		rst[j - 1] = i;
		i = j - 1;
	}
	for(int i = 1; i <= n; i ++) cout << rst[i] << ' ';
	cout << endl;
}

int main(){
	cin >> T;
	while(T --){
		solve();
	}

	return 0;
}