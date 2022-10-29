#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, n;
const int N = 25;
int a[N];
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int solve(){
	cin >> n;
	int g = 0;
	for(int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		g = gcd(g, x);
	}
	if(g == 1) return 0;
	if(gcd(g, n) == 1) return 1;
	if(gcd(g, n- 1) == 1) return 2;
	return 3;
}

int main(){
	cin >> T;
	while(T --){
		cout << solve() << endl;
	}

	return 0;
}