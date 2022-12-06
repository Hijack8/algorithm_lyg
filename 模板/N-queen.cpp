#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 15;
int n;
char g[N][N];
bool col[N], dg[2 * N], ldg[2 * N];

void dfs(int u){
	if(u == n){
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < n; j ++)
				cout << g[i][j];
			cout << endl;
		}
		cout << endl;
		return ;
	}
	for(int i = 0; i < n; i ++){
		if(col[i] || dg[u + i] || ldg[u - i + n]) continue;
		g[u][i] = 'Q';
		col[i] = dg[u + i] = ldg[u - i + n] = true;
		dfs(u + 1);
		col[i] = dg[u + i] = ldg[u - i + n] = false;
		g[u][i] = '.';
	}
}



int main(){
	cin >> n;
	for(int i = 0;i < n; i ++)
		for(int j = 0; j < n; j ++)
			g[i][j] = '.';
	dfs(0);

	return 0;
}