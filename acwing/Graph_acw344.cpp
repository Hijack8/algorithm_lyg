// 无向图的最小环问题
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;
int d[N][N], g[N][N];
int f[N][N];
int path[N], cnt;
int n, m;

void get(int x, int y){
	if(f[x][y] == 0) return;
	int t = f[x][y];
	get(x, t);
	path[cnt ++] = t;
	get(t, y);
}

int main(){
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	while(m --){
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	memcpy(d, g, sizeof d);
	int minv = 0x3f3f3f3f;
	int mink = -1;
	for(int k = 1; k <= n; k ++){
		// 此时已经求出来 1 ~ k - 1 的所有点最短路径
		for(int i = 1; i <= k - 1; i ++){
			for(int j = i + 1; j <= k - 1; j ++){
				if(g[i][k] + g[j][k] + d[i][j] < minv){
					minv = d[i][k] + d[j][k] + d[i][j];
					cnt = 0;
					path[cnt ++] = k;
					path[cnt ++] = i;
					get(i, j);
					path[cnt ++] = j;
				}
			}
		}

		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				if(d[i][k] + d[k][k] < d[i][j]){
					d[i][j] = d[i][k] + d[k][j];
					f[i][j] = k;
				}
			}
		}
	}
	if(minv == 0x3f3f3f3f) cout << "No solution." << endl;
	else {
		for(int i = 0; i < cnt; i ++) cout << path[i] << ' ';
		cout << endl;
	}

	return 0;
}