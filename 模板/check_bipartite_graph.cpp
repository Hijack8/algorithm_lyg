// 染色法判断二分图

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c){
	color[u] = c;
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!color[j]){
			if(!dfs(j, 3 - c)) return false;
		}
		else if(color[j] == c) return false;
	}
	return true;
}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	bool flg = true;
	for(int i = 1; i <= n; i ++){
		if(!color[i]){
			if(!dfs(i, 1)){
				flg = false;
				break;
			}
		}
	}
	if(flg) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}