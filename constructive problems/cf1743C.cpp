#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
const int N = 200010;
int a[N];

void solve(){
	int n;
	cin >> n;
	string str = "0";
	string x;
	cin >> x;
	str += x;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int rst = 0;
	for(int i = 1; i <= n; i ++){
		if(str[i] == '1') {
			int minv = a[i - 1], j = i;
			int sum = a[i - 1];
			while(str[j] == '1') {
				sum += a[j];
				minv = min(minv, a[j]);
				j ++;
			}
			rst += sum - minv;
			i = j;
		}
	}
	cout << rst << endl;
}

int main(){
	int T;
	cin >> T;
	while(T --){
		solve();
	}

	return 0;
}