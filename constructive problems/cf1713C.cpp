#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int N = 100010;
int ans[N], n;

void solve(int n){
	if(n < 0) return ;
	int s = sqrt(2 * n);
	s *= s;
	int l = s - n; 
	solve(l - 1);
	for(; l <= n; l ++, n --) {
		ans[l] = n; ans[n] = l;
	} 
}

int main(){
	int T;
	cin >> T;
	while(T --){
		cin >> n;
		solve(n - 1);
		for(int i = 0; i <= n - 1; i ++) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}