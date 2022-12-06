#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;
using namespace std;

int n, T;
string s;

void solve(){
	cin >> n >> s;
	LL rst = n;
	for(int i = 1; i < n; i ++){
		if(s[i] != s[i - 1]) 
			rst += i;
	}
	cout << rst << endl;
}

int main(){
	cin >> T;
	while(T --){
		solve();
	}

	return 0;
}