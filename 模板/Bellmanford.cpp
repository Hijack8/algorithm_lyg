// bellman-ford 算法用于求 含负权边 有边数限制 的最短路问题
// 效率较低
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 510, INF = 0x3f3f3f3f;

struct Edge{
	int a, b, w;
}edges[N];
int n, m, k;
int dist[N];
int last[N];

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
		auto &t = edges[i];
		cin >> t.a >> t.b >> t.w;
	}
	bellman_ford();
	if(dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
	else cout << dist[n];

	return 0;
}