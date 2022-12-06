#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;
int n, m, k;
int dist[N], last[N];
struct Edge{
	int a, b, w;
}edges[M];

void bellman_ford(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0; i < k; i ++){
		memcpy(last, dist, sizeof dist);
		for(int j = 0; j < m; j ++){
			auto e = edges[j];
			dist[e.b] = min(dist[e.b], last[e.a] + e.w);
		}
	}
}

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < m; i ++){
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	}

	bellman_ford();
	if(dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
	else cout << dist[n] << endl;

	return 0;
}