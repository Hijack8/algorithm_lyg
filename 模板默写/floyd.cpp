#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210;
int d[N][N];
int n, m, k;

void floyd(){
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main(){
	memset(d, 0x3f, sizeof d);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) d[i][i] = 0;
	while(m --){
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	floyd();
	while(k --){
		int a, b;
		cin >> a >> b;
		if(d[a][b] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
		else cout << d[a][b] << endl;
	}

	return 0;
}