// 朴素版Dijkstra算法
// 利用了贪心的思想
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


const int N = 510, M = 200010;
int h[N], e[M], ne[M], w[M], idx;
int n, m;
int dist[N];
bool st[N];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int dijkstra(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0; i < n - 1; i ++){
		int t = -1;
		for(int j = 1; j <= n; j ++){
			if(!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}
		st[t] = true;
		for(int j = h[t]; j != -1; j = ne[j]){
			int x = e[j];
			dist[x] = min(dist[x], dist[t] + w[j]);
		}
	}
	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	cout << dijkstra();


	return 0;
}