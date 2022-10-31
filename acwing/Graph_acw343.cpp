#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 26;
bool g[N][N], d[N][N];
bool st[N];
int n, m;

void floyd(){
	memcpy(d, g, sizeof g);
	for(int k = 0; k < n; k ++){
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				d[i][j] |= d[i][k] && d[k][j];
			}
		}
	}
}

int check(){
	for(int i = 0; i < n; i ++)
		if(d[i][i])
			return 2;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < i; j ++){
			if(!d[i][j] && !d[j][i])
				return 0;
		}
	}
	return 1;
}

char get_min(){
	for(int i = 0; i < n; i ++){
		if(!st[i]){
			bool flg = true;
			for(int j = 0; j < n; j ++){
				if(!st[j] && d[j][i]) {
					flg = false;
					break;
				}
			}
			if(flg) {
				st[i] = true;
				return 'A' + i;
			}
		}
	}
}

int main(){
	while(cin >> n >> m, n || m){
		memset(g, 0, sizeof g);
		int type = 0, t;
		for(int i = 1; i <= m; i ++){
			string a;
			cin >> a;
			int x = a[0] - 'A', y = a[2] - 'A';
			if(!type){
				g[x][y] = true;
				floyd();
				type = check();
				if(type) t = i;
			}
		}
		if(!type) cout << "Sorted sequence cannot be determined." << endl;
		else if(type == 2) printf("Inconsistency found after %d relations.\n", t);
		else {
			memset(st, 0, sizeof st);
			printf("Sorted sequence determined after %d relations: ", t);
			for(int i = 0; i < n; i ++) cout << get_min();
			cout << '.' << endl;
		}
	}

	return 0;
}