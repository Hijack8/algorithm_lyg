#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N];
int n, T;

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	if(n & 1) { 
		cout << "NO" << endl;
		return;
	}

	sort(a + 1, a + 1 + n);
	int m = n / 2;
	if(a[1] == a[1 + m]) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for(int i = 1; i <= m; i ++){
		cout << a[i] << ' ' << a[i + m] << ' ';
	}
	cout << endl;
}

int main(){
	cin >> T;
	while(T --){
		solve();
	}

	return 0;
}